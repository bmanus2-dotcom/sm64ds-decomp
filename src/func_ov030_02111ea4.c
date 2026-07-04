//cpp
// NONMATCHING: different op / idiom (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
struct Actor;

struct RaycastGround {
    char pad[0x54];
};
extern "C" int _ZNK12WithMeshClsn10IsOnGroundEv(void*);
extern "C" void _ZN13RaycastGroundC1Ev(RaycastGround*);
extern "C" void _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(RaycastGround*, const Vector3&, Actor*);
extern "C" int _ZN13RaycastGround10DetectClsnEv(RaycastGround*);
extern "C" void _ZN13RaycastGroundD1Ev(RaycastGround*);

extern "C" int func_ov030_02111ea4(char* thiz)
{
    char* c = thiz;
    if (_ZNK12WithMeshClsn10IsOnGroundEv(c + 0x194) != 0) {
        RaycastGround rg;
        Vector3 pos;
        _ZN13RaycastGroundC1Ev(&rg);
        {
            int y = *(int*)(c + 0x60);
            int z = *(int*)(c + 0x64);
            int x = *(int*)(c + 0x5c);
            pos.x = x;
            pos.y = y + 0x1e000;
            pos.z = z;
        }
        _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(&rg, pos, (Actor*)c);
        if (_ZN13RaycastGround10DetectClsnEv(&rg) != 0) {
            int d = *(int*)((char*)&rg + 0x44) - *(int*)(c + 0x60);
            if (d < 0) d = -d;
            if (d > 0x1000) {
                *(int*)(c + 0x98) = 0;
                *(int*)(c + 0x5c) = *(int*)(c + 0x68);
                *(int*)(c + 0x60) = *(int*)(c + 0x6c);
                *(int*)(c + 0x64) = *(int*)(c + 0x70);
            }
            _ZN13RaycastGroundD1Ev(&rg);
            return 1;
        }
        _ZN13RaycastGroundD1Ev(&rg);
    }
    return 0;
}
