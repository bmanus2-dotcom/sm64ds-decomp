// NONMATCHING: register allocation (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_0211e55c(char* c, int idx) {
    int i;
    char* slot = c;
    for (i = 0; i < 0x10; i++) {
        if (*(unsigned char*)(slot + 0x4000 + 0x8a9) == 0) {
            char* d = c + i * 0xc + 0x4000;
            char* src = c + idx * 0x24 + 0x4000;
            *(unsigned char*)(d + 0x8a9) = 1;
            *(unsigned char*)(d + 0x8aa) = 1;
            *(int*)(d + 0x8a0) = *(int*)(src + 0x660);
            *(int*)(d + 0x8a4) = *(int*)(src + 0x664) - 0x18000;
            *(unsigned char*)(d + 0x8a8) = 0x60;
            return;
        }
        slot += 0xc;
    }
}
