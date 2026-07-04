//cpp
// NONMATCHING: different op / idiom (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C;
typedef void (C::*PMF)();
struct C {
    PMF pmf;
};
extern "C" void _ZN14BlendModelAnim7AdvanceEv(void* x);
extern "C" int _Z15ApproachLinear2Rsss(short& v, short a, short b);
extern "C" void func_ov006_020c07e8(void* x);
extern short data_ov006_0212b89c[];

extern "C" void func_ov006_020c19d0(char* thiz)
{
    char* c = thiz;
    C* o = (C*)c;
    if (*(int*)c != 0) {
        (o->*(o->pmf))();
    }
    _ZN14BlendModelAnim7AdvanceEv(c + 0x1c);
    if (_Z15ApproachLinear2Rsss(*(short*)(c + 0x1e0), 0, 1) != 0) {
        short* p = (short*)(c + 0x1e2);
        *p = *p + 1;
        if (*(short*)(c + 0x1e2) > 7)
            *(short*)(c + 0x1e2) = 1;
        *(short*)(c + 0x1e0) = data_ov006_0212b89c[*(short*)(c + 0x1e2)];
    }
    *(short*)(c + 0x1e4) += 0x400;
    func_ov006_020c07e8(c + 0xdc);
}
