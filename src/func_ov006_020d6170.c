// NONMATCHING: base materialization / addressing (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020d6170(char *c, int idx) {
    if (*(unsigned short *)(c + idx * 0x10 + 0x6288) != 0) {
        short *base = (short *)(c + 0x6288);
        base[idx * 8] = base[idx * 8] - 1;
        if (*(short *)(c + idx * 0x10 + 0x6288) < 0)
            *(short *)(c + idx * 0x10 + 0x6288) = 0;
    } else {
        *(unsigned char *)(c + idx * 0x10 + 0x628c) = 3;
    }
}
