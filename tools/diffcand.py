"""Diff-oracle: show WHERE a candidate's compiled code diverges from the ROM.

oracle_ok returns only True/False. That makes the agent fly blind on the last mile,
which (per the 5-config experiment) is almost always codegen SHAPE, not logic. This
shows a reloc-aware, aligned asm diff between the candidate and the ROM, plus a category
breakdown, so the agent can fix the FIRST specific divergence instead of guessing.

It also doubles as a pattern-miner: run it over many near-misses and tally the categories
to see which shape mistakes recur (those get promoted into the fan-out prompt).

Usage:
    python tools/diffcand.py --c cand.txt --func NAME --hex TARGETHEX
    python tools/diffcand.py --c cand.txt --func NAME --hex TARGETHEX --brief   # categories only

Categories:
    regalloc   same instruction, only registers differ  (permuter can fix; small)
    reorder    same instructions present, different order (often schedule/store order)
    different  a different operation/operands (usually a real logic or idiom mismatch)
    missing    ROM has an instruction the candidate lacks (candidate did too little)
    extra      candidate has an instruction the ROM lacks (candidate did too much)
"""
import argparse
import difflib
import pathlib
import re
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import match as M
import swarm as S

REG = re.compile(r"\b(r\d+|sb|sl|fp|ip|sp|lr|pc)\b")


def disasm(code, relocs):
    """[(mnemonic, 'mnemonic  ops')] with the literal pool trimmed and reloc slots
    canonicalized so call/data refs don't show as spurious diffs."""
    out = []
    for ins in S.code_insns(list(S.md.disasm(code, 0))):
        if ins.address in relocs:
            out.append(("reloc", "reloc <wildcard>"))
        else:
            # wildcard the pc-relative pool OFFSET: "[pc, #0xNN]" depends on where the
            # literal pool sits (a size artifact), not on the logic, so it would flag
            # spurious "different" lines whenever the candidate's size differs.
            op = re.sub(r"\[pc, #-?0x[0-9a-fA-F]+\]", "[pc, #<pool>]", ins.op_str)
            out.append((ins.mnemonic, f"{ins.mnemonic}  {op}".rstrip()))
    return out


def _skel(row):
    return REG.sub("<r>", row)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--c", required=True)
    ap.add_argument("--func", required=True)
    ap.add_argument("--hex", required=True, help="target bytes hex (target_hex from the worklist)")
    ap.add_argument("--brief", action="store_true")
    args = ap.parse_args()

    src = pathlib.Path(args.c).read_text()
    cpp = src.startswith("//cpp")
    flags = S.CPP_FLAGS if cpp else M.DEFAULT_FLAGS
    # mwccarm compiles by file extension -- a .txt is ignored. Write a temp with the
    # right extension (.cpp for //cpp, else .c).
    import tempfile, os
    fd, tmp = tempfile.mkstemp(suffix=".cpp" if cpp else ".c")
    os.close(fd)
    cf = pathlib.Path(tmp)
    cf.write_text(src)
    try:
        obj = M.compile_c(cf, M.CANONICAL, flags)
    finally:
        cf.unlink(missing_ok=True)
    if obj is None:
        print("COMPILE FAILED -- fix the C first (the diff-oracle needs a compiling candidate).")
        return
    cand, crel = M.extract_func(obj, args.func)
    if cand is None:
        print(f"function {args.func} not found in the compiled object (name mismatch?).")
        return

    target = bytes.fromhex(args.hex)
    if cand == target:
        print("MATCH -- candidate is byte-identical to the ROM.")
        return

    crel = crel or set()
    c = disasm(cand, crel)
    t = disasm(target, crel)               # canonicalize the same reloc offsets in both
    sm = difflib.SequenceMatcher(a=[x[1] for x in c], b=[x[1] for x in t], autojunk=False)

    cats = {"regalloc": 0, "reorder": 0, "different": 0, "missing": 0, "extra": 0}
    first = None
    rows = []
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == "equal":
            for k in range(i1, i2):
                rows.append(("  ", c[k][1], t[j1 + (k - i1)][1]))
            continue
        cs = [c[k][1] for k in range(i1, i2)]
        ts = [t[k][1] for k in range(j1, j2)]
        # categorize this hunk
        if cs and ts and sorted(cs) == sorted(ts):
            cat = "reorder"; cats["reorder"] += max(len(cs), len(ts))
        elif cs and ts and all(_skel(a) == _skel(b) for a, b in zip(cs, ts)) and len(cs) == len(ts):
            cat = "regalloc"; cats["regalloc"] += len(cs)
        elif op == "insert":
            cat = "missing"; cats["missing"] += len(ts)
        elif op == "delete":
            cat = "extra"; cats["extra"] += len(cs)
        else:
            cat = "different"; cats["different"] += max(len(cs), len(ts))
        if first is None:
            first = (cat, cs, ts)
        n = max(len(cs), len(ts))
        for k in range(n):
            rows.append((f"!{cat[:1]}", cs[k] if k < len(cs) else "", ts[k] if k < len(ts) else ""))

    total = sum(cats.values())
    print(f"NO MATCH -- {total} diverging instructions. categories: " +
          ", ".join(f"{k}={v}" for k, v in cats.items() if v))
    if first:
        cat, cs, ts = first
        print(f"FIRST divergence ({cat}):")
        print(f"  candidate: {cs[0] if cs else '(missing)'}")
        print(f"  ROM:       {ts[0] if ts else '(absent)'}")
        hint = {
            "reorder": "same instructions, wrong ORDER -- reorder your statements/stores to match the ROM.",
            "regalloc": "only registers differ -- this is permuter-territory; the structure is right.",
            "missing": "the ROM does something your C doesn't -- you're missing an operation here.",
            "extra": "your C emits an instruction the ROM doesn't -- remove/merge a step.",
            "different": "different operation -- check the idiom (mul-vs-shift, op order) or the logic at this point.",
        }[cat]
        print(f"  hint: {hint}")
    if args.brief:
        return
    print("\n  flag | candidate                          | ROM")
    print("  " + "-" * 78)
    for flag, cc, tt in rows:
        print(f"  {flag:4} | {cc[:34]:34} | {tt[:34]}")


if __name__ == "__main__":
    main()
