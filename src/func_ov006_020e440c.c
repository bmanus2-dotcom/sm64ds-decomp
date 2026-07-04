// NONMATCHING: register allocation (div=34). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
typedef unsigned short u16;

void func_ov006_020e440c(char *c, int idx)
{
    register int n = idx * 0x24;
    int v;

    *(int *)(c + 0x48c0 + n) = *(int *)(c + 0x48c0 + n) + *(int *)(c + 0x48c8 + n);
    *(int *)(c + 0x48c4 + n) = *(int *)(c + 0x48c4 + n) + *(int *)((char *)(c + n) + 0x48cc);

    if (*(u16 *)(c + 0x48d4 + n) != 0) {
        *(s16 *)(c + 0x48d4 + n) = *(u16 *)(c + 0x48d4 + n) - 1;
        if (*(s16 *)(c + 0x48d4 + n) < 0) *(s16 *)(c + 0x48d4 + n) = 0;
    } else {
        v = *(int *)(c + 0x48c8 + n);
        if (v > -0x400) {
            v -= 0x20;
            *(int *)(c + 0x48c8 + n) = v;
            if (*(int *)(c + 0x48c8 + n) <= -0x400) *(int *)(c + 0x48c8 + n) = 0x400;
        }
        if (*(u16 *)(c + 0x48d6 + n) != 0) {
            *(s16 *)(c + 0x48d6 + n) = *(u16 *)(c + 0x48d6 + n) - 1;
            if (*(s16 *)(c + 0x48d6 + n) < 0) *(s16 *)(c + 0x48d6 + n) = 0;
        } else {
            *(char *)((char *)(c + n) + 0x48de) = 3;
        }
    }
}
