//cpp
// NONMATCHING: push-set / frame (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
typedef unsigned int u32;

template<class T> struct Fix12 { int val; };

struct SharedFilePtr { unsigned short fileID; unsigned char numRefs; char* filePtr; };
struct BMD_File; struct BMA_File; struct BCA_File; struct Vector3_16; struct Actor;

struct Model { static void LoadFile(SharedFilePtr&); };
struct Animation { static void LoadFile(SharedFilePtr&); };
struct ModelBase { int SetFile(BMD_File*, int, int); };
struct ShadowModel { int InitCylinder(); };
struct MaterialChanger {
    static void Prepare(BMD_File&, BMA_File&);
    int SetFile(BMA_File&, int, Fix12<int>, u32);
};
struct ModelAnim { void SetAnim(BCA_File*, int, Fix12<int>, u32); };
struct WithMeshClsn { void Init(Actor*, Fix12<int>, Fix12<int>, Vector3_16*, Fix12<int>); };

extern SharedFilePtr data_ov084_02130cf8;
extern SharedFilePtr* data_ov074_0212292c[];
extern SharedFilePtr data_ov084_0213089c;
extern SharedFilePtr data_ov084_02130cc8;

extern "C" int func_ov074_02122634(char* self)
{
    int i;
    Model::LoadFile(data_ov084_02130cf8);
    for (i = 0; i < 7; i++)
        Animation::LoadFile(*data_ov074_0212292c[i]);

    if (((ModelBase*)(self + 0x210))->SetFile((BMD_File*)data_ov084_02130cf8.filePtr, 1, 1) == 0)
        return 0;
    if (((ShadowModel*)(self + 0x274))->InitCylinder() == 0)
        return 0;

    MaterialChanger::Prepare(*(BMD_File*)data_ov084_02130cf8.filePtr,
                             *(BMA_File*)&data_ov084_0213089c);
    ((MaterialChanger*)(self + 0x3d0))->SetFile(*(BMA_File*)&data_ov084_0213089c, 0x40000000, (Fix12<int>){0x1000}, 0);
    ((ModelAnim*)(self + 0x210))->SetAnim((BCA_File*)data_ov084_02130cc8.filePtr, 0, (Fix12<int>){0x1000}, 0);

    *(s16*)(self + 0x92) = *(s16*)(self + 0x8c);
    *(s16*)(self + 0x94) = *(s16*)(self + 0x8e);
    *(s16*)(self + 0x96) = *(s16*)(self + 0x90);
    *(int*)(self + 0xa0) = -0x3c000;
    *(int*)(self + 0x5dc) = 0;
    ((WithMeshClsn*)(self + 0x40c))->Init((Actor*)self, (Fix12<int>){0x14000}, (Fix12<int>){0x14000}, (Vector3_16*)0, (Fix12<int>){0});
    return 1;
}
