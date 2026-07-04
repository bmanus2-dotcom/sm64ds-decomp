// NONMATCHING: push-set / frame (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_ov006_0212e2c8[];
extern int data_ov006_0212e2e0[];
void func_ov006_020d62e0(char *c) {
    int i;
    for (i = 0; i < 2; i++) {
        *(unsigned char *)(c + i * 0x10 + 0x628d) = 1;
        *(unsigned char *)(c + i * 0x10 + 0x628c) = 0;
        *(unsigned char *)(c + i * 0x10 + 0x628e) = 1;
        *(int *)(c + i * 0x10 + 0x6280) = data_ov006_0212e2c8[i] << 0xc;
        *(int *)(c + i * 0x10 + 0x6284) = data_ov006_0212e2e0[i] << 0xc;
        *(unsigned char *)(c + i * 0x10 + 0x628f) = 0;
        *(short *)(c + i * 0x10 + 0x6288) = 0;
    }
}
