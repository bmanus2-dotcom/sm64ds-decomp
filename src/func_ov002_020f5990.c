//cpp
// NONMATCHING: different op / idiom (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int s32;
typedef short s16;
typedef unsigned char u8;
struct C;
typedef void (C::*PMF)(int);

extern "C" void func_ov002_020f39ec(char* c, int i);
extern "C" void func_ov002_020f2790(char* c, int p1, int p2, int p3, s16 p4);
extern PMF data_ov002_02110e7c[];

struct Sub {
    int f0;
    int f4;
    char pad8[0x28 - 8];
    int f28;
    s16 f2c;
    char pad2e[0x44 - 0x2e];
    u8 f44;
    u8 pad45;
    u8 f46;
    char pad47[0x49 - 0x47];
    u8 f49;
};

extern "C" void func_ov002_020f5990(char* c);
void func_ov002_020f5990(char* c)
{
    C* self = (C*)c;
    Sub* s = (Sub*)c;
    int i;
    {
        int* cnt = (int*)(c + 0x1f8);
        *cnt = *cnt + 1;
        *cnt = *cnt & 3;
    }
    for (i = 0; i < 4; i++, s = (Sub*)((char*)s + 0x4c)) {
        if (s->f44 == 0) continue;
        (self->*data_ov002_02110e7c[s->f46])(i);
        func_ov002_020f39ec(c, i);
        if (s->f49 == 0) continue;
        if (i != *(int*)(c + 0x1f8)) continue;
        func_ov002_020f2790(c, (s->f0 << 4) >> 0x10, (s->f4 << 4) >> 0x10, s->f28, s->f2c);
    }
}
