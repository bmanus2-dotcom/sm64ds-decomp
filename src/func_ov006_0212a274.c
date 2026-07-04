// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int RandomIntInternal(int *seed);
extern int data_0209d4b8;
extern unsigned char data_ov006_0212f3b4[];

void func_ov006_0212a274(char *self, int idx)
{
    int r = RandomIntInternal(&data_0209d4b8);
    int v = (((r >> 16) & 0x7fff) << 3) >> 0xf;
    *(unsigned char *)(self + idx * 0x24 + 0xbeaf) = data_ov006_0212f3b4[v == 5];
    *(unsigned char *)(self + idx * 0x24 + 0xbeb0) = 0;
}
