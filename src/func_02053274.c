// NONMATCHING: register allocation (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
int func_02053274(int *a, int *b)
{
    volatile unsigned short *ime_reg = (volatile unsigned short *)0x4000208;
    volatile unsigned short *cnt = (volatile unsigned short *)0x40002b0;
    volatile unsigned int *param = (volatile unsigned int *)0x40002b8;
    int dy = a[1] - b[1];
    long long sq = (long long)dy * dy;
    int dx = a[0] - b[0];
    int dz;
    unsigned short ime;
    sq += (long long)dx * dx;
    dz = a[2] - b[2];
    sq += (long long)dz * dz;
    ime = *ime_reg;
    *ime_reg = 0;
    *cnt = 1;
    param[0] = (unsigned int)sq << 2;
    param[1] = ((unsigned int)(sq >> 32) << 2) | ((unsigned int)sq >> 30);
    *ime_reg;
    *ime_reg = ime;
    while (*cnt & 0x8000);
    return (*(volatile int *)0x40002b4 + 1) >> 1;
}
