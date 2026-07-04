// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0205e280(void);

int func_0205e7e0(unsigned int *thiz, unsigned char *out)
{
    int i;
    unsigned int r;
    if (thiz == 0 || out == 0) return 1;
    r = thiz[0x19];
    if (r != 0) return r;
    if (thiz[0x18] == 0) {
        char *p = (char*)thiz;
        func_0205e280();
        for (i = 0; i < 0x40; i++)
            (p + i)[0x20] = 0;
        thiz[5] = 0;
        thiz[6] = 0;
        thiz[0x18] = 1;
    }
    for (i = 0; i < 0x14; i++)
        out[i] = (unsigned char)(thiz[i >> 2] >> ((3 - (i & 3)) * 8));
    return 0;
}
