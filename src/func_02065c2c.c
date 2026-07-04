// NONMATCHING: base materialization / addressing (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0205a61c(const void *src, void *dst, unsigned int size);
extern char *data_020a9db8[];

unsigned char *func_02065c2c(unsigned char *r0, unsigned char *r1)
{
    unsigned char *r4;
    unsigned short *p;
    r1[0] = r0[0];
    switch (r1[0]) {
    case 7:
        r4 = r0 + 2;
        r1[2] = r0[1];
        if (r1[2] > *(int *)(data_020a9db8[0] + 0x1320)) return 0;
        func_0205a61c(r4, r1 + 3, *(int *)(data_020a9db8[0] + 0x131c));
        r4 = r4 + *(int *)(data_020a9db8[0] + 0x131c);
        break;
    case 8:
        r4 = r0 + 3;
        p = (unsigned short *)(r1 + 2);
        *p = r0[1];
        *p = *p | ((r0[2] << 8) & 0xff00);
        break;
    case 9:
        p = (unsigned short *)(r1 + 2);
        *p = r0[1];
        r4 = r0 + 3;
        *p = *p | ((r0[2] << 8) & 0xff00);
        func_0205a61c(r4, r1 + 4, *(int *)(data_020a9db8[0] + 0x131c));
        r4 = r4 + *(int *)(data_020a9db8[0] + 0x131c);
        break;
    default:
        return 0;
    }
    return r4;
}
