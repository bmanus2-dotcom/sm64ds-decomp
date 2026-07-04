//cpp
// NONMATCHING: different op / idiom (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
char* _ZN5Actor13ClosestPlayerEv(void);
void func_ov002_020c3f18(void);
void _Z14ApproachLinearRsss(short&, short, short);
void func_ov085_0212e728(char* c, void* p);
extern char data_ov085_021307c0[];

int func_ov085_0212dd10(char* c)
{
    char* p = _ZN5Actor13ClosestPlayerEv();
    if (!p) return 1;
    short v = *(short*)(c + 0x8e);
    *(short*)(p + 0x8c) = 0;
    *(short*)(p + 0x8e) = v + 0x8000;
    *(short*)(p + 0x90) = 0;
    *(int*)(c + 0x2c8) += 1;
    if (*(int*)(c + 0x2c8) == 0x5a) func_ov002_020c3f18();
    {
        int s = *(int*)(c + 0x2c8);
        if (s > 0x57 && s < 0x5b)
            _Z14ApproachLinearRsss(*(short*)(c + 0x8c), 0x2000, 0x400);
        else
            _Z14ApproachLinearRsss(*(short*)(c + 0x8c), 0x1000, 0x400);
    }
    if (*(int*)(c + 0x2c8) > 0x78)
        func_ov085_0212e728(c, data_ov085_021307c0);
    return 1;
}
}
