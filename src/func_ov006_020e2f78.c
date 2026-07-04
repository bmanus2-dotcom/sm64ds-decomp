// NONMATCHING: different op / idiom (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020e1608(void);
extern void PlayBank2_2D(unsigned int);
extern void func_ov004_020adb1c(int self);
extern void func_ov006_020e2dbc(void *c);

void func_ov006_020e2f78(char *c)
{
    char *b;
    short *p;
    int i;
    int sum;
    int one;

    func_ov006_020e1608();
    b = c + 0x4e00;
    if (*(unsigned short *)(b + 0xe2) != 0)
    {
        p = (short *)(c + 0x4ee2);
        *p = *(unsigned short *)p - 1;
        if (*(short *)(b + 0xe2) <= 0)
            *(short *)(b + 0xe2) = 0;
        return;
    }

    one = 1;
    *(int *)(c + 0x4eac) = one;
    if (*(unsigned char *)(c + 0x4ee6) >= 5)
    {
        *(int *)(c + 0x4eac) = 3;
        *(short *)(b + 0xe2) = 0x80;
        *(unsigned char *)(c + 0x4ee8) = one;
        sum = 0;
        PlayBank2_2D(0x1bc);
        for (i = 0; i < 5; i++)
            sum += *(unsigned short *)(c + (i << 4) + 0x4744);
        func_ov004_020adb1c(sum);
    }

    for (i = 0; i < 5; i++)
    {
        *(int *)(c + (i << 4) + 0x473c) = 0;
        *(int *)(c + (i << 4) + 0x4740) = 0;
        *(short *)(c + (i << 4) + 0x4744) = 0;
        *(short *)(c + (i << 4) + 0x4746) = 0;
        *(unsigned char *)(c + (i << 4) + 0x4749) = 0;
        *(unsigned char *)(c + (i << 4) + 0x4748) = 0;
    }

    func_ov006_020e2dbc(c);
}
