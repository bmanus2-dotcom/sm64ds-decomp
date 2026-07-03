#!/usr/bin/env python3
"""Quick variant sweep for batch16 regperm floors."""
import subprocess
import sys
from pathlib import Path

DECOMP = Path(__file__).resolve().parent.parent
PROBE = DECOMP / "src" / "_sweep16.c"
FLAGS = "-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc"
FLAGS_CPP = FLAGS.replace("-lang c99", "-lang c++")


def match(func, addr, size, bin_path, base, flags):
    cmd = [
        sys.executable, str(DECOMP / "tools/match.py"), "--c", str(PROBE),
        "--func", func, "--addr", addr, "--size", size, "--version", "1.2/sp2p3",
        "--flags", flags, "--brief",
    ]
    if bin_path:
        cmd += ["--bin", str(DECOMP / bin_path), "--base", base]
    r = subprocess.run(cmd, capture_output=True, text=True, cwd=str(DECOMP))
    out = r.stdout
    if "compile failed" in out:
        return "COMPILE_FAIL"
    if "MATCHING VERSIONS: 1.2/sp2p3" in out:
        return "MATCH"
    for line in out.splitlines():
        if "sp2p3:" in line or "size differs" in line:
            return line.strip()
    return "?"


def run(name, func, addr, size, bin_path, base, flags, variants):
    print(f"\n=== {name} ===")
    for vname, src in variants.items():
        PROBE.write_text(src.strip() + "\n", encoding="utf-8")
        res = match(func, addr, size, bin_path, base, flags)
        mark = " *** MATCH ***" if res == "MATCH" else ""
        print(f"  {vname}: {res}{mark}")


BC3DC = {
    "dup_call": """extern int func_ov007_020c9214();
void func_ov007_020bc3dc(void *c, int i, int a2)
{
    unsigned short **arr;
    unsigned short *p;
    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) return;
    if (*(unsigned char *)((char *)p + 4) == 0)
        func_ov007_020c9214(*(void **)((char *)c + 0x18), i, 0, *(unsigned short *)((char *)p + 2), a2, 0x1000);
    else
        func_ov007_020c9214(*(void **)((char *)c + 0x18), i, 1, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}""",
    "if_assign": """extern int func_ov007_020c9214();
void func_ov007_020bc3dc(void *c, int i, int a2)
{
    unsigned short **arr;
    unsigned short *p;
    unsigned char b;
    int flag;
    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) return;
    b = *(unsigned char *)((char *)p + 4);
    flag = 0;
    if (b != 0) flag = 1;
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}""",
    "sub_one": """extern int func_ov007_020c9214();
void func_ov007_020bc3dc(void *c, int i, int a2)
{
    unsigned short **arr;
    unsigned short *p;
    int flag;
    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) return;
    flag = (int)(*(unsigned char *)((char *)p + 4) - 1) >> 31;
    flag = flag & 1;
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}""",
    "byte_ne": """extern int func_ov007_020c9214();
void func_ov007_020bc3dc(void *c, int i, int a2)
{
    unsigned short **arr;
    unsigned short *p;
    unsigned char b;
    int flag;
    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) return;
    b = *(unsigned char *)((char *)p + 4);
    flag = (b != 0);
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}""",
}

E3DC = {
    "struct_init": """extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
struct Ctx { char *buf; unsigned int len; int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx = { buf, len, 0 };
    unsigned int r;
    r = func_0206e4a4(func_0206e450, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}""",
    "fn_before_ctx": """extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
struct Ctx { char *buf; unsigned int len; int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx;
    unsigned int r;
    void (*fn)(void);
    fn = func_0206e450;
    ctx.buf = buf;
    ctx.len = len;
    ctx.z = 0;
    r = func_0206e4a4(fn, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}""",
    "extra_locals": """extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
struct Ctx { char *buf; unsigned int len; int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx;
    unsigned int r;
    char *b;
    unsigned int l;
    int z;
    b = buf;
    l = len;
    z = 0;
    ctx.buf = b;
    ctx.len = l;
    ctx.z = z;
    r = func_0206e4a4(func_0206e450, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}""",
    "z_via_ip_asm": """extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
struct Ctx { char *buf; unsigned int len; int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx;
    unsigned int r;
    ctx.buf = buf;
    ctx.len = len;
    asm { mov ip, #0; str ip, [sp, #8] }
    r = func_0206e4a4(func_0206e450, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}""",
    "volatile_ctx": """extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
struct Ctx { char *buf; unsigned int len; int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    volatile struct Ctx ctx;
    unsigned int r;
    ctx.buf = buf;
    ctx.len = len;
    ctx.z = 0;
    r = func_0206e4a4(func_0206e450, (void *)&ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}""",
}

BF36C_HEAD = """//cpp
typedef int Fix12i;
extern "C" void func_ov002_020bfa74(void);
extern "C" void func_ov002_020c0108(void *self, int x);
extern "C" void _ZN5Actor9UpdatePosEP12CylinderClsn(void *self, void *c);
extern "C" void func_ov002_020ce798(void *self);
extern "C" void func_ov002_020bf36c(char *self, void *arg)
{
%s
}"""

BF36C = {
    "e73ac_pressure": BF36C_HEAD % """    int a, b, c;
    unsigned char r2;
    Fix12i saved;
    r2 = *(unsigned char *)(self + 0x709);
    if (r2 == 0) func_ov002_020bfa74();
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0 || *(unsigned char *)(self + 0x706) != 0)
        func_ov002_020c0108(self, 1);
    if (*(int *)(self + 0x37c) != 0) return;
    saved = *(Fix12i *)(self + 0x98);
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0)
        *(Fix12i *)(self + 0x98) = (Fix12i)(((long long)saved * *(Fix12i *)(self + 0x558) + 0x800) >> 12);
    _ZN5Actor9UpdatePosEP12CylinderClsn(self, arg);
    *(Fix12i *)(self + 0x98) = saved;
    func_ov002_020ce798(self);""",
    "r2_before_saved": BF36C_HEAD % """    unsigned char r2;
    Fix12i saved;
    int t;
    t = 0;
    r2 = *(unsigned char *)(self + 0x709);
    if (r2 == 0) func_ov002_020bfa74();
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0 || *(unsigned char *)(self + 0x706) != 0)
        func_ov002_020c0108(self, 1);
    if (*(int *)(self + 0x37c) != 0) return;
    saved = *(Fix12i *)(self + 0x98);
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0)
        *(Fix12i *)(self + 0x98) = (Fix12i)(((long long)saved * *(Fix12i *)(self + 0x558) + 0x800) >> 12);
    _ZN5Actor9UpdatePosEP12CylinderClsn(self, arg);
    *(Fix12i *)(self + 0x98) = saved;
    func_ov002_020ce798(self);""",
    "deref_r2": BF36C_HEAD % """    unsigned char r2;
    Fix12i saved;
    unsigned char *base;
    base = (unsigned char *)self;
    r2 = base[0x709];
    if (r2 == 0) func_ov002_020bfa74();
    if ((base[0x6e9] & 1) != 0 || base[0x706] != 0)
        func_ov002_020c0108(self, 1);
    if (*(int *)(self + 0x37c) != 0) return;
    saved = *(Fix12i *)(self + 0x98);
    if ((base[0x6e9] & 1) != 0)
        *(Fix12i *)(self + 0x98) = (Fix12i)(((long long)saved * *(Fix12i *)(self + 0x558) + 0x800) >> 12);
    _ZN5Actor9UpdatePosEP12CylinderClsn(self, arg);
    *(Fix12i *)(self + 0x98) = saved;
    func_ov002_020ce798(self);""",
    "dup_call_f": BF36C_HEAD % """    Fix12i saved;
    if (*(unsigned char *)(self + 0x709) == 0) func_ov002_020bfa74();
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0 || *(unsigned char *)(self + 0x706) != 0)
        func_ov002_020c0108(self, 1);
    if (*(int *)(self + 0x37c) != 0) return;
    saved = *(Fix12i *)(self + 0x98);
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0)
        *(Fix12i *)(self + 0x98) = (Fix12i)(((long long)saved * *(Fix12i *)(self + 0x558) + 0x800) >> 12);
    _ZN5Actor9UpdatePosEP12CylinderClsn(self, arg);
    *(Fix12i *)(self + 0x98) = saved;
    func_ov002_020ce798(self);""",
}

DOSET_HEAD = """//cpp
extern "C" {
int _ZN5Model23AddToCommonModelDataArrER8BMD_File(void *);
unsigned int func_02046564(void *);
void *_ZN6Memory13operator_new2Ej(unsigned int);
int func_020462d0(void *, void *);
int _ZN15ModelComponents21UpdateVertsUsingBonesEv(void *);
int func_02016b24(void *, int);
int _ZN5Model12SetPolygonIDEi(void *, int);
"""

DOSET = {
    "slot_ptr": DOSET_HEAD + """
int _ZN5Model9DoSetFileEPcii(void *c, void *file, int a, int b)
{
    void **slot;
    _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
    slot = (void **)((char *)c + 0x4c);
    *slot = _ZN6Memory13operator_new2Ej(func_02046564(file));
    if (*slot == 0) return 0;
    func_020462d0((char *)c + 8, file);
    _ZN15ModelComponents21UpdateVertsUsingBonesEv((char *)c + 8);
    if (a != 0) func_02016b24(c, 0x8000);
    if (b < 0) return 1;
    _ZN5Model12SetPolygonIDEi(c, b & 0xff);
    return 1;
}
}""",
    "alloc_named_r2": DOSET_HEAD + """
int _ZN5Model9DoSetFileEPcii(void *c, void *file, int a, int b)
{
    void *r2;
    unsigned int sz;
    sz = func_02046564(file);
    _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
    r2 = _ZN6Memory13operator_new2Ej(sz);
    *(void **)((char *)c + 0x4c) = r2;
    if (r2 == 0) return 0;
    func_020462d0((char *)c + 8, file);
    _ZN15ModelComponents21UpdateVertsUsingBonesEv((char *)c + 8);
    if (a != 0) func_02016b24(c, 0x8000);
    if (b < 0) return 1;
    _ZN5Model12SetPolygonIDEi(c, b & 0xff);
    return 1;
}
}""",
    "dup_zero_check": DOSET_HEAD + """
int _ZN5Model9DoSetFileEPcii(void *c, void *file, int a, int b)
{
    void *alloc;
    _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
    alloc = _ZN6Memory13operator_new2Ej(func_02046564(file));
    *(void **)((char *)c + 0x4c) = alloc;
    if (alloc == 0) return 0;
    if (*(void **)((char *)c + 0x4c) == 0) return 0;
    func_020462d0((char *)c + 8, file);
    _ZN15ModelComponents21UpdateVertsUsingBonesEv((char *)c + 8);
    if (a != 0) func_02016b24(c, 0x8000);
    if (b < 0) return 1;
    _ZN5Model12SetPolygonIDEi(c, b & 0xff);
    return 1;
}
}""",
    "store_then_r2_reload": DOSET_HEAD + """
int _ZN5Model9DoSetFileEPcii(void *c, void *file, int a, int b)
{
    void *r2;
    void *alloc;
    _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
    alloc = _ZN6Memory13operator_new2Ej(func_02046564(file));
    *(void **)((char *)c + 0x4c) = alloc;
    r2 = *(void **)((char *)c + 0x4c);
    if (r2 == 0) return 0;
    func_020462d0((char *)c + 8, file);
    _ZN15ModelComponents21UpdateVertsUsingBonesEv((char *)c + 8);
    if (a != 0) func_02016b24(c, 0x8000);
    if (b < 0) return 1;
    _ZN5Model12SetPolygonIDEi(c, b & 0xff);
    return 1;
}
}""",
}


if __name__ == "__main__":
    run("bc3dc", "func_ov007_020bc3dc", "0x020bc3dc", "0x58",
        "extracted/dsd/arm9_overlays/ov007.bin", "0x020ad660", FLAGS, BC3DC)
    run("e3dc", "func_0206e3dc", "0x0206e3dc", "0x74", None, None, FLAGS, E3DC)
    run("bf36c", "func_ov002_020bf36c", "0x020bf36c", "0xa0",
        "extracted/dsd/arm9_overlays/ov002.bin", "0x020ad660", FLAGS_CPP, BF36C)
    run("doset", "_ZN5Model9DoSetFileEPcii", "0x02016bf8", "0xa0", None, None, FLAGS_CPP, DOSET)