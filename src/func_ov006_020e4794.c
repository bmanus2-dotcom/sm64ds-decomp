// NONMATCHING: different op / idiom (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int RandomIntInternal(int *seed);
extern int data_0209d4b8[];
extern int data_ov006_0212e4fc[];
void func_ov006_020e4794(char *c, int idx) {
    unsigned r = (unsigned)RandomIntInternal(data_0209d4b8);
    int k = 0;
    unsigned m = ((r >> 16) & 0x7fff) << 3 >> 0xf;
    char *p = c + idx * 0x24;
    if (m == 5) k = 1;
    *(unsigned char *)(p + 0x48dd) = data_ov006_0212e4fc[k];
    *(unsigned char *)(p + 0x48de) = 0;
}
