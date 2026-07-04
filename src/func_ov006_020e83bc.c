// NONMATCHING: register allocation (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020e83bc(char *c, int i)
{
    int *p = (int*)(c + i * 32 + 0x5000);
    *(int*)(c + 0x52bc + i * 32) = *(int*)(c + 0x52bc + i * 32) + p[0xb1];
    *(int*)(c + 0x52c0 + i * 32) = *(int*)(c + 0x52c0 + i * 32) + p[0xb2];
    if (p[0xb1] > 0) {
        unsigned char e = *(unsigned char*)(c + i * 32 + 0x52d5);
        *(int*)(c + 0x52c4 + i * 32) = *(int*)(c + 0x52c4 + i * 32) - (e * 16 + 0x10);
        if ((short)p[0xb1] < 0) p[0xb1] = 0;
    } else if (p[0xb1] < 0) {
        unsigned char e = *(unsigned char*)(c + i * 32 + 0x52d5);
        *(int*)(c + 0x52c4 + i * 32) = *(int*)(c + 0x52c4 + i * 32) + (e * 16 + 0x10);
        if ((short)p[0xb1] > 0) p[0xb1] = 0;
    } else {
        *(unsigned char*)(c + i * 32 + 0x52da) = 0;
    }
}
