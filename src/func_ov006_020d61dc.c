// NONMATCHING: register allocation (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020d61dc(char *c, int index)
{
    char *base = c + index * 16;
    *(unsigned short *)(c + 0x6288 + index * 16) =
        *(unsigned short *)(c + 0x6288 + index * 16) + 1;
    if (*(unsigned short *)(base + 0x6200 + 0x88) < 5)
        return;
    *(unsigned short *)(base + 0x6200 + 0x88) = 0;
    *(unsigned char *)(c + 0x628f + index * 16) =
        *(unsigned char *)(c + 0x628f + index * 16) + 1;
    if (*(unsigned char *)(base + 0x6000 + 0x28f) >= 4) {
        *(unsigned char *)(base + 0x6000 + 0x28c) = 2;
        *(unsigned short *)(base + 0x6200 + 0x88) = 0x20;
    }
}
