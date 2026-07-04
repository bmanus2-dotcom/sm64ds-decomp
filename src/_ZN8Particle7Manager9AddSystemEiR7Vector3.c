//cpp
// NONMATCHING: different op / idiom (div=30). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Vector3 { int x, y, z; };

extern "C" {
void *func_0204d958(void *p);
void func_0204ae2c(void *p, Vector3 *v);
void func_0204d9a0(void *a, void *b);
}

struct Mgr {
    char pad0[0xc];
    int u0c;        /* 0xc */
    char pad1[0x1c - 0x10];
    int *u1c;       /* 0x1c */
    char pad2[0x2c - 0x20];
    u16 u2c;        /* 0x2c */
    u16 u2e;        /* 0x2e */
};

namespace Particle {
struct Manager {
    int AddSystem(int idx, Vector3 &v);
};

int Manager::AddSystem(int idx, Vector3 &v) {
    Mgr *self = (Mgr*)this;
    int r4 = 0;
    if (self->u0c != 0) {
        void *sys = func_0204d958(&self->u0c);
        r4 = (int)sys;
        func_0204ae2c((char*)self->u1c + idx * 0x20, &v);
        {
            u32 *p = (u32*)((char*)sys + 0x74);
            *p = (*p & ~0x3fu) | (self->u2c & 0x3f);
            *p = (*p & ~0xfc0u) | ((self->u2e & 0x3f) << 6);
            u32 lo = (*((u32*)sys + 0x74/4) << 0x1a) >> 0x1a;
            *p = (*p & ~0x3f000u) | ((lo & 0x3f) << 12);
            *p = *p & 0x3ffff;
        }
        func_0204d9a0((char*)self + 4, sys);
        if (((**(u32**)((char*)sys + 0x18)) << 0x11) >> 0x1f) r4 = 0;
    }
    return r4;
}
}
