// NONMATCHING: register allocation (div=19). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020f4b30(char *c)
{
    int x;
    unsigned char st;
    if (*(short *)(c + 0x5326) < 2)
        return;
    x = *(short *)(c + 0x5328);
    *(unsigned char *)(c + (0xb - x) * 0x18 + 0x5000 + 0x1bb) = 1;
    *(short *)(c + 0x5328) += 1;
    st = *(unsigned char *)(c + 0x533c);
    if (st == 1) {
        if (*(short *)(c + 0x5328) >= 0xa)
            *(int *)(c + 0x5318) = 4;
        return;
    }
    if (*(short *)(c + 0x5328) < 8)
        return;
    if (st != 0)
        *(int *)(c + 0x5318) = 3;
    else
        *(int *)(c + 0x5318) = 4;
}
