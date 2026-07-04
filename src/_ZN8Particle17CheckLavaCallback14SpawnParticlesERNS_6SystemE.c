//cpp
// NONMATCHING: different op / idiom (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; Vector3(int a,int b,int c):x(a),y(b),z(c){} Vector3(){} };
struct Actor;

struct RaycastGround {
    char pad[0x50];
    RaycastGround();
    ~RaycastGround();
    void SetObjAndPos(const Vector3 &pos, Actor *obj);
    int DetectClsn();
};

struct Node {
    Node *next;
    char p4[4];
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    char p20[0x2c - 0x20];
    unsigned short f2c;
    unsigned short f2e;
};

struct System;

extern "C" int func_02037e38(unsigned int *p);

namespace Particle {
struct System {};
struct SimpleCallback { void SpawnParticles(System &sys); };
struct CheckLavaCallback : SimpleCallback { void SpawnParticles(System &sys); };

void CheckLavaCallback::SpawnParticles(System &sys)
{
    SimpleCallback::SpawnParticles(sys);

    Node *n = *(Node **)((char *)&sys + 8);
    while (n != 0) {
        int sx = n->f14 + n->f8;
        int sy = n->f18 + n->fc;
        int sz = n->f1c + n->f10;
        RaycastGround rg;
        Vector3 v(sx << 3, (sy << 3) + 0x12c000, sz << 3);
        rg.SetObjAndPos(v, 0);
        if (rg.DetectClsn() != 0) {
            if (func_02037e38((unsigned int *)((char *)&rg + 0x14)) != 1) {
                n->f2e = n->f2c;
            } else {
                n->f18 = (*(int *)((char *)&rg + 0x44) + 0x7000 >> 3) - n->fc;
            }
        }
        n = n->next;
    }
}
}
