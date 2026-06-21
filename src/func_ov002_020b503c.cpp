//cpp
struct Matrix4x3 { int m[12]; };

struct MovingMeshCollider {
    void Transform(const Matrix4x3 &, short);
};

struct Obj {
    char pad[0x5c];
    int f5c, f60, f64;            /* +0x5c */
    char pad2[0x8e - 0x68];
    short f8e;                    /* +0x8e */
    char pad3[0x2ec - 0x90];
    Matrix4x3 mDst;              /* +0x2ec, translation row at +0x310 */
    char pad6[0x320 - (0x2ec + 48)];
    MovingMeshCollider *f320;    /* +0x320 */
    char pad7[0x6d0 - 0x324];
    Matrix4x3 mSrc;              /* +0x6d0 */
};

extern "C" void func_ov002_020b503c(Obj *self) {
    self->mDst = self->mSrc;
    self->mDst.m[9] = self->f5c;
    self->mDst.m[10] = self->f60;
    self->mDst.m[11] = self->f64;
    self->f320->Transform(self->mDst, self->f8e);
}
