//cpp
// NONMATCHING: missing logic (ROM does more) (div=34). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;

struct Animation { void Advance(); };
struct CylinderClsn { void Clear(); void Update(); };
struct WithMeshClsn { int IsOnGround() const; };
struct Vector3;

extern "C" void func_ov030_02111a00(void* c);
extern "C" void func_ov030_02111f6c(char* c, WithMeshClsn* w);
extern "C" void func_ov030_02111bc4(void* c);
extern "C" int Vec3_Dist(const Vector3* a, const Vector3* b);
extern "C" void func_ov030_021141a8(void* c, int x);

struct Actor {
    void UpdatePos(CylinderClsn*);
};

struct V2 { int x, y; };
struct ClsnResult {
    V2 v;          // 0x4,0x8
    int a2, a3, a4; // 0xc,0x10,0x14
    u16 h0, h1;    // 0x18,0x1a
    int t0, t1, t2; // 0x1c,0x20,0x24
    int GetClsnID() const;
    virtual ~ClsnResult();
};
extern "C" ClsnResult* func_0203567c(WithMeshClsn* w);
extern "C" int func_02037f44(ClsnResult* r);

extern "C" int func_ov030_02112400(char* c)
{
    func_ov030_02111a00(c);
    ((Animation*)(c + 0x124))->Advance();
    ((Actor*)c)->UpdatePos((CylinderClsn*)(c + 0x160));
    func_ov030_02111f6c(c, (WithMeshClsn*)(c + 0x194));
    func_ov030_02111bc4(c);
    ((CylinderClsn*)(c + 0x160))->Clear();
    ((CylinderClsn*)(c + 0x160))->Update();

    int b = (int)(*(u16*)(c + 0xc) == 0x10c);
    if (b != 0) {
        if (Vec3_Dist((Vector3*)(c + 0x380), (Vector3*)(c + 0x5c)) < 0x514000) {
            if (*(int*)(c + 0x60) > *(int*)(c + 0x384) - 0x12c000) {
                func_ov030_021141a8(c, 1);
            }
        }
    } else {
        if (((WithMeshClsn*)(c + 0x194))->IsOnGround()) {
            ClsnResult res = *func_0203567c((WithMeshClsn*)(c + 0x194));
            if (res.GetClsnID() != -1) {
                if (func_02037f44(&res) == 0) {
                    func_ov030_021141a8(c, 0);
                }
            }
        }
    }
    return 1;
}
