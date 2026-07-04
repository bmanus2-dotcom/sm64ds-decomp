// NONMATCHING: register allocation (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_0211e020(char* c, int i)
{
    int n;
    char* p = c;
    for (n = 0; n < 0x10; n++) {
        if (*(unsigned char*)(p + 0x4a70) == 0) {
            char* d = c + n * 0x14 + 0x4000;
            char* s = c + i * 0x24;
            unsigned char* tbl = (unsigned char*)(c + 0x4680);
            *(unsigned char*)(d + 0xa70) = 1;
            *(unsigned char*)(d + 0xa71) = 0;
            *(int*)(d + 0xa60) = *(int*)(s + 0x4660);
            *(int*)(d + 0xa64) = *(int*)(s + 0x4664) - 0x10000;
            *(int*)(d + 0xa6c) = tbl[i * 0x24] * 0x3c + 0x10;
            *(unsigned char*)(d + 0xa73) = 0;
            *(unsigned char*)(d + 0xa72) = tbl[i * 0x24];
            return;
        }
        p += 0x14;
    }
}
