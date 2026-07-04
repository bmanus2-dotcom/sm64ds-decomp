// NONMATCHING: register allocation (div=19). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_ov006_0212ee64[];
extern int data_ov006_0212ef00[];
void func_ov006_0211a420(char *c, int i){
    int o = i * 0x24;
    char *bIdx = c + 0x51d2;
    char *bVal = c + 0x51b0;
    char *b50 = c + o + 0x5000;
    unsigned char idx;
    *(unsigned char*)(b50 + 0x1cd) = 1;
    idx = *(unsigned char*)(bIdx + o);
    *(int*)(bVal + o) = *(int*)(bVal + o) + data_ov006_0212ee64[idx];
    *(int*)(b50 + 0x1bc) = -0x3800;
    *(int*)(b50 + 0x1b8) = data_ov006_0212ef00[*(unsigned char*)(bIdx + o)];
    *(short*)(c + o + 0x51c8) = 0;
    *(unsigned char*)(b50 + 0x1d1) = 1;
}
