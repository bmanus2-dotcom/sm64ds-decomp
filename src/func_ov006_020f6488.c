// NONMATCHING: register allocation (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_ov004_020b56c8(int);
extern short data_ov004_020bf9e4;

struct S5300 {
    char pad[0xe2];
    unsigned short timer;   /* 0xe2 */
    char pad2[0xea - 0xe4];
    unsigned short fea;     /* 0xea */
};

void func_ov006_020f6488(char *c)
{
    struct S5300 *s = (struct S5300 *)(c + 0x5300);
    unsigned short *t;
    if (s->timer != 0) {
        t = (unsigned short *)(c + 0x53e2);
        t[0] = t[0] - 1;
        if (s->timer != 0)
            return;
        if (*(unsigned char *)(c + 0x5405) < s->fea)
            return;
        func_ov004_020b56c8((5 - *(unsigned char *)(c + 0x5408)) * 5);
        return;
    }
    if (data_ov004_020bf9e4 == 1) {
        s->timer = 0;
        *(int *)(c + 0x53d8) = 2;
    }
}
