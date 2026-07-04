// NONMATCHING: register allocation (div=34). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
typedef unsigned short u16;

void func_ov006_020e0edc(char *c, int idx)
{
    register int n = idx * 0x24;
    int v;

    *(int *)(c + 0x478c + n) = *(int *)(c + 0x478c + n) + *(int *)(c + 0x4794 + n);
    *(int *)(c + 0x4790 + n) = *(int *)(c + 0x4790 + n) + *(int *)((char *)(c + n) + 0x4798);

    if (*(u16 *)(c + 0x47a0 + n) != 0) {
        *(s16 *)(c + 0x47a0 + n) = *(u16 *)(c + 0x47a0 + n) - 1;
        if (*(s16 *)(c + 0x47a0 + n) < 0) *(s16 *)(c + 0x47a0 + n) = 0;
    } else {
        v = *(int *)(c + 0x4794 + n);
        if (v > -0x400) {
            v -= 0x20;
            *(int *)(c + 0x4794 + n) = v;
            if (*(int *)(c + 0x4794 + n) <= -0x400) *(int *)(c + 0x4794 + n) = 0x400;
        }
        if (*(u16 *)(c + 0x47a2 + n) != 0) {
            *(s16 *)(c + 0x47a2 + n) = *(u16 *)(c + 0x47a2 + n) - 1;
            if (*(s16 *)(c + 0x47a2 + n) < 0) *(s16 *)(c + 0x47a2 + n) = 0;
        } else {
            *(char *)((char *)(c + n) + 0x47aa) = 3;
        }
    }
}
