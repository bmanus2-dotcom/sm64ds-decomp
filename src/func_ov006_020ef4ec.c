//cpp
// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
void func_ov006_020c42bc(void);
void func_ov006_020c712c(void);
int _Z15ApproachLinear2Rsss(short *, short, short);
void func_ov006_020c7388(void);
void func_ov006_020c40e8(void);
struct G2 { int w[2]; };
extern struct G2 data_ov006_0213cc8c;
void func_ov006_020ef4ec(char *c)
{
    int *p = (int *)(c + 0x5a64);
    char *b = c + 0x5000;
    *p = *p + (*(int *)(b + 0xa68) >> 12);
    if (*(int *)(b + 0xa64) > 0x1000)
        *p = *p - 0x1000;
    func_ov006_020c42bc();
    func_ov006_020c712c();
    if (_Z15ApproachLinear2Rsss((short *)(c + 0x5a74), 0, 1) == 0)
        return;
    func_ov006_020c7388();
    func_ov006_020c40e8();
    *(struct G2 *)(c + 0x5004) = data_ov006_0213cc8c;
}
}
