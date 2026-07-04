// NONMATCHING: push-set / frame (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_ov006_0212e2d8[];
extern int data_ov006_0212e2d0[];
void func_ov006_020d6630(char *c) {
    int i;
    for (i = 0; i < 2; i++) {
        *(unsigned char *)(c + i * 0x10 + 0x626d) = 1;
        *(unsigned char *)(c + i * 0x10 + 0x626c) = 0;
        *(int *)(c + i * 0x10 + 0x6260) = data_ov006_0212e2d8[i] << 0xc;
        *(int *)(c + i * 0x10 + 0x6264) = data_ov006_0212e2d0[i] << 0xc;
        *(unsigned char *)(c + i * 0x10 + 0x626f) = 0;
        *(short *)(c + i * 0x10 + 0x6268) = 0;
        *(unsigned char *)(c + i * 0x10 + 0x626e) = 1;
    }
}
