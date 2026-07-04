// NONMATCHING: base materialization / addressing (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov102_0214b384(char *c, int a);
extern void func_ov102_0214c0b8(char *c);

void func_ov102_0214ad40(char *c)
{
    if ((unsigned char)(*(unsigned char *)(c + 0x3f5) + 0xfe) > 1)
        return;
    if (*(int *)(c + 0x60) >= *(int *)(c + 0x3c8) - 0x12c000)
        return;
    {
        unsigned short v = *(unsigned short *)(c + 0x3ea);
        if (v > 4)
            ;
        else if (v != 0)
            return;
    }
    func_ov102_0214b384(c, 4);
    *(unsigned char *)(c + 0x3f5) = 3;
    *(int *)(c + 0x128) = *(int *)(c + 0x128) & ~2;
    func_ov102_0214c0b8(c);
}
