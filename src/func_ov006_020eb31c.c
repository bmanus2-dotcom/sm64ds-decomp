//cpp
// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Sound { static void PlayBank2_2D(unsigned int); };
struct C;
typedef void (C::*PMF)();
struct C {
    char pad10[0x10];
    PMF pmf;        // 0x10
};

extern "C" void func_ov006_020eb31c(char* c)
{
    short* t = (short*)(c+0x90);
    short v = (short)(*t - 1);
    *t = v;
    if (*(short*)(c+0x90) == 0) {
        *(unsigned char*)(c+0x94) = 0;
        *(unsigned char*)(c+0x93) = 1;
        *(int*)(c+0x44) = 0x1000;
        *(short*)(c+0x86) = 0x900;
        *(unsigned char*)(c+0x95) = 4;
        *(short*)(c+0x8e) = 0x78;
        *(int*)c = *(int*)(c+0x10);
        *(int*)(c+4) = *(int*)(c+0x14);
        return;
    }
    C* o = (C*)c;
    (o->*(o->pmf))();
    if (*(short*)(c+0x90) != 0x30) return;
    if (*(int*)(c+0x70) == 0)
        Sound::PlayBank2_2D(0x1ea);
    *(unsigned char*)(c+0x95) = 3;
}
