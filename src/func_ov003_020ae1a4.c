// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned short data_ov003_020b16ac[];

void func_ov003_020ae1a4(char *c, int sb)
{
    int found = 0;
    int m1 = -1;
    int one = 1;
    int i;
    for (i = 0; i < 3; i++) {
        unsigned short d = data_ov003_020b16ac[i];
        int q = sb / d;
        if (q == 0 && found == 0) {
            if (i != 2) {
                *(unsigned char *)(c + i + 0x121) = (unsigned char)m1;
            } else {
                found = one;
                *(unsigned char *)(c + i + 0x121) = (unsigned char)q;
            }
        }
        sb = (unsigned short)(sb % d);
    }
}
