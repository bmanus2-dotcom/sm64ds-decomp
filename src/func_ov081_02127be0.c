//cpp
// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
struct Vector3_16 { unsigned short x, y, z; };
struct ActorBase { void MarkForDestruction(); };
struct Actor {
    static Actor* Spawn(unsigned int a, unsigned int b, const Vector3& v, const Vector3_16* v16, int e, int f);
};

extern "C" void func_ov081_02127be0(char* c)
{
    char* o = *(char**)(c + 0x364);
    if (o == 0) return;
    if (*(unsigned short*)(o + 0xc) != 0xb2) return;

    Vector3 pos;
    Vector3* src = (Vector3*)(o + 0x5c);
    unsigned int flags = *(unsigned int*)(o + 8);
    pos.x = src->x;
    pos.y = src->y;
    pos.z = src->z;

    char* o2 = *(char**)(c + 0x364);
    Vector3_16 rot;
    rot = *(Vector3_16*)(o2 + 0x8c);

    ((ActorBase*)*(char**)(c + 0x364))->MarkForDestruction();

    unsigned int newflags = (unsigned char)(flags & 0xf) | 0x20;
    Actor::Spawn(0xb4, newflags, pos, &rot, *(signed char*)(c + 0xcc), -1);
    *(char**)(c + 0x364) = (char*)Actor::Spawn(0xb2, newflags, pos, &rot, *(signed char*)(c + 0xcc), -1);
    int* fl = (int*)(c + 0xb0);
    *fl |= 0x4000000;
}
