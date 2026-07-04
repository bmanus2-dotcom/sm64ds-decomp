// NONMATCHING: register allocation (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov063_0211a964(void);
extern void func_ov063_02119b1c(void *);

void func_ov063_02119a50(char *c) {
    *(unsigned short *)(c + 0x5d4) &= ~0x40;
    if (*(unsigned short *)(c + 0x100) >= 0x1e) {
        *(unsigned char *)(c + 0x5cc) = 1;
    } else {
        *(int *)(c + 0xa8) = 0;
        *(int *)(c + 0x98) = 0x7ccc;
        func_ov063_0211a964();
    }
    func_ov063_02119b1c(c);
}
