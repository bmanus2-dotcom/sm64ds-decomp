// NONMATCHING: different op / idiom (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(char *anim, void *file, int a, int b, unsigned int u);

struct G2 { int w[2]; };
extern struct G2 data_ov006_0213b204;
extern struct G2 data_ov006_0213b21c;
extern int data_ov006_021405c8[];
extern int data_ov006_0214057c;
extern int data_ov006_02140564;
extern int data_ov006_0214055c;

void func_ov006_020cc8c8(char *p) {
    int *cur = (int *)(p + 0x64);
    struct G2 *want = &data_ov006_0213b204;
    *(int *)(p + 0x40) = 0;
    *(int *)(p + 0x20) = data_ov006_021405c8[*(short *)(p + 0x52)];
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3c) = 0;
    if (cur[0] == want->w[0] && (cur[1] == want->w[1] || *(int *)(p + 0x64) == 0)) {
        _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(p + 0x6c, (void *)data_ov006_0214057c, 0x40000000, 0x800, 0);
    } else {
        _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(p + 0x6c, (void *)data_ov006_02140564, 0, 0x800, 0);
        struct G2 *src = &data_ov006_0213b21c;
        data_ov006_0214055c += 1;
        *(int *)(p + 0x64) = src->w[0];
        *(int *)(p + 0x68) = src->w[1];
    }
}
