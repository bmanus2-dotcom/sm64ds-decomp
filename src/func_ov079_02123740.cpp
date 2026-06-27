//cpp
struct MovingMeshCollider { ~MovingMeshCollider(); };
struct ShadowModel { ~ShadowModel(); };
struct TextureSequence { ~TextureSequence(); };
struct ModelAnim { ~ModelAnim(); };
struct WithMeshClsn { ~WithMeshClsn(); };

extern int data_ov079_02127c80;
extern "C" int func_ov002_020aed18(int *x);

extern "C" void *func_ov079_02123740(char *r4) {
    *(int *)r4 = (int)&data_ov079_02127c80;
    ((MovingMeshCollider *)(r4 + 0x418))->~MovingMeshCollider();
    ((ShadowModel *)(r4 + 0x344))->~ShadowModel();
    ((TextureSequence *)(r4 + 0x330))->~TextureSequence();
    ((ModelAnim *)(r4 + 0x2cc))->~ModelAnim();
    ((WithMeshClsn *)(r4 + 0x110))->~WithMeshClsn();
    func_ov002_020aed18((int *)r4);
    return r4;
}
