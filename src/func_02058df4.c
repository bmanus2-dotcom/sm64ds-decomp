// NONMATCHING: different op / idiom (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_023c0000;
extern int gMainRamFlag;

int func_02058df4(unsigned int idx)
{
    switch (idx) {
    case 0:
        return 0x23c0000;
    case 2:
        return 0x2700000;
    case 3:
        return 0x2000000;
    case 4:
    {
        int base = (int)&data_023c0000;
        int v = gMainRamFlag;
        int lim = (base + 0x3f80) - 0x600;
        if (v == 0) {
            if (base < 0x23c0020) base = 0x23c0020;
            return base;
        }
        if (v < 0) return base - v;
        return lim - v;
    }
    case 5:
        return 0x27ff800;
    case 6:
        return 0x37f8000;
    default:
        return 0;
    }
}
