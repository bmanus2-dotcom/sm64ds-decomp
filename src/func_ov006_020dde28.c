// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned short data_ov006_0212e32c[];

void func_ov006_020dde28(char *c, int index)
{
    char *e = c + index * 0x1c;
    unsigned short cur;
    unsigned char k;
    *(unsigned short *)(c + 0x4672 + index * 0x1c) =
        *(unsigned short *)(c + 0x4672 + index * 0x1c) + 1;
    k = *(unsigned char *)(e + 0x4000 + 0x678);
    cur = *(unsigned short *)(c + 0x4672 + index * 0x1c);
    if (cur < data_ov006_0212e32c[k])
        return;
    *(unsigned char *)(c + 0x4678 + index * 0x1c) =
        *(unsigned char *)(c + 0x4678 + index * 0x1c) + 1;
    *(unsigned char *)(c + 0x4678 + index * 0x1c) =
        *(unsigned char *)(c + 0x4678 + index * 0x1c) & 3;
    *(unsigned short *)e = 0;
}
