//cpp
// NONMATCHING: register allocation (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
struct Vector3_16 { short x, y, z; };

struct Actor {
    char pad[0x92];
    short f92;   /* 0x92 */
    short f94;   /* 0x94 */
    short f96;   /* 0x96 */
};

extern "C" {
extern void* _ZN5Actor13ClosestPlayerEv(void);
extern short Vec3_HorzAngle(const Vector3* a, const Vector3* b);
extern void* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int a, unsigned int b, const Vector3& v, const Vector3_16* p, int e, int f);
extern void _ZN9ActorBase18MarkForDestructionEv(void* a);
}

extern "C" void func_ov060_021167ec(char* c)
{
    char* p;
    if (*(unsigned short*)(c + 0x374) != 0) return;
    p = (char*)_ZN5Actor13ClosestPlayerEv();
    if (p == 0) return;
    *(short*)(c + 0x94) = Vec3_HorzAngle((Vector3*)(c + 0x5c), (Vector3*)(p + 0x5c));
    *(int*)(c + 0x360) = 0x5000;
    {
        int i = 0;
        int ang = 0;
        do {
            Actor* a = (Actor*)_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0x118, 4, *(Vector3*)(c + 0x5c), (const Vector3_16*)0, *(signed char*)(c + 0xcc), -1);
            short v = *(short*)(c + 0x94) + ang;
            a->f92 = 0;
            a->f94 = v;
            a->f96 = 0;
            *(int*)((char*)a + 0x360) = *(int*)(c + 0x360);
            i++;
            ang += 0x5555;
        } while (i < 3);
    }
    _ZN9ActorBase18MarkForDestructionEv(c);
}
