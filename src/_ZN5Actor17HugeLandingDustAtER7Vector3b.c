//cpp
// NONMATCHING: base materialization / addressing (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12i;
struct Vector3 { Fix12i x, y, z; };
struct Actor;
struct RaycastGround {
    char buf[0x50];
    RaycastGround();
    ~RaycastGround();
    void SetObjAndPos(const Vector3 &pos, Actor *actor);
    int DetectClsn();
};
namespace Particle { struct System {
    static void NewSimple(unsigned int id, Fix12i a, Fix12i b, Fix12i c);
}; }

extern "C" void _ZN5Actor17HugeLandingDustAtER7Vector3b(Actor *self, Vector3 *pos, bool b)
{
    if (b) {
        RaycastGround rc;
        pos->y += 0x32000;
        rc.SetObjAndPos(*pos, 0);
        if (rc.DetectClsn())
            pos->y = *(Fix12i*)((char*)&rc + 0x44);
    }
    pos->y += 0x28000;
    Particle::System::NewSimple(0xb2, pos->x, pos->y, pos->z);
}
