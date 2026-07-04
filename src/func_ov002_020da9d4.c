//cpp
// NONMATCHING: base materialization / addressing (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" void func_ov002_020db54c(void* s, int a, int b, int c);

extern "C" int func_ov002_020da9d4(char* self){
    char* s = *(char**)(self + 0x358);
    int b = (s != 0);
    int* p;
    if (!b)
        return 0;
    {
        int e = (*(unsigned short*)(s + 0xc) == 0xbf);
        if (e)
            func_ov002_020db54c(s, 0x10000, 0x10000, *(short*)(self + 0x8e));
    }
    p = (int*)(*(char**)(self + 0x358) + 0xb0);
    *p &= ~0x4000;
    p = (int*)(*(char**)(self + 0x358) + 0xb0);
    *p |= 0x2000;
    p = (int*)(*(char**)(self + 0x358) + 0xb0);
    *p &= ~0x100;
    *(char**)(self + 0x358) = 0;
    return 1;
}
