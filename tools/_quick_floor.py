#!/usr/bin/env python3
import subprocess, sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
P = REPO / "src" / "_qf.c"
FLAGS = "-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc"
FLAGS_CPP = FLAGS.replace("-lang c99", "-lang c++")


def go(name, src, func, addr, size, binp=None, base=None, cpp=False):
    P.write_text(src.strip() + "\n")
    cmd = [sys.executable, str(REPO / "tools/match.py"), "--c", str(P), "--func", func,
           "--addr", addr, "--size", size, "--version", "1.2/sp2p3",
           "--flags", FLAGS_CPP if cpp else FLAGS, "--brief"]
    if binp:
        cmd += ["--bin", str(REPO / binp), "--base", base]
    out = subprocess.run(cmd, capture_output=True, text=True, cwd=str(REPO)).stdout
    if "MATCHING VERSIONS: 1.2/sp2p3" in out:
        return "MATCH"
    for line in out.splitlines():
        if "sp2p3:" in line or "size differs" in line or "compile failed" in line:
            return line.strip()
    return "?"


tests = {
    "bc_sub1": ("""extern int func_ov007_020c9214();
void func_ov007_020bc3dc(void *c, int i, int a2) {
    unsigned short **arr; unsigned short *p; int flag;
    unsigned char b;
    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) return;
    b = *(unsigned char *)((char *)p + 4);
    flag = 1 - (b == 0);
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}""", "func_ov007_020bc3dc", "0x020bc3dc", "0x58", "extracted/dsd/arm9_overlays/ov007.bin", "0x020ad660", False),

    "bc_not_eq": ("""extern int func_ov007_020c9214();
void func_ov007_020bc3dc(void *c, int i, int a2) {
    unsigned short **arr; unsigned short *p; int flag;
    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) return;
    flag = !(*(unsigned char *)((char *)p + 4) == 0);
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}""", "func_ov007_020bc3dc", "0x020bc3dc", "0x58", "extracted/dsd/arm9_overlays/ov007.bin", "0x020ad660", False),

    "e3_z_first": ("""extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
struct Ctx { int z; unsigned int len; char *buf; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx; unsigned int r;
    ctx.z = 0; ctx.len = len; ctx.buf = buf;
    r = func_0206e4a4(func_0206e450, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}""", "func_0206e3dc", "0x0206e3dc", "0x74", None, None, False),

    "e3_fn_first_z0": ("""extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
struct Ctx { char *buf; unsigned int len; int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx; unsigned int r; void (*fn)(void);
    fn = func_0206e450;
    ctx.z = 0;
    ctx.buf = buf;
    ctx.len = len;
    r = func_0206e4a4(fn, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}""", "func_0206e3dc", "0x0206e3dc", "0x74", None, None, False),

    "bf_vol": ("""typedef int Fix12i;
void func_ov002_020bfa74(void); void func_ov002_020c0108(void*,int);
void _ZN5Actor9UpdatePosEP12CylinderClsn(void*,void*); void func_ov002_020ce798(void*);
void func_ov002_020bf36c(char *self, void *arg) {
    volatile unsigned char *vp;
    unsigned char r2;
    Fix12i saved;
    vp = (volatile unsigned char *)(self + 0x709);
    r2 = *vp;
    if (r2 == 0) func_ov002_020bfa74();
    if ((*(unsigned char *)(self + 0x6e9) & 1) || *(unsigned char *)(self + 0x706))
        func_ov002_020c0108(self, 1);
    if (*(int *)(self + 0x37c)) return;
    saved = *(Fix12i *)(self + 0x98);
    if (*(unsigned char *)(self + 0x6e9) & 1)
        *(Fix12i *)(self + 0x98) = (Fix12i)(((long long)saved * *(Fix12i *)(self + 0x558) + 0x800) >> 12);
    _ZN5Actor9UpdatePosEP12CylinderClsn(self, arg);
    *(Fix12i *)(self + 0x98) = saved;
    func_ov002_020ce798(self);
}""", "func_ov002_020bf36c", "0x020bf36c", "0xa0", "extracted/dsd/arm9_overlays/ov002.bin", "0x020ad660", False),

    "doset_xor": ("""int _ZN5Model23AddToCommonModelDataArrER8BMD_File(void *);
unsigned int func_02046564(void *);
void *_ZN6Memory13operator_new2Ej(unsigned int);
int func_020462d0(void *, void *);
int _ZN15ModelComponents21UpdateVertsUsingBonesEv(void *);
int func_02016b24(void *, int);
int _ZN5Model12SetPolygonIDEi(void *, int);
int _ZN5Model9DoSetFileEPcii(void *c, void *file, int a, int b) {
    void *alloc;
    void *slot;
    _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
    alloc = _ZN6Memory13operator_new2Ej(func_02046564(file));
    *(void **)((char *)c + 0x4c) = alloc;
    slot = *(void **)((char *)c + 0x4c);
    if (slot == 0 || (slot ^ alloc) != 0) return 0;
    func_020462d0((char *)c + 8, file);
    _ZN15ModelComponents21UpdateVertsUsingBonesEv((char *)c + 8);
    if (a != 0) func_02016b24(c, 0x8000);
    if (b < 0) return 1;
    _ZN5Model12SetPolygonIDEi(c, b & 0xff);
    return 1;
}""", "_ZN5Model9DoSetFileEPcii", "0x02016bf8", "0xa0", None, None, False),
}

for name, args in tests.items():
    print(name, go(name, *args))