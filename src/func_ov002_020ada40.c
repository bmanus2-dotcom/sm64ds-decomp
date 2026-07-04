//cpp
// NONMATCHING: different op / idiom (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
typedef struct Vector3 { int x,y,z; } Vector3;
short Vec3_HorzAngle(const Vector3* a, const Vector3* b);
void _ZN5Sound9PlayBank0EjRK7Vector3(unsigned int a, const Vector3* b);
void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int a, int x, int y, int z);
void _ZN6Player16IncMegaKillCountEv(void* p);

struct Player3 {
    char pad5c[0x5c];
    Vector3 pos;
    char pad68[0x94-0x68];
    short ang;
    char pad96[0x98-0x96];
    int f98, f9c, fa0;
    char pada4[0xa8-0xa4];
    int fa8;
    char padac[0xb0-0xac];
    int fb0;
    char padb4[0xec-0xb4];
    short fec, fee, ff0;
    char padf2[0x102-0xf2];
    short f102;
    char pad104[0x10c-0x104];
    int f10c;
};

void func_ov002_020ada40(Player3* r0, short* r1, void* r2) {
    r0->fb0 &= ~0x10000001;
    r0->ang = Vec3_HorzAngle(&r0->pos, (const Vector3*)((char*)r2+0x5c));
    r0->f98 = 0xa000;
    r0->fa8 = 0x28000;
    r0->f102 = 0x1e;
    r0->fec = r1[0];
    r0->fee = r1[1];
    r0->ff0 = r1[2];
    r0->f10c = 8;
    r0->f9c = -0x2000;
    r0->fa0 = -0x32000;
    _ZN5Sound9PlayBank0EjRK7Vector3(9, (const Vector3*)((char*)r0+0x74));
    volatile Vector3 v;
    v.x = r0->pos.x;
    v.y = r0->pos.y;
    v.z = r0->pos.z;
    int ret = (*(int(**)(void*))(*(int*)r0 + 0x74))(r0);
    v.y = v.y + ret;
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x43, v.x, v.y, v.z);
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x44, v.x, v.y, v.z);
    _ZN6Player16IncMegaKillCountEv(r2);
}
}
