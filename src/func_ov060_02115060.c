// NONMATCHING: register allocation (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov060_021150d0(void);
extern void func_ov060_021150c4(void);

void func_ov060_02115060(char *c) {
    if (*(unsigned char *)(c + 0x415) == 0) {
        if (*(unsigned char *)(c + 0x416) != 0) {
            func_ov060_021150c4();
        } else {
            func_ov060_021150d0();
        }
        (*(unsigned char *)(c + 0x415))++;
        return;
    }
    *(unsigned char *)(c + 0x415) = 0;
    *(int *)(c + 0x40c) = 0xe;
}
