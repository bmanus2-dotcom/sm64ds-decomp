//cpp
struct Matrix4x3 {
    int m[12];
};
struct MovingMeshCollider {
    void Transform(const Matrix4x3 &mtx, short s);
};

extern "C" void func_ov002_020b9f80(char *self) {
    *(Matrix4x3 *)(self + 0x2ec) = *(Matrix4x3 *)(self + 0xf0);
    *(int *)(self + 0x310) = *(int *)(self + 0x5c);
    *(int *)(self + 0x314) = *(int *)(self + 0x60) - *(int *)(self + 0x32c);
    *(int *)(self + 0x318) = *(int *)(self + 0x64);
    ((MovingMeshCollider *)(self + 0x124))->Transform(*(Matrix4x3 *)(self + 0x2ec),
        *(short *)(self + 0x8e));
}
