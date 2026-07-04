// NONMATCHING: register allocation (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_ov004_020b56c8(int);
extern short data_ov004_020bf9e4;

struct S5300 {
    char pad[0x22];
    unsigned short timer;   /* 0x22 */
    char pad2[0x2a - 0x24];
    unsigned short f2a;     /* 0x2a */
};

void func_ov006_020f47d8(char *c)
{
    struct S5300 *s = (struct S5300 *)(c + 0x5300);
    unsigned short *t;
    if (s->timer != 0) {
        t = (unsigned short *)(c + 0x5322);
        t[0] = t[0] - 1;
        if (s->timer != 0)
            return;
        if (*(unsigned char *)(c + 0x5337) < s->f2a)
            return;
        func_ov004_020b56c8((3 - *(unsigned char *)(c + 0x533a)) * 6);
        return;
    }
    if (data_ov004_020bf9e4 == 1) {
        s->timer = 0;
        *(int *)(c + 0x5318) = 2;
    }
}
