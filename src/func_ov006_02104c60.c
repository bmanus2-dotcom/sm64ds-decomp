//cpp
// NONMATCHING: different op / idiom (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
struct C;
typedef void (C::*PMF)();
extern "C" {
void func_ov006_02104c60(char *c);
}
extern PMF data_ov006_021427ec[];
void func_ov006_02104c60(char *c)
{
    char *r3 = c + 0x4000;
    if (*(u8*)(r3 + 0x684) == 0) return;
    char *r2 = c + 0x4600;
    unsigned short *ip = (unsigned short*)(c + 0x4680);
    *ip = *ip - 1;
    if (*(short*)(r2 + 0x80) <= 0) {
        *(short*)(r2 + 0x80) = 0;
        *(u8*)(r3 + 0x684) = 0;
        *(u8*)(r3 + 0x685) = 0;
        return;
    }
    C *cc = (C*)c;
    (cc->*data_ov006_021427ec[*(u8*)(r3 + 0x686)])();
}
