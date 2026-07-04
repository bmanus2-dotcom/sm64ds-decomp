// NONMATCHING: different op / idiom (div=36). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0203cd80(int* m, int angle);
extern void func_0203ccd4(int* m, short angle);
extern void func_ov006_020c8e90(char* o);
extern void func_ov006_020c8a30(void);

extern int data_ov006_021405bc;
extern char* data_ov006_02140554;

void func_ov006_020caadc(void)
{
    int v[3];
    int w[3];
    int i;

    v[0] = 0;
    v[1] = 0;
    v[2] = 0xfffff008;
    func_0203cd80(v, -0x2000);
    func_0203ccd4(v, -0x3000);
    *(int*)0x40004c8 =
        (((v[0] << 16) >> 19) & 0x3ff) |
        ((((v[1] << 16) >> 19) & 0x3ff) << 10) |
        ((((v[2] << 16) >> 19) & 0x3ff) << 20);

    w[0] = 0;
    w[1] = 0;
    w[2] = 0xfffff008;
    func_0203cd80(w, -0x2000);
    *(int*)0x40004c8 =
        ((((w[0] << 16) >> 19) & 0x3ff) |
        ((((w[1] << 16) >> 19) & 0x3ff) << 10) |
        ((((w[2] << 16) >> 19) & 0x3ff) << 20)) | 0x40000000;
    *(int*)0x40004cc = 0x7fff;
    *(int*)0x40004cc = 0x40007fff;

    for (i = 0; i < data_ov006_021405bc; i++) {
        func_ov006_020c8e90(data_ov006_02140554 + i * 0xdc);
    }
    func_ov006_020c8a30();
}
