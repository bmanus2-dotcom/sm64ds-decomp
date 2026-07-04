// NONMATCHING: different op / idiom (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_02053200(int x);
extern int func_ov004_020af770(int a0, int a1, int a2, int a3, int a4, int a5, unsigned short a6);

void func_ov006_020deed8(int a0, void *a1, int a2, int a3, int a4, int a5)
{
    unsigned char *sl = (unsigned char *)a1;
    int s = func_02053200(a4);
    int e2 = a2 >> 12;
    int e3 = a3 >> 12;

    for (;;) {
        int r = func_ov004_020af770((int)sl, e2, e3, -1, -1, s, 0);
        if (r != 0 && a5 == 2) {
            if ((unsigned)(*(int *)(sl + 4) << 0x10) >> 0x1c == 3) {
                int *p = (int *)(r + 4);
                *p = (*p & ~0xf000) | 0x4000;
            }
        }
        if (*(unsigned short *)(sl + 6) == 0xffff) break;
        sl += 8;
    }
}
