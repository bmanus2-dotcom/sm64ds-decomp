//cpp
// NONMATCHING: different op / idiom (div=35). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Actor { static Actor* FindWithID(unsigned int); };
extern "C" void func_02035860(void*, void*);
extern "C" void func_ov002_020e9464(char* p);

extern "C" void func_ov002_020e7454(char* self);
void func_ov002_020e7454(char* self) {
    char* a = (char*)Actor::FindWithID(*(unsigned int*)(self + 0x434));
    { unsigned short* f = (unsigned short*)(self + 0x4a2); *f &= ~0x30; }
    *(int*)(self + 0x5c) = *(int*)(a + 0x5c);
    *(int*)(self + 0x60) = *(int*)(a + 0x60);
    *(int*)(self + 0x64) = *(int*)(a + 0x64);
    func_02035860(self + 0x150, self + 0x5c);
    if (*(unsigned char*)(a + 0x1d8) == 3) {
        *(int*)(self + 0x444) = *(unsigned char*)(a + 0x1da);
        *(int*)(self + 0x440) = *(int*)(self + 0x444);
        if (*(int*)(self + 0x440) != 4) return;
        func_ov002_020e9464(self);
    } else {
        unsigned char* q = (unsigned char*)a + 0x1db;
        *q &= ~1;
        *q |= 2;
        *(int*)(self + 0x440) = 9;
        *(int*)(self + 0x128) |= 1;
        { unsigned short* f = (unsigned short*)(self + 0x4a2); *f &= ~2; *f |= 8; }
    }
}
