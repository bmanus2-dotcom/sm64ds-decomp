//cpp
// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C;
typedef void (C::*PMF)();

extern "C" void func_ov075_0211a194(char* self, int* src)
{
    *(int*)(self + 0x54) = src[0];
    *(int*)(self + 0x58) = src[1];
    *(int*)(self + 0x5c) = src[2];
    *(int*)(self + 0x60) = src[3];
    *(int*)(self + 0x64) = src[4];
    *(int*)(self + 0x68) = src[5];
    {
        PMF* p = (PMF*)(self + 0x54);
        C* o = (C*)self;
        if (*(int*)(self + 0x54) != 0)
            (o->**p)();
    }
}
