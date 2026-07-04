// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void MultiStore32Bytes(unsigned val, int *dst, int len);
extern void _ZN4CP1527FlushAndInvalidateDataCacheEjj(unsigned int a, unsigned int b);
extern void func_02058200(void *a, void *fn, int c, void *d, int e, int f);
extern void func_02058048(void *a);
extern void func_0205ba64(int a, void *fn);

extern void func_020602bc(void);
extern void func_02060310(void);

extern int data_020a8180;
extern int data_020a8160[];
extern int data_020a81bc;
extern int data_020a8760;

void func_0206002c(void)
{
    int *base = &data_020a8180;
    int local;
    int v38;

    base[2] = ~2;            /* field_8 */
    base[3] = 0;             /* field_c */
    local = 0;
    base[5] = 0;             /* field_14 */
    base[0] = (int)data_020a8160;
    MultiStore32Bytes(local, data_020a8160, 0x20);

    _ZN4CP1527FlushAndInvalidateDataCacheEjj((unsigned int)data_020a8160, 0x20);

    *(short *)((char *)base + 0x10) = 0;
    *(short *)((char *)base + 0xd4) = 0;
    base[0xe] = 4;           /* field_38 */

    v38 = base[0xe];
    func_02058200(&data_020a81bc, (void *)func_020602bc, 0, &data_020a8760, 0x400, v38);
    func_02058048(&data_020a81bc);
    func_0205ba64(0xb, (void *)func_02060310);
}
