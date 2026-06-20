"""Empirical study of when mwccarm colors a temporary into ip/r12.

ip (r12) is the ARM intra-procedure scratch register: caller-saved, so the compiler
favors it for a SHORT-LIVED temporary that does not need to survive a call. The
matching wall (triage's "regperm") is that an isolated minimal function colors a temp
into a low reg (r1) where the ROM used ip -- byte-identical except that field.

This tool mines the MATCHED corpus (functions we already reproduced byte-for-byte) to
characterize ip usage empirically, so we can predict it and bias templates toward it.

Pass 1 (descriptive): over every matched arm function, disassemble the ROM bytes and
record, for each instruction that mentions ip:
  - the mnemonic and which operand slot ip occupies (dest vs source)
  - whether ip is live across any bl/blx in the function (it shouldn't be -- calls
    clobber ip; if it is, that's a different ip, e.g. a veneer)
  - function size and call count (proxies for register pressure)

Usage:
    python tools/coloring.py                 # corpus-wide summary
    python tools/coloring.py --module ov002
    python tools/coloring.py --examples 20   # show sample ip-using functions
"""
import argparse
import collections
import pathlib
import re
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import swarm as S
import modules as MOD
import sweep

REG_RE = re.compile(r"\b(r\d+|sb|sl|fp|ip|sp|lr|pc)\b")
ALIAS = {"sb": "r9", "sl": "r10", "fp": "r11", "ip": "r12", "sp": "r13", "lr": "r14", "pc": "r15"}


def uses_ip(op):
    return any(ALIAS.get(t, t) == "r12" for t in REG_RE.findall(op))


def code_insns(ins):
    """Trim the trailing literal pool. The symbol size includes pool words, which
    decode as junk (andeq/andseq...). Real code ends at the LAST return instruction
    (bx lr / pop ..pc / ldm ..pc / mov pc,lr); everything after is pool."""
    last = -1
    for i, x in enumerate(ins):
        op = x.op_str.replace(" ", "")
        if x.mnemonic == "bx" and op in ("lr", "ip", "r12", "r14"):
            last = i
        elif x.mnemonic in ("pop", "ldm", "ldmia", "ldmfd") and "pc" in op:
            last = i
        elif x.mnemonic == "mov" and op == "pc,lr":
            last = i
    return ins[:last + 1] if last >= 0 else ins


def analyze_func(ins):
    """Return per-function ip stats, or None if ip never appears."""
    call_idxs = [i for i, x in enumerate(ins) if x.mnemonic in ("bl", "blx")]
    ip_ctx = []          # (mnemonic, dest_or_src, idx)
    for i, x in enumerate(ins):
        if not uses_ip(x.op_str):
            continue
        ops = [o.strip() for o in x.op_str.split(",")]
        dest = bool(ops) and ALIAS.get(ops[0], ops[0]) == "r12"
        ip_ctx.append((x.mnemonic, "dest" if dest else "src", i))
    if not ip_ctx:
        return None
    # is any ip definition live across a call? (def at i, used at j>some call k, i<k<j)
    crosses_call = False
    defs = [i for m, ds, i in ip_ctx if ds == "dest"]
    uses = [i for m, ds, i in ip_ctx if ds == "src"]
    for d in defs:
        for u in uses:
            if u > d and any(d < k < u for k in call_idxs):
                crosses_call = True
    return {
        "ip_insns": ip_ctx,
        "n_calls": len(call_idxs),
        "n_ins": len(ins),
        "crosses_call": crosses_call,
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default=None)
    ap.add_argument("--examples", type=int, default=0)
    args = ap.parse_args()

    done = sweep.load_done()
    n_matched = 0
    n_with_ip = 0
    by_mnemonic = collections.Counter()       # ip instruction mnemonic+slot
    by_role = collections.Counter()           # dest vs src
    crosses = 0
    size_with = []
    size_without = []
    calls_with = []
    calls_without = []
    examples = []

    for mod in MOD.modules():
        label = "arm9" if mod["name"] == "main" else mod["name"]
        if args.module and mod["name"] != args.module and label != args.module:
            continue
        data = mod["bin"].read_bytes()
        for name, addr, size in sweep.funcs(mod):
            if (label, addr) not in done:        # MATCHED only
                continue
            tgt = data[addr - mod["base"]:addr - mod["base"] + size]
            ins = list(S.md.disasm(tgt, 0))
            if not ins or S.is_thunk(ins):
                continue
            ins = code_insns(ins)
            n_matched += 1
            st = analyze_func(ins)
            if st is None:
                size_without.append(size)
                calls_without.append(sum(1 for x in ins if x.mnemonic in ("bl", "blx")))
                continue
            n_with_ip += 1
            size_with.append(size)
            calls_with.append(st["n_calls"])
            if st["crosses_call"]:
                crosses += 1
            for m, ds, i in st["ip_insns"]:
                by_mnemonic[f"{m} ({ds})"] += 1
                by_role[ds] += 1
            if len(examples) < args.examples:
                examples.append((label, addr, size, st))

    def avg(xs):
        return sum(xs) / len(xs) if xs else 0.0

    print(f"=== ip/r12 coloring over {n_matched} matched arm functions ===")
    if not n_matched:
        print("  (no matched functions found -- is progress/matched.jsonl populated?)")
        return
    print(f"  functions using ip : {n_with_ip:5}  ({100*n_with_ip/n_matched:.1f}%)")
    print(f"  ip def live across a call : {crosses}  (expected ~0; calls clobber ip)")
    print(f"  avg size  with ip / without : 0x{int(avg(size_with)):x} / 0x{int(avg(size_without)):x}")
    print(f"  avg calls with ip / without : {avg(calls_with):.2f} / {avg(calls_without):.2f}")
    print("\n  ip instruction contexts (mnemonic, slot):")
    for k, n in by_mnemonic.most_common(25):
        print(f"    {n:5}  {k}")
    print(f"\n  ip role: dest={by_role['dest']}  src={by_role['src']}")
    if examples:
        print("\n  examples:")
        for lbl, a, s, st in examples:
            ctx = ",".join(f"{m}/{ds}" for m, ds, _ in st["ip_insns"][:4])
            print(f"    {lbl} 0x{a:08x} (0x{s:x}, {st['n_calls']} calls): {ctx}")


if __name__ == "__main__":
    main()
