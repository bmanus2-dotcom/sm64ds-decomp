// NONMATCHING: register allocation (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_0203f6e8(s16 v);
extern int func_0203f818(int arg);
extern int func_02059640(void);
extern int __aeabi_idiv(int a, int b);

extern u16 data_020a0f34;
extern u16 data_020a0fd0[];
extern u8 data_020a0ef4;
extern s16 data_020a0f18;

struct S { u16 f0, f2, f4, f6, f8, fa; };

void func_0203f714(struct S* s)
{
    u16 a, cur, v;
    int r;
    if (s->f2 != 0) {
        func_0203f6e8(-4);
        return;
    }
    a = s->fa;
    cur = data_020a0f34;
    v = s->f8;
    if (a < cur) {
        data_020a0f34 = a;
        data_020a0ef4 = 1;
        data_020a0fd0[0] = v;
    } else if (a == cur) {
        data_020a0fd0[data_020a0ef4] = v;
        data_020a0ef4++;
    }
    r = func_0203f818((u16)(v + 1));
    if (r == 1) {
        int n = func_02059640();
        int idx = __aeabi_idiv(n, data_020a0ef4);
        data_020a0f18 = data_020a0fd0[idx];
        func_0203f6e8(data_020a0f18);
    } else if (r == 2) {
        func_0203f6e8(-3);
    }
}
