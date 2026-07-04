//cpp
// NONMATCHING: different op / idiom (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(char *anim, void *file, int a, int b, unsigned int u);
struct G2 { int w[2]; };
extern int data_ov006_021405c8;
extern struct G2 data_ov006_02140564;
extern struct G2 data_ov006_0213b184;
extern int data_ov006_0214058c;
extern struct G2 data_ov006_0213b12c;

extern "C" void func_ov006_020cc9fc(char *c)
{
    *(int *)(c + 0x40) = 0;
    *(int *)(c + 0x20) = data_ov006_021405c8;
    *(int *)(c + 0x24) = 0;
    *(int *)(c + 0x28) = *(int *)(c + 0x1c);
    *(int *)(c + 0x2c) = *(int *)(c + 0x20);
    *(int *)(c + 0x30) = *(int *)(c + 0x24);
    *(int *)(c + 0x34) = 0x1800;
    *(int *)(c + 0x38) = 0;
    *(int *)(c + 0x3c) = 0;
    *(short *)(c + 0x4a) = 0x4000;
    _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c + 0x6c, (void *)data_ov006_02140564.w[0], 0, 0x800, 0);
    int *s = (int *)(c + 0x64);
    struct G2 *d = &data_ov006_0213b184;
    if (s[0] == d->w[0] && (s[1] == d->w[1] || *(int *)(c + 0x64) == 0)) return;
    data_ov006_0214058c += 1;
    *(int *)(c + 0x64) = data_ov006_0213b12c.w[0];
    *(int *)(c + 0x68) = data_ov006_0213b12c.w[1];
}
