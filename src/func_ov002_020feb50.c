//cpp
// NONMATCHING: missing logic (ROM does more) (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

struct Vector3 { int x, y, z; };

extern "C" char* _ZN5Actor10FindWithIDEj(unsigned int id);
extern "C" void _ZN5Sound4PlayEjjRK7Vector3(unsigned int a, unsigned int b, Vector3 const & v);
extern "C" void _ZN5Actor13SmallPoofDustEv(char* self);
extern "C" void func_02012694(unsigned int a, Vector3 const & v);
extern "C" void _ZN9ActorBase18MarkForDestructionEv(char* self);
extern "C" void _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(char* self, Vector3 const & v, unsigned int a, int b, unsigned int c, unsigned int d, unsigned int e);

extern "C" void func_ov002_020feb50(char* self) {
    char* a;
    int b;
    int flags;
    Vector3 v;

    if (*(s32*)(self + 0x134) == 0) {
        return;
    }
    a = _ZN5Actor10FindWithIDEj(*(s32*)(self + 0x134));
    if (a == 0) {
        return;
    }
    b = (*(u16*)(a + 0xc) == 0xbf);
    if (b == 0) {
        return;
    }
    if (*(u8*)(a + 0x6fb) != 0) {
        return;
    }
    if (*(u8*)(a + 0x6f9) != 0) {
        *(s32*)(self + 0x354) = 1;
        _ZN5Sound4PlayEjjRK7Vector3(0, 0xa5, *(Vector3*)(self + 0x74));
        *(s16*)(self + 0x94) = *(s16*)(self + 0x94) - 0x8000;
        *(s32*)(self + 0xa4) = 0;
        *(s32*)(self + 0xa8) = 0x1e000;
        *(s32*)(self + 0xac) = 0;
        *(s32*)(self + 0x9c) = -0x4000;
        return;
    }
    flags = *(s32*)(self + 0x130);
    _ZN5Actor13SmallPoofDustEv(self);
    func_02012694(0x166, *(Vector3*)(self + 0x74));
    _ZN9ActorBase18MarkForDestructionEv(self);
    if ((flags & 0x10) != 0) {
        return;
    }
    v.x = *(s32*)(self + 0x5c);
    v.y = *(s32*)(self + 0x60);
    v.z = *(s32*)(self + 0x64);
    _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(a, v, 1, 0xc000, 1, 0, 1);
}
