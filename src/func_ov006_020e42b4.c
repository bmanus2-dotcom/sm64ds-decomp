//cpp
// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C;
typedef void (C::*PMF)(int);
extern PMF data_ov006_021419f8[];
extern PMF data_ov006_021419a0[];
extern "C" void func_ov006_020e42b4(char *c, int i)
{
    int idx = i * 0x24;
    C *self = (C *)c;
    unsigned char k0 = *(unsigned char *)(c + idx + 0x4000 + 0x8de);
    (self->*data_ov006_021419f8[k0])(i);
    {
        unsigned char k1 = *(unsigned char *)(c + idx + 0x4000 + 0x8df);
        (self->*data_ov006_021419a0[k1])(i);
    }
}
