// NONMATCHING: different op / idiom (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov075_0211a948(int *c)
{
    unsigned int w, b, t, s;
    unsigned int f0, f1, f2, f3;
    int e;
    *(volatile int*)0x40004c0 = c[0x90 / 4];
    *(volatile int*)0x40004c4 = c[0x94 / 4];
    w = (unsigned int)c[0x98 / 4];
    b = (unsigned int)c[0x88 / 4];
    f0 = w >> 0x1a;
    f1 = w >> 0x14;
    f2 = w >> 0x17;
    f3 = w >> 0x1d;
    *(volatile int*)0x40004a8 =
        (b >> 3)
        | ((f0 & 7) << 26)
        | ((f1 & 7) << 20)
        | ((f2 & 7) << 23)
        | ((f3 & 1) << 29);
    t = (unsigned int)c[0x98 / 4];
    e = (((t >> 0x1a) & 7) == 2) ? 1 : 0;
    s = (unsigned int)c[0x8c / 4];
    *(volatile int*)0x40004ac = s >> (4 - e);
    *(volatile int*)0x40004a4 = 0x11f0088;
}
