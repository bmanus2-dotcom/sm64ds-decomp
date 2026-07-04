// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_020a648c;
extern int data_020a64a0;
extern int data_020a6760;
extern int data_020a649c;
extern int data_020a64a8[];
extern int data_020a64a4;
extern int data_020a6490;

extern void _ZN4CP1527FlushAndInvalidateDataCacheEjj(unsigned int a, unsigned int b);
extern int IPCSend(unsigned int a, unsigned int c, unsigned int b);
extern int func_0205b274(int a);

int func_0205b070(int x)
{
    if (data_020a648c == 0) return 1;
    if (data_020a64a0 >= 8) {
        if (x == 0) return 0;
        do {
            func_0205b274(1);
        } while (data_020a64a0 >= 8);
    }
    _ZN4CP1527FlushAndInvalidateDataCacheEjj((unsigned int)&data_020a6760, 0x1800);
    if (IPCSend(7, data_020a648c, 0) < 0) {
        if (x == 0) return 0;
        while (IPCSend(7, data_020a648c, 0) < 0)
            ;
    }
    data_020a64a8[data_020a649c] = data_020a648c;
    data_020a649c++;
    if (data_020a649c > 8) data_020a649c = 0;

    data_020a64a4++;
    data_020a648c = 0;
    data_020a6490 = 0;
    data_020a64a0++;
    return 1;
}
