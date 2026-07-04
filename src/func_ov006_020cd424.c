// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_ov006_020cd510(int sz);
extern void func_ov006_020cd62c(int n);
extern void func_ov006_020ccd78(char *c);
extern void func_ov006_020cafdc(char *o);
extern void func_ov006_020c8a9c(int a0, int a1);

extern int data_ov006_02140594;
extern int data_ov006_0213b0ec;
extern int data_ov006_02140588;
extern int data_ov006_0214058c;
extern int data_ov006_0214055c;
extern char *data_ov006_02140550;

void func_ov006_020cd424(unsigned int n, int arg1)
{
    int i;
    int r = n - n / 10 * 5;
    func_ov006_020cd510((r + n / 10) * 0x150 + 0x1000);
    func_ov006_020cd62c(arg1);
    data_ov006_0213b0ec = 3;
    data_ov006_02140588 = 0;
    data_ov006_0214058c = 0;
    data_ov006_0214055c = 0;
    for (i = 0; i < data_ov006_02140594; i++) {
        func_ov006_020ccd78(data_ov006_02140550 + i * 0xd0);
        func_ov006_020cafdc(data_ov006_02140550 + i * 0xd0);
    }
    func_ov006_020c8a9c(0, 0);
}
