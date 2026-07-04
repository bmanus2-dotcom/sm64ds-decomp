//cpp
// NONMATCHING: missing logic (ROM does more) (div=47). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
typedef unsigned int u32;

struct Vector3 { int x, y, z; };

extern "C" void* func_02010304(void* a, void* b);
extern "C" void func_ov080_0212513c(void* c, int n);

struct Actor {
    static Actor* FindWithID(u32 id);
    void PoofDustAt(const Vector3&);
    void SpawnCoins(const Vector3&, u32, int, short);
};
struct Player { static void IncMegaKillCount(); };
namespace Particle { struct System { static void* NewSimple(u32, int, int, int); }; }
struct Sound { static void PlayBank3(u32, const Vector3&); };
struct ActorBase { void MarkForDestruction(); };

extern "C" void func_ov080_02124acc(char* c)
{
    if (*(int*)(c + 0x170) == 0)
        return;

    void* p = func_02010304(c, c + 0x14c);
    if (p != 0) {
        *(void**)(c + 0x374) = p;
        func_ov080_0212513c(c, 1);
        return;
    }

    Actor* a = Actor::FindWithID(*(u32*)(c + 0x170));
    if (a == 0)
        return;

    int b1 = (int)(*(u16*)((char*)a + 0xc) == 0xbf);
    if (b1 == 0)
        return;

    int b2 = (int)((*(u32*)(c + 0xb0) & 0x20000) != 0);
    if (b2) {
        func_ov080_0212513c(c, 2);
        return;
    }
    if ((*(u32*)(c + 0x16c) & 0x10) == 0)
        return;

    Player::IncMegaKillCount();

    Vector3 v;
    v.x = *(int*)(c + 0x5c);
    v.y = *(int*)(c + 0x60) + 0x32000;
    v.z = *(int*)(c + 0x64);
    Particle::System::NewSimple(6, v.x, v.y, v.z);

    Vector3 v2 = v;
    ((Actor*)c)->PoofDustAt(v2);

    Vector3 v3;
    v3.x = v.x;
    v.y = *(int*)(c + 0x60) + 0x64000;
    v3.y = v.y;
    v3.z = v.z;
    ((Actor*)c)->SpawnCoins(v3, 5, 0xf000, 0);

    Sound::PlayBank3(0x41, *(Vector3*)(c + 0x74));

    ((ActorBase*)c)->MarkForDestruction();
}
