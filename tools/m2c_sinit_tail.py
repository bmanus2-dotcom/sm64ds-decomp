"""Convert m2c __sinit tail field stores to mwccarm struct P2/P6 + bqa spill C."""
import re
import pathlib

REPO = pathlib.Path(__file__).resolve().parent.parent
ASSIGN_RE = re.compile(
    r"^(data_\S+)\.unk([0-9a-fA-F]+)\s*=\s*\(s32\)\s*(data_\S+)\.unk([0-9a-fA-F]+);"
)
CALL_RE = re.compile(r"^func_ov002_020e6ad4\(&(\S+)\);")


def read_draft(draft_path):
    raw = draft_path.read_bytes()
    if raw[:2] == b"\xff\xfe":
        return raw.decode("utf-16-le")
    return raw.decode("utf-8", errors="replace")


def parse_tail(draft_path):
    lines = read_draft(draft_path).splitlines()
    tail = []
    for ln in lines:
        s = ln.strip()
        if ASSIGN_RE.match(s) or CALL_RE.match(s):
            tail.append(s)
        elif tail and s == "}":
            break
    return tail


def emit_bqa(dest):
    return (
        f"    {dest}.tail.a = tb ? ta : ta;\n"
        f"    {dest}.tail.b = tb;\n"
    )


def emit_spill_once(spilled):
    if spilled[0]:
        return ""
    spilled[0] = True
    return (
        "    tmp = data_02086b58;\n"
        "    ta = tmp.a;\n"
        "    tb = tmp.b;\n"
    )


def emit_tail(tail_lines):
    out = []
    spilled = [False]
    i = 0
    while i < len(tail_lines):
        m = CALL_RE.match(tail_lines[i])
        if m:
            out.append(f"    func_ov002_020e6ad4(&{m.group(1)});\n")
            i += 1
            continue

        if i + 5 < len(tail_lines):
            batch = [ASSIGN_RE.match(tail_lines[i + k]) for k in range(6)]
            if all(batch):
                dests = [b.group(1) for b in batch]
                offs = [int(b.group(2), 16) for b in batch]
                if len(set(dests)) == 1 and offs == [0, 4, 8, 0xC, 0x10, 0x14]:
                    dest = dests[0]
                    lo, hi = batch[0].group(3), batch[2].group(3)
                    out.append(f"    {dest}.lo = {lo};\n")
                    out.append(f"    {dest}.hi = {hi};\n")
                    if batch[4].group(3) == "data_02086b58":
                        out.append(emit_spill_once(spilled))
                        out.append(emit_bqa(dest))
                    i += 6
                    continue

        if i + 3 < len(tail_lines):
            batch = [ASSIGN_RE.match(tail_lines[i + k]) for k in range(4)]
            if all(batch):
                dests = [b.group(1) for b in batch]
                offs = [int(b.group(2), 16) for b in batch]
                if len(set(dests)) == 1 and offs == [0, 4, 8, 0xC]:
                    dest = dests[0]
                    out.append(f"    {dest}.lo = {batch[0].group(3)};\n")
                    out.append(f"    {dest}.hi = {batch[2].group(3)};\n")
                    i += 4
                    continue

        m0 = ASSIGN_RE.match(tail_lines[i])
        if not m0:
            i += 1
            continue
        dest, doff, src, soff = m0.group(1), int(m0.group(2), 16), m0.group(3), int(m0.group(4), 16)

        if doff == 0 and i + 1 < len(tail_lines):
            m1 = ASSIGN_RE.match(tail_lines[i + 1])
            if m1 and m1.group(1) == dest and int(m1.group(2), 16) == 4:
                if src == m1.group(3) and soff == 0 and int(m1.group(4), 16) == 4:
                    out.append(f"    {dest}.lo = {src};\n")
                    i += 2
                    continue
                out.append(f"    {dest}.lo = {src};\n")
                out.append(f"    {dest}.hi = {m1.group(3)};\n")
                i += 2
                continue

        if doff == 0x10 and src == "data_02086b58":
            out.append(emit_spill_once(spilled))
            out.append(emit_bqa(dest))
            i += 2 if i + 1 < len(tail_lines) else 1
            if i < len(tail_lines):
                m1 = ASSIGN_RE.match(tail_lines[i])
                if m1 and m1.group(1) == dest and int(m1.group(2), 16) == 0x14:
                    i += 1
            continue

        out.append(
            f"    ((int *)&{dest})[{doff // 4}] = ((int *)&{src})[{soff // 4}];\n"
        )
        i += 1

    return "".join(out)


def collect_syms(tail_lines):
    syms = set()
    for ln in tail_lines:
        m = ASSIGN_RE.match(ln)
        if m:
            syms.add(m.group(1))
            syms.add(m.group(3))
        m = CALL_RE.match(ln)
        if m:
            syms.add(m.group(1))
    syms.add("data_02086b58")
    return syms


def main():
    draft = REPO / "_m2c_draft.txt"
    tail = parse_tail(draft)
    body = emit_tail(tail)
    out = REPO / "_sinit_tail.c"
    out.write_text(body)
    print(f"tail lines in: {len(tail)}  out lines: {body.count(chr(10))}  -> {out}")


if __name__ == "__main__":
    main()