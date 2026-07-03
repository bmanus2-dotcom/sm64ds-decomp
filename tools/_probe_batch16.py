#!/usr/bin/env python3
"""Sweep near-miss variants for batch16 leftovers."""
import pathlib, subprocess, sys

DECOMP = pathlib.Path(__file__).resolve().parent.parent
PROBE = DECOMP / "src" / "_probe16.c"
FLAGS = "-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc"
FLAGS_CPP = FLAGS.replace("-lang c99", "-lang c++")

TARGETS = {
    "bf36c": ("func_ov002_020bf36c", "0x020bf36c", "0xa0",
              str(DECOMP / "extracted/dsd/arm9_overlays/ov002.bin"), "0x020ad660", FLAGS_CPP),
    "doset": ("_ZN5Model9DoSetFileEPcii", "0x02016bf8", "0xa0", None, None, FLAGS_CPP),
    "memleft": ("_ZN18SolidHeapAllocator10MemoryLeftEi", "0x0204eaf0", "0x40", None, None, FLAGS),
    "e3dc": ("func_0206e3dc", "0x0206e3dc", "0x74", None, None, FLAGS),
    "bc3dc": ("func_ov007_020bc3dc", "0x020bc3dc", "0x58",
              str(DECOMP / "extracted/dsd/arm9_overlays/ov007.bin"), "0x020ad660", FLAGS),
}


def match(func, addr, size, bin_path, base, flags):
    cmd = [sys.executable, str(DECOMP / "tools/match.py"), "--c", str(PROBE),
           "--func", func, "--addr", addr, "--size", size, "--version", "1.2/sp2p3",
           "--flags", flags, "--brief"]
    if bin_path:
        cmd += ["--bin", bin_path, "--base", base]
    r = subprocess.run(cmd, capture_output=True, text=True, cwd=str(DECOMP))
    out = r.stdout
    if "compile failed" in out:
        return "COMPILE_FAIL"
    if "MATCHING VERSIONS: 1.2/sp2p3" in out:
        return "MATCH"
    for line in out.splitlines():
        if "sp2p3:" in line:
            return line.strip()
        if "size differs" in line:
            return line.strip()
    return "?"


def run_group(name, variants):
    t = TARGETS[name]
    print(f"\n=== {name} ===")
    for vname, src in variants.items():
        PROBE.write_text(src.strip() + "\n", encoding="utf-8")
        res = match(t[0], t[1], t[2], t[3], t[4], t[5])
        mark = " *** MATCH ***" if res == "MATCH" else ""
        print(f"  {vname}: {res}{mark}")


BF36C = """//cpp
typedef int Fix12i;
extern "C" void func_ov002_020bfa74(void);
extern "C" void func_ov002_020c0108(void *self, int x);
extern "C" void _ZN5Actor9UpdatePosEP12CylinderClsn(void *self, void *c);
extern "C" void func_ov002_020ce798(void *self);
extern "C" void func_ov002_020bf36c(char *self, void *arg)
{
%s
}
"""

BF36C_VARIANTS = {
    "e73ac_style": BF36C % """    int a, b, c;
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
    "ifelse_flag": BF36C % """    unsigned char b;
    int flag;
    Fix12i saved;
    b = *(unsigned char *)(self + 0x709);
    if (b == 0) flag = 0; else flag = 1;
    if (flag == 0) func_ov002_020bfa74();
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0 || *(unsigned char *)(self + 0x706) != 0)
        func_ov002_020c0108(self, 1);
    if (*(int *)(self + 0x37c) != 0) return;
    saved = *(Fix12i *)(self + 0x98);
    if ((*(unsigned char *)(self + 0x6e9) & 1) != 0)
        *(Fix12i *)(self + 0x98) = (Fix12i)(((long long)saved * *(Fix12i *)(self + 0x558) + 0x800) >> 12);
    _ZN5Actor9UpdatePosEP12CylinderClsn(self, arg);
    *(Fix12i *)(self + 0x98) = saved;
    func_ov002_020ce798(self);""",
    "saved_after": BF36C % """    unsigned char r2;
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
}

DOSET_HEAD = """//cpp
extern "C" {
int _ZN5Model23AddToCommonModelDataArrER8BMD_File(void*);
unsigned int func_02046564(void*);
void* _ZN6Memory13operator_new2Ej(unsigned int);
int func_020462d0(void*, void*);
int _ZN15ModelComponents21UpdateVertsUsingBonesEv(void*);
int func_02016b24(void*, int);
int _ZN5Model12SetPolygonIDEi(void*, int);
"""

DOSET_VARIANTS = {
    "alloc_and_slot": DOSET_HEAD + """
int _ZN5Model9DoSetFileEPcii(void* c, void* file, int a, int b){
  void* alloc;
  void* slot;
  _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
  alloc = _ZN6Memory13operator_new2Ej(func_02046564(file));
  *(void**)((char*)c+0x4c) = alloc;
  slot = *(void**)((char*)c+0x4c);
  if (slot == 0 || alloc == 0) return 0;
  func_020462d0((char*)c+8, file);
  _ZN15ModelComponents21UpdateVertsUsingBonesEv((char*)c+8);
  if (a != 0) func_02016b24(c, 0x8000);
  if (b < 0) return 1;
  _ZN5Model12SetPolygonIDEi(c, b & 0xff);
  return 1;
}
}""",
    "alloc_xor_check": DOSET_HEAD + """
int _ZN5Model9DoSetFileEPcii(void* c, void* file, int a, int b){
  void* alloc;
  _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
  alloc = _ZN6Memory13operator_new2Ej(func_02046564(file));
  *(void**)((char*)c+0x4c) = alloc;
  if ((*(void**)((char*)c+0x4c) ^ alloc) != 0) return 0;
  if (*(void**)((char*)c+0x4c) == 0) return 0;
  func_020462d0((char*)c+8, file);
  _ZN15ModelComponents21UpdateVertsUsingBonesEv((char*)c+8);
  if (a != 0) func_02016b24(c, 0x8000);
  if (b < 0) return 1;
  _ZN5Model12SetPolygonIDEi(c, b & 0xff);
  return 1;
}
}""",
    "size_after": DOSET_HEAD + """
int _ZN5Model9DoSetFileEPcii(void* c, void* file, int a, int b){
  unsigned int sz;
  _ZN5Model23AddToCommonModelDataArrER8BMD_File(file);
  sz = func_02046564(file);
  *(void**)((char*)c+0x4c) = _ZN6Memory13operator_new2Ej(sz);
  if (*(void**)((char*)c+0x4c) == 0) return 0;
  func_020462d0((char*)c+8, file);
  _ZN15ModelComponents21UpdateVertsUsingBonesEv((char*)c+8);
  if (a != 0) func_02016b24(c, 0x8000);
  if (b < 0) return 1;
  _ZN5Model12SetPolygonIDEi(c, b & 0xff);
  return 1;
}
}""",
}

MEM = """#pragma opt_strength_reduction off
typedef unsigned int u32;
extern int _ZN4cstd3absEi(int x);
int _ZN18SolidHeapAllocator10MemoryLeftEi(void *c, int align)
{
%s
}
"""

MEM_VARIANTS = {
    "pragma_t": MEM % """    int abs = _ZN4cstd3absEi(align);
    int *fb = (int *)(((long long)(int)((char *)c + 0x24)) & 0xFFFFFFFFFFFFFFFFLL);
    u32 m = (u32)abs - 1u;
    u32 b = (u32)fb[0];
    u32 t;
    u32 e;
    t = b + m;
    e = (u32)fb[1];
    if ((t & ~m) > e) return 0;
    return (int)(e - (t & ~m));""",
    "no_aligned": MEM % """    int abs = _ZN4cstd3absEi(align);
    int *fb = (int *)(((long long)(int)((char *)c + 0x24)) & 0xFFFFFFFFFFFFFFFFLL);
    u32 m = (u32)abs - 1u;
    u32 b = (u32)fb[0];
    u32 e = (u32)fb[1];
    u32 t = (b + m) & ~m;
    if (t > e) return 0;
    return (int)(e - t);""",
    "fb0_direct": MEM % """    int abs = _ZN4cstd3absEi(align);
    int *fb = (int *)(((long long)(int)((char *)c + 0x24)) & 0xFFFFFFFFFFFFFFFFLL);
    u32 m = (u32)abs - 1u;
    u32 e;
    u32 b = (u32)fb[0] + m;
    e = (u32)fb[1];
    if ((b & ~m) > e) return 0;
    return (int)(e - (b & ~m));""",
}

E3DC_HEAD = """extern void func_0206e450(void);
extern unsigned int func_0206e4a4(void (*fn)(void), void *ctx);
"""

E3DC_VARIANTS = {
    "mov_ip_first": E3DC_HEAD + """
struct Ctx { char *buf; unsigned int len; int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx;
    unsigned int r;
    asm { mov ip, #0 }
    ctx.buf = buf;
    ctx.len = len;
    ctx.z = 0;
    r = func_0206e4a4(func_0206e450, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}
""",
    "fn_ptr_first": E3DC_HEAD + """
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
}
""",
    "z_volatile": E3DC_HEAD + """
struct Ctx { char *buf; unsigned int len; volatile int z; };
unsigned int func_0206e3dc(char *buf, unsigned int len) {
    struct Ctx ctx;
    unsigned int r;
    ctx.buf = buf;
    ctx.len = len;
    ctx.z = 0;
    r = func_0206e4a4(func_0206e450, &ctx);
    if (buf == 0) return r;
    if (r < len) { buf[r] = 0; return r; }
    if (len != 0) { char *end = buf + len; end[-1] = 0; }
    return r;
}
""",
}

BC3DC_HEAD = """extern int func_ov007_020c9214();
"""

BC3DC_VARIANTS = {
    "ifelse": BC3DC_HEAD + """
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
    if (b == 0) flag = 0; else flag = 1;
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}
""",
    "enum_cast": BC3DC_HEAD + """
typedef enum { FALSE, TRUE } Bool;
void func_ov007_020bc3dc(void *c, int i, int a2)
{
    unsigned short **arr;
    unsigned short *p;
    Bool flag;
    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) return;
    flag = (Bool)(*(unsigned char *)((char *)p + 4) != 0);
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}
""",
    "byte_sep": BC3DC_HEAD + """
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
    flag = 1;
    if (b == 0) flag = 0;
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, flag, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}
""",
}

if __name__ == "__main__":
    for g, v in [("bf36c", BF36C_VARIANTS), ("doset", DOSET_VARIANTS),
                 ("memleft", MEM_VARIANTS), ("e3dc", E3DC_VARIANTS), ("bc3dc", BC3DC_VARIANTS)]:
        run_group(g, v)