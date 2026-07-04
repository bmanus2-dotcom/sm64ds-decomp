// NONMATCHING: different op / idiom (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
typedef int Fix12i;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

extern u32 _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    u32 a, u32 b, Fix12i x, Fix12i y, Fix12i z, void* rot, void* cb);

void func_ov002_020e7f2c(char* c)
{
    Fix12i x, y, z;
    u16* base = (u16*)(c + 0x400);
    if (base[0x94/2] == 0)
        return;
    (*(u16*)(c + 0x494))--;
    if (base[0x94/2] == 0)
        *(u32*)(c + 0x4bc) = 0;
    x = *(Fix12i*)(c + 0x5c);
    y = *(Fix12i*)(c + 0x60);
    z = *(Fix12i*)(c + 0x64);
    y = y + 0xd000;
    *(u32*)(c + 0x4bc) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
        *(u32*)(c + 0x4bc),
        0x114,
        x, y, z,
        0, 0);
}
