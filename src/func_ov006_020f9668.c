// NONMATCHING: different op / idiom (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_ov006_0213d700;
extern short data_ov006_0213d6f8;
extern short data_ov006_0214255c;
extern int data_ov006_02142570;
extern int data_ov006_02142574;

int func_ov006_020f9668(void) {
    int a = (data_ov006_0213d700 << 4) >> 0x10;
    int b = data_ov006_0213d6f8;
    if (b > 0x14) b = 0x14;
    if (a != b) return 1;
    if (data_ov006_0214255c != 0) return 1;
    if (data_ov006_02142570 != 0) {
        if (data_ov006_02142574 != 0) return 1;
    }
    return 0;
}
