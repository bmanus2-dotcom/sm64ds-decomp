//cpp
// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C;
typedef void (C::*PMF)();
extern "C" {
extern PMF data_ov006_021416e0[];
void func_ov006_020d5d08(char *c);
void func_ov006_020d5b10(char *c);
int func_ov006_020d91b0(char *c)
{
    if (*(unsigned short *)(c + 0x6200 + 0xf0) != 0) {
        unsigned short *t = (unsigned short *)(c + 0x62f0);
        *t = *t - 1;
        if (*(short *)(c + 0x6200 + 0xf0) <= 0)
            *(short *)(c + 0x6200 + 0xf0) = 0;
    } else {
        (((C *)c)->*data_ov006_021416e0[*(int *)(c + 0x6000 + 0x2d0)])();
    }
    func_ov006_020d5d08(c);
    func_ov006_020d5b10(c);
    return 1;
}
}
