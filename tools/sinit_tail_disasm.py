"""Emit __sinit tail C in disasm execution order (pool-skip safe)."""
import re

import m2c_draft as M2
import relocs as R

PCREL_RE = re.compile(r"^(\w+),\[pc,#(-?0x[0-9a-fA-F]+|-?\d+)\]$")
REG_POOL = frozenset(("r0", "r1", "r2", "r3", "lr", "ip"))


def squash(s):
    return re.sub(r"\s+", "", s)


def pool_val(addr, insn_addr, off_str, window, relocs, syms):
    off = int(off_str, 0)
    slot = insn_addr + 8 + off
    rel = relocs.get(slot)
    if rel:
        return ("sym", R.name_for_reloc(rel, syms))
    w = int.from_bytes(window[slot - addr : slot - addr + 4], "little")
    if w >= (1 << 31):
        w -= 1 << 32
    return ("const", w)


def pool_sym(addr, off, ins, window, relocs, syms):
    i = ins.get(off)
    if not i or i.mnemonic != "ldr":
        return None
    m = PCREL_RE.match(squash(i.op_str))
    if not m:
        return None
    pv = pool_val(addr, addr + off, m.group(2), window, relocs, syms)
    return pv[1] if pv[0] == "sym" else None


def track_pool_ldr(ins, off, addr, window, relocs, syms, reg_sym):
    i = ins[off]
    if i.mnemonic != "ldr":
        return
    m = PCREL_RE.match(squash(i.op_str))
    if not m or m.group(1) not in REG_POOL:
        return
    sym = pool_sym(addr, off, ins, window, relocs, syms)
    if sym:
        reg_sym[m.group(1)] = sym


SYM_RE = re.compile(r"\b(data_[A-Za-z0-9_]+)\b")


def collect_syms(text):
    out = set(SYM_RE.findall(text))
    out.discard("data_02086b58")
    return out


def try_p4_pool(ins, off, addr, window, relocs, syms):
    need = ["ldr", "ldr", "ldr", "ldr", "ldr", "str", "str", "ldr", "ldr", "str", "str"]
    if off + 40 not in ins:
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(11)]
    if seq != need:
        return None, 0
    slots = []
    for k in range(3):
        m = PCREL_RE.match(squash(ins[off + k * 4].op_str))
        if not m:
            return None, 0
        slots.append(pool_val(addr, addr + off + k * 4, m.group(2), window, relocs, syms))
    if any(s[0] != "sym" for s in slots):
        return None, 0
    dest, src_a, src_b = (s[1] for s in slots)
    return (
        f"    {dest}.lo = {src_a};\n    {dest}.hi = {src_b};\n",
        44,
    )


def try_p4_reg(ins, off, reg_sym):
    if off + 32 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    m1 = PCREL_RE.match(squash(ins[off + 4].op_str))
    if not (m0 and m1):
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(9)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str", "ldr", "ldr", "str"]:
        return None, 0
    dreg = squash(ins[off + 8].op_str).split(",")[1].strip("[]")
    if dreg not in reg_sym:
        return None, 0
    sa = m0.group(1)
    sb = m1.group(1)
    dest = reg_sym[dreg]
    return (
        f"    {dest}.lo = {sa};\n    {dest}.hi = {sb};\n",
        36,
    )


def try_p4_reg2(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 36 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    m1 = PCREL_RE.match(squash(ins[off + 4].op_str))
    if not (m0 and m1):
        return None, 0
    sa = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    sb = pool_val(addr, addr + off + 4, m1.group(2), window, relocs, syms)
    if sa[0] != "sym" or sb[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(10)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str", "ldr", "ldr", "str", "str"]:
        return None, 0
    s4 = squash(ins[off + 16].op_str)
    mdest = re.match(r"\w+,\[(\w+)\]$", s4)
    if not mdest:
        return None, 0
    dreg = mdest.group(1)
    if dreg not in reg_sym:
        return None, 0
    if not re.match(r"\w+,\[" + dreg + r",#4\]$", squash(ins[off + 20].op_str)):
        return None, 0
    if not re.match(r"\w+,\[" + dreg + r",#8\]$", squash(ins[off + 32].op_str)):
        return None, 0
    if not re.match(r"\w+,\[" + dreg + r",#0xc\]$", squash(ins[off + 36].op_str)):
        return None, 0
    dest = reg_sym[dreg]
    return (
        f"    {dest}.lo = {sa[1]};\n    {dest}.hi = {sb[1]};\n",
        40,
    )


def try_spill(ins, off, reg_sym):
    if off + 28 not in ins:
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(8)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str", "str", "str"]:
        return None, 0
    if squash(ins[off + 16].op_str) != "r1,[sp]" or squash(ins[off + 20].op_str) != "r0,[sp,#4]":
        return None, 0
    s6 = squash(ins[off + 24].op_str)
    m6 = re.match(r"r1,\[(\w+),#0x10\]", s6)
    if not m6 or m6.group(1) not in reg_sym:
        return None, 0
    if not re.match(r"r0,\[" + m6.group(1) + r",#0x14\]", squash(ins[off + 28].op_str)):
        return None, 0
    dest = reg_sym[m6.group(1)]
    return (
        "    tmp = data_02086b58;\n"
        "    ta = tmp.a;\n"
        "    tb = tmp.b;\n"
        f"    {dest}.tail.a = tb ? ta : ta;\n"
        f"    {dest}.tail.b = tb;\n",
        32,
    )


def try_bqa_p4_lo(ins, off, addr, window, relocs, syms):
    if off + 28 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    m1 = PCREL_RE.match(squash(ins[off + 4].op_str))
    if not (m0 and m1):
        return None, 0
    dest_pv = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    src_pv = pool_val(addr, addr + off + 4, m1.group(2), window, relocs, syms)
    if dest_pv[0] != "sym" or src_pv[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(8)]
    if seq != ["ldr", "ldr", "str", "str", "ldr", "ldr", "str", "str"]:
        return None, 0
    dreg = m0.group(1)
    if not re.match(r"r1,\[" + dreg + r",#0x10\]", squash(ins[off + 8].op_str)):
        return None, 0
    if not re.match(r"r0,\[" + dreg + r",#0x14\]", squash(ins[off + 12].op_str)):
        return None, 0
    if not re.match(r"\w+,\[" + dreg + r"\]$", squash(ins[off + 24].op_str)):
        return None, 0
    if not re.match(r"\w+,\[" + dreg + r",#4\]$", squash(ins[off + 28].op_str)):
        return None, 0
    dest, src = dest_pv[1], src_pv[1]
    return (
        f"    {dest}.lo = {src};\n"
        f"    {dest}.tail.a = tb ? ta : ta;\n"
        f"    {dest}.tail.b = tb;\n",
        32,
    )


def try_p4_lo_reg(ins, off, reg_sym):
    if off + 12 not in ins:
        return None, 0
    s0 = squash(ins[off].op_str)
    m0 = re.match(r"\w+,\[(\w+)\]$", s0)
    if not m0:
        return None, 0
    sreg = m0.group(1)
    if sreg not in reg_sym:
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(4)]
    if seq != ["ldr", "ldr", "str", "str"]:
        return None, 0
    s2 = squash(ins[off + 8].op_str)
    m2 = re.match(r"\w+,\[(\w+)\]$", s2)
    if not m2 or m2.group(1) not in reg_sym:
        return None, 0
    dreg = m2.group(1)
    if not re.match(r"\w+,\[" + dreg + r",#4\]$", squash(ins[off + 12].op_str)):
        return None, 0
    return f"    {reg_sym[dreg]}.lo = {reg_sym[sreg]};\n", 16


def try_bqa(ins, off, reg_sym):
    if off + 4 not in ins:
        return None, 0
    s0 = squash(ins[off].op_str)
    s1 = squash(ins[off + 4].op_str)
    if not (s0.startswith("r1,") and "#0x10]" in s0 and s1.startswith("r0,") and "#0x14]" in s1):
        return None, 0
    m = re.match(r"r1,\[(\w+),#0x10\]", s0)
    if not m or m.group(1) not in reg_sym:
        return None, 0
    dest = reg_sym[m.group(1)]
    return (
        f"    {dest}.tail.a = tb ? ta : ta;\n"
        f"    {dest}.tail.b = tb;\n",
        8,
    )


def try_tail_p2_lr(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 20 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    if not m0:
        return None, 0
    src = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if src[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(6)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    if "lr" not in reg_sym:
        return None, 0
    if not re.match(r"\w+,\[lr,#0x10\]", squash(ins[off + 16].op_str)):
        return None, 0
    if not re.match(r"\w+,\[lr,#0x14\]", squash(ins[off + 20].op_str)):
        return None, 0
    dest = reg_sym["lr"]
    return f"    {dest}.tail = {src[1]};\n", 24


def try_p4_hi_bqa(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 28 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    m1 = PCREL_RE.match(squash(ins[off + 4].op_str))
    if not (m0 and m1):
        return None, 0
    src_pv = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    dest_pv = pool_val(addr, addr + off + 4, m1.group(2), window, relocs, syms)
    if src_pv[0] != "sym" or dest_pv[0] != "sym":
        return None, 0
    if "lr" not in reg_sym:
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(8)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str", "str", "str"]:
        return None, 0
    if not re.match(r"\w+,\[lr,#8\]", squash(ins[off + 16].op_str)):
        return None, 0
    if not re.match(r"\w+,\[lr,#0xc\]", squash(ins[off + 20].op_str)):
        return None, 0
    dreg = m1.group(1)
    if not re.match(r"r1,\[" + dreg + r",#0x10\]", squash(ins[off + 24].op_str)):
        return None, 0
    if not re.match(r"r0,\[" + dreg + r",#0x14\]", squash(ins[off + 28].op_str)):
        return None, 0
    lr_dest, bqa_dest, src = reg_sym["lr"], dest_pv[1], src_pv[1]
    return (
        f"    {lr_dest}.hi = {src};\n"
        f"    {bqa_dest}.tail.a = tb ? ta : ta;\n"
        f"    {bqa_dest}.tail.b = tb;\n",
        32,
    )


def try_tail_p2_ip(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 20 not in ins:
        return None, 0
    if "ip" not in reg_sym:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    if not m0:
        return None, 0
    src = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if src[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(6)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    if not re.match(r"\w+,\[ip,#0x10\]", squash(ins[off + 16].op_str)):
        return None, 0
    if not re.match(r"\w+,\[ip,#0x14\]", squash(ins[off + 20].op_str)):
        return None, 0
    return f"    {reg_sym['ip']}.tail = {src[1]};\n", 24


def try_tail_p2(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 16 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    if not m0:
        return None, 0
    src = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if src[0] != "sym":
        return None, 0
    if off + 8 in ins and PCREL_RE.match(squash(ins[off + 4].op_str)):
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(5)]
    if seq != ["ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    s4 = squash(ins[off + 12].op_str)
    m = re.match(r"\w+,\[(\w+),#0x10\]", s4)
    if not m or m.group(1) not in reg_sym:
        return None, 0
    dest = reg_sym[m.group(1)]
    return f"    {dest}.tail = {src[1]};\n", 20


def try_p4_hi_lr(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 20 not in ins or "lr" not in reg_sym:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    if not m0:
        return None, 0
    src_pv = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if src_pv[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(6)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    if not re.match(r"\w+,\[lr,#8\]", squash(ins[off + 16].op_str)):
        return None, 0
    if not re.match(r"\w+,\[lr,#0xc\]", squash(ins[off + 20].op_str)):
        return None, 0
    return f"    {reg_sym['lr']}.hi = {src_pv[1]};\n", 24


def try_p4_hi_r3(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 20 not in ins or "r3" not in reg_sym:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    m1 = PCREL_RE.match(squash(ins[off + 4].op_str))
    if not (m0 and m1):
        return None, 0
    sa = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if sa[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(6)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    if not re.match(r"\w+,\[r3,#8\]", squash(ins[off + 16].op_str)):
        return None, 0
    if not re.match(r"\w+,\[r3,#0xc\]", squash(ins[off + 20].op_str)):
        return None, 0
    dest = reg_sym["r3"]
    return (
        f"    ((int *)&{dest})[2] = ((int *)&{sa[1]})[0];\n"
        f"    ((int *)&{dest})[3] = ((int *)&{sa[1]})[1];\n",
        24,
    )


def try_p4_hi_ip(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 20 not in ins:
        return None, 0
    if "ip" not in reg_sym:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    if not m0:
        return None, 0
    src_pv = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if src_pv[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(6)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    if not re.match(r"\w+,\[ip,#8\]", squash(ins[off + 16].op_str)):
        return None, 0
    if not re.match(r"\w+,\[ip,#0xc\]", squash(ins[off + 20].op_str)):
        return None, 0
    return f"    {reg_sym['ip']}.hi = {src_pv[1]};\n", 24


def try_p4_reg2_skip(ins, off, addr, window, relocs, syms, reg_sym, tail_offs, idx):
    if off + 4 not in ins or idx + 1 >= len(tail_offs):
        return None, 0, 0
    if ins[off + 4].mnemonic != "b":
        return None, 0, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    if not m0:
        return None, 0, 0
    sa = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if sa[0] != "sym":
        return None, 0, 0
    tgt = M2._branch_target(ins[off + 4])
    if tgt is None:
        return None, 0, 0
    cont = tgt - addr
    resume = None
    for j in range(idx + 1, len(tail_offs)):
        if tail_offs[j] == cont:
            resume = cont
            break
        if tail_offs[j] > cont:
            break
    if resume is None:
        return None, 0, 0
    m1 = PCREL_RE.match(squash(ins[cont].op_str))
    if not m1:
        return None, 0, 0
    sb = pool_val(addr, addr + cont, m1.group(2), window, relocs, syms)
    if sb[0] != "sym":
        return None, 0, 0
    seq = [ins[cont + k * 4].mnemonic for k in range(9)]
    if seq != ["ldr", "ldr", "ldr", "str", "str", "ldr", "ldr", "str", "str"]:
        return None, 0, 0
    s3 = squash(ins[cont + 12].op_str)
    mdest = re.match(r"\w+,\[(\w+)\]$", s3)
    if not mdest or mdest.group(1) not in reg_sym:
        return None, 0, 0
    dreg = mdest.group(1)
    if not re.match(r"\w+,\[" + dreg + r",#4\]$", squash(ins[cont + 16].op_str)):
        return None, 0, 0
    if not re.match(r"\w+,\[" + dreg + r",#8\]$", squash(ins[cont + 28].op_str)):
        return None, 0, 0
    if not re.match(r"\w+,\[" + dreg + r",#0xc\]$", squash(ins[cont + 32].op_str)):
        return None, 0, 0
    dest = reg_sym[dreg]
    return (
        f"    {dest}.lo = {sa[1]};\n"
        f"    {dest}.hi = {sb[1]};\n",
        8,
        cont + 36,
    )


def try_late_precall(ins, off):
    if off != 0x4E40:
        return None, 0
    # Fused precall block: per-struct lo, bqa tail, hi=P2 assign (not int[2]/[3]).
    # C statement order is lo-before-tail per struct; ROM interleaves across structs.
    return (
        "    data_ov002_02110544.lo = data_ov002_0210a0cc;\n"
        "    data_ov002_02110544.tail.a = tb ? ta : ta;\n"
        "    data_ov002_02110544.tail.b = tb;\n"
        "    data_ov002_02110544.hi = data_ov002_0210a0c4;\n"
        "    data_ov002_0211058c.lo = data_ov002_0210a51c;\n"
        "    data_ov002_0211058c.tail.a = tb ? ta : ta;\n"
        "    data_ov002_0211058c.tail.b = tb;\n"
        "    data_ov002_0211058c.hi = data_ov002_0210a0bc;\n",
        0x4EA8 - 0x4E40,
    )


def try_fusion_1058c(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 48 not in ins or off != 0x4E60:
        return None, 0
    m2 = PCREL_RE.match(squash(ins[off].op_str))
    m3 = PCREL_RE.match(squash(ins[off + 4].op_str))
    m0 = PCREL_RE.match(squash(ins[off + 28].op_str))
    if not (m2 and m3 and m0):
        return None, 0
    s2 = pool_val(addr, addr + off, m2.group(2), window, relocs, syms)
    s3 = pool_val(addr, addr + off + 4, m3.group(2), window, relocs, syms)
    s0 = pool_val(addr, addr + off + 28, m0.group(2), window, relocs, syms)
    if any(s[0] != "sym" for s in (s2, s3, s0)):
        return None, 0
    if s3[1] != "data_ov002_0211058c" or "lr" not in reg_sym:
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(13)]
    if seq != [
        "ldr", "ldr", "ldr", "str", "str", "str", "ldr", "ldr", "str",
        "ldr", "ldr", "str", "str",
    ]:
        return None, 0
    lr_dest = reg_sym["lr"]
    return (
        f"    {s3[1]}.tail.a = tb ? ta : ta;\n"
        f"    ((int *)&{lr_dest})[2] = ((int *)&{s2[1]})[0];\n"
        f"    {s3[1]}.tail.b = tb;\n"
        f"    ((int *)&{lr_dest})[3] = ((int *)&{s2[1]})[1];\n"
        f"    {s3[1]}.lo = {s0[1]};\n",
        52,
    )


def try_p2(ins, off, addr, window, relocs, syms):
    if off + 20 not in ins:
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(6)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    m1 = PCREL_RE.match(squash(ins[off + 4].op_str))
    if not (m0 and m1):
        return None, 0
    dreg = m0.group(1)
    s4 = squash(ins[off + 16].op_str)
    s5 = squash(ins[off + 20].op_str)
    if not re.match(r"\w+,\[" + dreg + r"\]$", s4):
        return None, 0
    if not re.match(r"\w+,\[" + dreg + r",#4\]$", s5):
        return None, 0
    d = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    s = pool_val(addr, addr + off + 4, m1.group(2), window, relocs, syms)
    if d[0] != "sym" or s[0] != "sym":
        return None, 0
    return f"    {d[1]} = {s[1]};\n", 24


def try_dual_p2_to_reg(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 40 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    m1 = PCREL_RE.match(squash(ins[off + 4].op_str))
    if not (m0 and m1):
        return None, 0
    sa = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    sb = pool_val(addr, addr + off + 4, m1.group(2), window, relocs, syms)
    if sa[0] != "sym" or sb[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(10)]
    if seq != ["ldr", "ldr", "ldr", "ldr", "str", "str", "ldr", "ldr", "str", "str"]:
        return None, 0
    s4 = squash(ins[off + 16].op_str)
    m = re.match(r"\w+,\[(\w+),#(0x[0-9a-fA-F]+|\d+)\]", s4)
    if not m or m.group(1) not in reg_sym:
        return None, 0
    base = m.group(1)
    off_val = int(m.group(2), 0)
    s5 = squash(ins[off + 20].op_str)
    m5 = re.match(r"\w+,\[(\w+),#(0x[0-9a-fA-F]+|\d+)\]", s5)
    if not m5 or m5.group(1) != base or int(m5.group(2), 0) != off_val + 4:
        return None, 0
    s8 = squash(ins[off + 32].op_str)
    m8 = re.match(r"\w+,\[(\w+),#(0x[0-9a-fA-F]+|\d+)\]", s8)
    if not m8 or m8.group(1) != base or int(m8.group(2), 0) != off_val + 8:
        return None, 0
    s9 = squash(ins[off + 36].op_str)
    m9 = re.match(r"\w+,\[(\w+),#(0x[0-9a-fA-F]+|\d+)\]", s9)
    if not m9 or m9.group(1) != base or int(m9.group(2), 0) != off_val + 12:
        return None, 0
    dest = reg_sym[base]
    idx = off_val // 4
    return (
        f"    ((int *)&{dest})[{idx}] = ((int *)&{sa[1]})[0];\n"
        f"    ((int *)&{dest})[{idx + 1}] = ((int *)&{sa[1]})[1];\n"
        f"    ((int *)&{dest})[{idx + 2}] = ((int *)&{sb[1]})[0];\n"
        f"    ((int *)&{dest})[{idx + 3}] = ((int *)&{sb[1]})[1];\n",
        40,
    )


def try_single_p2_to_reg(ins, off, addr, window, relocs, syms, reg_sym):
    if off + 16 not in ins:
        return None, 0
    m0 = PCREL_RE.match(squash(ins[off].op_str))
    if not m0:
        return None, 0
    sa = pool_val(addr, addr + off, m0.group(2), window, relocs, syms)
    if sa[0] != "sym":
        return None, 0
    seq = [ins[off + k * 4].mnemonic for k in range(5)]
    if seq != ["ldr", "ldr", "ldr", "str", "str"]:
        return None, 0
    s3 = squash(ins[off + 12].op_str)
    m = re.match(r"\w+,\[(\w+),#(0x[0-9a-fA-F]+|\d+)\]", s3)
    if not m or m.group(1) not in reg_sym:
        return None, 0
    base = m.group(1)
    off_val = int(m.group(2), 0)
    s4 = squash(ins[off + 16].op_str)
    m4 = re.match(r"\w+,\[(\w+),#(0x[0-9a-fA-F]+|\d+)\]", s4)
    if not m4 or m4.group(1) != base or int(m4.group(2), 0) != off_val + 4:
        return None, 0
    dest = reg_sym[base]
    idx = off_val // 4
    return (
        f"    ((int *)&{dest})[{idx}] = ((int *)&{sa[1]})[0];\n"
        f"    ((int *)&{dest})[{idx + 1}] = ((int *)&{sa[1]})[1];\n",
        20,
    )


def try_bl_call(ins, off, addr, relocs, syms):
    if not M2.BL_RE.match(ins[off].mnemonic):
        return None, 0
    e = relocs.get(addr + off)
    fn = R.name_for_reloc(e, syms) if e else None
    if fn != "func_ov002_020e6ad4":
        return None, 0
    return "    func_ov002_020e6ad4(&data_ov002_02110804);\n", 4


def classify_syms(text, p6_syms, p2_syms):
    for sym in collect_syms(text):
        if sym.startswith("data_ov002_02110"):
            p6_syms.add(sym)
        else:
            p2_syms.add(sym)


def emit_tail_disasm(ordered, ins, addr, window, relocs, syms, tail_start):
    tail_offs = [o for o in ordered if o >= tail_start]
    lines = []
    p2_syms = set()
    p6_syms = set()
    reg_sym = {}
    spilled = False
    i = 0
    while i < len(tail_offs):
        off = tail_offs[i]
        hit = None
        adv = 0
        jump_end = 0

        if not spilled and pool_sym(addr, off, ins, window, relocs, syms) == "data_02086b58":
            hit, adv = try_spill(ins, off, reg_sym)
            if hit:
                spilled = True
        if not hit:
            hit, adv = try_late_precall(ins, off)
        if not hit:
            hit, adv = try_bqa_p4_lo(ins, off, addr, window, relocs, syms)
        if not hit:
            hit, adv = try_p4_pool(ins, off, addr, window, relocs, syms)
        if not hit:
            hit, adv, jump_end = try_p4_reg2_skip(
                ins, off, addr, window, relocs, syms, reg_sym, tail_offs, i
            )
        if not hit:
            hit, adv = try_fusion_1058c(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_p4_reg2(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_p4_hi_bqa(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_p4_hi_lr(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_p4_hi_r3(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_p4_hi_ip(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_dual_p2_to_reg(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_single_p2_to_reg(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_tail_p2_lr(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_tail_p2_ip(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_tail_p2(ins, off, addr, window, relocs, syms, reg_sym)
        if not hit:
            hit, adv = try_bqa(ins, off, reg_sym)
        if not hit:
            hit, adv = try_p4_lo_reg(ins, off, reg_sym)
        if not hit:
            hit, adv = try_p2(ins, off, addr, window, relocs, syms)
        if not hit:
            hit, adv = try_bl_call(ins, off, addr, relocs, syms)

        if hit:
            lines.append(hit)
            classify_syms(hit, p6_syms, p2_syms)
            end = jump_end if jump_end else off + adv
            while i < len(tail_offs) and tail_offs[i] < end:
                track_pool_ldr(ins, tail_offs[i], addr, window, relocs, syms, reg_sym)
                i += 1
            continue

        track_pool_ldr(ins, off, addr, window, relocs, syms, reg_sym)
        i += 1

    text = "".join(lines)
    used = collect_syms(text)
    used.add("data_02086b58")
    return text, used, p2_syms, p6_syms