//cpp
struct BMD_File;
struct BTA_File;
struct KCL_File;
struct Actor;
struct Vector3;
struct Matrix4x3;
struct CLPS_Block;
struct SharedFilePtr;

extern "C" void *_ZN5Model8LoadFileER13SharedFilePtr(void *fp);

struct ModelBase {
    void SetFile(BMD_File *f, int b, int c);
};

struct ShadowModel {
    void InitCuboid();
};

extern "C" void _ZN18TextureTransformer7PrepareER8BMD_FileR8BTA_File(
    BMD_File &f, BTA_File &b);

struct TextureTransformer {
    void SetFile(BTA_File &f, int a, int fix, unsigned int u);
};

struct Platform {
    void UpdateModelPosAndRotY();
    void UpdateClsnPosAndRot();
};

extern "C" void *_ZN12MeshCollider8LoadFileER13SharedFilePtr(void *fp);

struct MovingMeshCollider {
    void SetFile(KCL_File *f, const Matrix4x3 &m, int fix, short sh,
                 CLPS_Block &b);
};

extern "C" void func_020393c4(void *p, void *v);

struct RaycastGround {
    int pad[0x11];
    int result;
    int pad2[2];

    RaycastGround();
    void SetObjAndPos(const Vector3 &v, Actor *a);
    int DetectClsn();
    ~RaycastGround();
};

struct Entry3 {
    void *a;
    void *b;
    void *c;
};

extern "C" char data_ov065_0211d16c[8];
extern "C" Entry3 data_ov065_0211d194[];
extern "C" Entry3 data_ov065_0211d198[];
extern "C" Entry3 data_ov065_0211d19c[];
extern "C" void func_ov065_0211aacc();
extern "C" unsigned char data_0209f2c0;
extern "C" void *data_ov065_0211c0b8[];

struct V3 {
    int x;
    int y;
    int z;
};

extern "C" int _ZN20TtcConveyorBeltLarge13InitResourcesEv(char *self)
{
    void *locbuf[2];
    V3 v;
    unsigned char e;
    void *mf;
    void *kf;

    locbuf[0] = *(void **)&data_ov065_0211d16c[0];
    locbuf[1] = *(void **)&data_ov065_0211d16c[4];

    if (*(unsigned short *)(self + 0xc) != 0x6f) {
        if (*(unsigned short *)(self + 0xc) == 0x70)
            *(unsigned char *)(self + 0x39e) = 1;
    } else {
        *(unsigned char *)(self + 0x39e) = 0;
    }

    e = *(unsigned char *)(self + 0x39e);
    mf = _ZN5Model8LoadFileER13SharedFilePtr(
        data_ov065_0211d194[e].a);
    ((ModelBase *)(self + 0xd4))->SetFile(
        (BMD_File *)mf, 1, -1);

    ((ShadowModel *)(self + 0x334))->InitCuboid();

    e = *(unsigned char *)(self + 0x39e);
    _ZN18TextureTransformer7PrepareER8BMD_FileR8BTA_File(
        *(BMD_File *)*(void **)((char *)data_ov065_0211d194[e].a + 4),
        *(BTA_File *)locbuf[e]);

    ((TextureTransformer *)(self + 0x320))->SetFile(
        *(BTA_File *)locbuf[*(unsigned char *)(self + 0x39e)],
        0, 0x1000, 0);

    ((Platform *)self)->UpdateModelPosAndRotY();
    ((Platform *)self)->UpdateClsnPosAndRot();

    e = *(unsigned char *)(self + 0x39e);
    kf = _ZN12MeshCollider8LoadFileER13SharedFilePtr(
        data_ov065_0211d198[e].a);
    ((MovingMeshCollider *)(self + 0x124))->SetFile(
        (KCL_File *)kf,
        *(Matrix4x3 *)(self + 0x2ec),
        0x199,
        *(short *)(self + 0x8e),
        *(CLPS_Block *)data_ov065_0211d19c[e].a);

    func_020393c4(
        self + 0x124,
        (void *)&func_ov065_0211aacc);

    *(void **)(self + 0x390) =
        data_ov065_0211c0b8[data_0209f2c0];
    *(void **)(self + 0x38c) =
        *(void **)(self + 0x390);
    *(void **)(self + 0x32c) =
        *(void **)(self + 0x38c);

    v.x = *(int *)(self + 0x5c);
    v.y = *(int *)(self + 0x60);
    v.z = *(int *)(self + 0x64);
    v.y = v.y - 0xa000;

    {
        RaycastGround rg;

        rg.SetObjAndPos(*(Vector3 *)&v, (Actor *)0);
        *(int *)(self + 0x394) = v.y;

        if (rg.DetectClsn() != 0)
            *(int *)(self + 0x394) = rg.result;
    }

    return 1;
}
