// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct State;
extern void func_ov002_020bda48(char* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* thiz, struct State* s);
extern void func_ov002_020bd9ec(char* c, u32 a);
extern void func_ov002_020c43c4(char* c, int a);
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(u32 id, int x, int y, int z);
extern void _ZN5Sound9PlayBank0EjRK7Vector3(u32 id, void* pos);

extern struct State data_ov002_0211028c;

void _ZN6Player16InitBalloonMarioEv(char* thiz)
{
    volatile int x, y, z;

    if (*(u8*)(thiz + 0x6fd) != 0) return;

    func_ov002_020bda48(thiz);
    *(u8*)(thiz + 0x6fd) = 1;
    *(s16*)(thiz + 0x6c0) = 0x258;
    _ZN6Player11ChangeStateERNS_5StateE(thiz, &data_ov002_0211028c);
    func_ov002_020bd9ec(thiz, 0x30);
    func_ov002_020c43c4(thiz, 2);

    x = *(int*)(thiz + 0x5c);
    y = *(int*)(thiz + 0x60);
    z = *(int*)(thiz + 0x64);
    y = *(int*)(thiz + 0x60) + 0x50000;
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0xc5, x, y, z);
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0xc6, x, y, z);

    _ZN5Sound9PlayBank0EjRK7Vector3(0xd7, thiz + 0x74);
}
