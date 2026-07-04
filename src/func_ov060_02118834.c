// NONMATCHING: different op / idiom (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov060_021184bc(char *c);

void func_ov060_02118834(char *c)
{
    unsigned short h = *(unsigned short*)(c + 0x100 + 0xac);
    int ip = h * 9;
    int v = (ip << 12) / 7 + 0x1000;
    *(int*)(c + 0x80) = v;
    *(int*)(c + 0x84) = v;
    *(int*)(c + 0x88) = v;
    {
        unsigned char *p = (unsigned char*)(c + 0x1ae);
        *p = *p - 0xa;
    }
    if (*(unsigned char*)(c + 0x1ae) < 0xa) *(unsigned char*)(c + 0x1ae) = 0;
    *(int*)(c + 0x60) += *(int*)(c + 0xa8);
    if (*(unsigned short*)(c + 0x100 + 0xac) == 0x1c) func_ov060_021184bc(c);
    *(unsigned short*)(c + 0x1ac) += 1;
}
