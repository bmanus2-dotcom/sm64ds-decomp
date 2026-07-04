// NONMATCHING: register allocation (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
struct Obj {
    char pad0[0x10];
    s16 f10;
    s16 f12;
    char pad1[0x18-0x14];
    int f18;
    int f1c;
    char pad2[0x34-0x20];
    int f34;
};
extern int func_ov004_020b1aec(void);
extern void func_ov004_020b1cf0(int a, int b, int c, int sel, int e);
extern void func_ov004_020b2444(int a, int b, int c, int d, int e, int f, int g);
void func_ov004_020b35d8(struct Obj* self)
{
    int n;
    int y = self->f10;
    int v = (int)((unsigned int)(self->f34 << 7) >> 0x17);
    int w;
    int x;
    n = func_ov004_020b1aec() + 1;
    if (v > 0x100) v -= 0x200;
    if (v < 0) v = -v;
    x = self->f10 + v + 0x10;
    w = 0x10;
    {
        int p = 1;
        while (p < n) {
            p *= 10;
            w += 0x10;
        }
    }
    x = x - (w >> 1);
    func_ov004_020b1cf0((int)&self->f34, y - (w >> 1), self->f12, self->f1c, self->f18);
    func_ov004_020b2444(x, self->f12, n, self->f1c, self->f18, 2, 0);
}
