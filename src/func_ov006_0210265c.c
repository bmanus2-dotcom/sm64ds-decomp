// NONMATCHING: different op / idiom (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);

void func_ov006_0210265c(char *c)
{
    unsigned char *q;
    unsigned short *h;
    if (*(unsigned short *)(c + 0x5674) == 0) return;
    q = (unsigned char *)(c + 0x5679);
    *q = *q + 1;
    if (*(unsigned char *)(c + 0x5679) < 0x3c) return;
    *(unsigned char *)(c + 0x5679) = 0;
    h = (unsigned short *)(c + 0x5674);
    *h = *h - 1;
    if (*h > 0xa)
        _ZN5Sound12PlayBank2_2DEj(0xa8);
    else if (*h > 3)
        _ZN5Sound12PlayBank2_2DEj(0xa7);
    else
        _ZN5Sound12PlayBank2_2DEj(0xa6);
    if (*(unsigned short *)(c + 0x5674) == 0)
        *(unsigned char *)(c + 0x567a) = 0;
}
