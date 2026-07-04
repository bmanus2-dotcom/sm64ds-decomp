//cpp
// NONMATCHING: different op / idiom (div=27). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
struct Actor;
struct ClsnResult { char data[0x34]; };

struct RaycastGround {
    char pad0[0x10];
    ClsnResult clsn;   /* 0x10 */
    int field44;       /* 0x44 */
    char pad48[0x50 - 0x48];
    RaycastGround();
    ~RaycastGround();
    void SetObjAndPos(const Vector3& pos, Actor* a);
    int DetectClsn();
};

struct WithMeshClsn { void SetGroundFlag(); };

extern "C" bool _ZN6Player7IsInAirEv(void* p);
extern "C" void _ZN10ClsnResultaSERKS_(ClsnResult* d, const ClsnResult* s);

extern "C" void func_020371fc(char* self);
void func_020371fc(char* self)
{
    if ((*(unsigned char*)(self + 0x90) & 1) == 0) return;
    if ((*(unsigned char*)(self + 0x90) & 8) == 0) return;
    if (*(int*)(self + 0x10) & 0x100) return;
    if (*(int*)(self + 0x1b0) >= 0xf20) return;
    if (_ZN6Player7IsInAirEv(*(void**)(self + 0x14))) return;
    {
        Vector3 pos;
        Vector3* objpos = (Vector3*)(*(char**)(self + 0x14) + 0x5c);
        RaycastGround rg;
        pos.x = objpos->x;
        pos.y = objpos->y + *(int*)(self + 0x18);
        pos.z = objpos->z;
        rg.SetObjAndPos(pos, *(Actor**)(self + 0x14));
        if (rg.DetectClsn() != 0) {
            int cy = rg.field44;
            int diff = objpos->y - cy;
            if (diff > 0 && diff < (*(int*)(self + 0x18) << 1)) {
                objpos->y = cy;
                *(unsigned char*)(self + 0x90) |= 4;
                _ZN10ClsnResultaSERKS_((ClsnResult*)(self + 0x94), &rg.clsn);
                ((WithMeshClsn*)self)->SetGroundFlag();
            }
        }
    }
}
