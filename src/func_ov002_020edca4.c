// NONMATCHING: missing logic (ROM does more) (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned int u32;

struct Actor;
struct Vector3 { int x, y, z; };

extern void func_ov002_020ec728(char* c);
extern int func_ov002_020ec610(unsigned char* p);
extern void _ZN5Actor11UntrackStarERa(struct Actor* self, signed char* r);
extern struct Actor* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(u32 a, u32 b, const struct Vector3* pos, const void* v, int e, int f);
extern void func_ov002_020e7218(struct Actor* a, char* c, int x);
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(u32 a, int b, int c, int d);
extern void _ZN9ActorBase18MarkForDestructionEv(struct Actor* self);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(u32 a, u32 b, const struct Vector3* pos);

void func_ov002_020edca4(char* self)
{
    struct Vector3 pos;
    struct Actor* spawned;
    int xv, zv, yv;

    if (*(u8*)(self + 0x426) != 0) return;

    func_ov002_020ec728(self);

    yv = *(int*)(self + 0x60);
    zv = *(int*)(self + 0x64);
    xv = *(int*)(self + 0x5c);
    pos.y = yv + 0x28000;
    pos.x = xv;
    pos.z = zv;
    if (func_ov002_020ec610((unsigned char*)self) == 0) goto done;

    _ZN5Actor11UntrackStarERa((struct Actor*)self, (signed char*)(self + 0x427));

    spawned = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0xb3, 0x10,
        &pos, 0, *(signed char*)(*(char**)(self + 0x38c) + 0xcc), -1);
    if (spawned == 0) goto done;

    func_ov002_020e7218((struct Actor*)*(char**)(self + 0x38c), self, 1);
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x3f, *(int*)(self + 0x5c), *(int*)(self + 0x60), *(int*)(self + 0x64));
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x40, *(int*)(self + 0x5c), *(int*)(self + 0x60), *(int*)(self + 0x64));
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x41, *(int*)(self + 0x5c), *(int*)(self + 0x60), *(int*)(self + 0x64));
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x42, *(int*)(self + 0x5c), *(int*)(self + 0x60), *(int*)(self + 0x64));
    _ZN9ActorBase18MarkForDestructionEv((struct Actor*)self);
    _ZN5Sound13PlayCharVoiceEjjRK7Vector3(0, 0x103, (const struct Vector3*)(self + 0x74));

done:
    *(u8*)(self + 0x426) = 1;
}
