// NONMATCHING: register allocation (div=55). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;

typedef struct Mtx43 { int w[12]; } Mtx43;

extern void Matrix4x3_ApplyInPlaceToRotationY(void* m, s16 angY);
extern void Matrix4x3_ApplyInPlaceToRotationX(void* m, s16 angX);
extern void Matrix4x3_ApplyInPlaceToRotationZ(void* m, s16 angZ);
extern void Matrix4x3_ApplyInPlaceToScale(void* m, int x, int y, int z);
extern void _ZN18MovingMeshCollider9TransformERK9Matrix4x3s(void* mc, void* m, short s);

void func_ov079_02124008(char* c)
{
    int a = (int)(s16)(*(s16*)(c + 0x8c) + *(s16*)(c + 0x3e0));
    unsigned char r7 = *(unsigned char*)(c + 0x414);
    if (a < 0)
        a = (s16)(a * -1);
    int r4 = (s16)(0x4000 - a);

    if (r7 != 0) {
        if (*(int*)(c + 0x3b0) == 0) {
            r4 = r4 / 32 + 0x1000;
        } else {
            r4 = r4 / 48 + 0x1000;
        }
    } else {
        r4 = r4 / 102 + 0x1000;
    }

    *(Mtx43*)(c + 0x5e0) = *(Mtx43*)(c + 0x2e8);
    r7 = r7 + 1;
    int r8 = r7 * ((r4 - 0x1000) * 0x168);

    Matrix4x3_ApplyInPlaceToRotationY(c + 0x5e0, *(s16*)(c + 0x3e2));

    int s = *(int*)(c + 0x3b0);
    if (s != 1 && s != 7) {
        Matrix4x3_ApplyInPlaceToRotationX(c + 0x5e0, *(s16*)(c + 0x3e0));
        Matrix4x3_ApplyInPlaceToRotationZ(c + 0x5e0, (s16)(*(s16*)(c + 0x3e4) >> 1));
    }

    Matrix4x3_ApplyInPlaceToScale(c + 0x5e0, 0x1000, r4, 0x1000);

    *(int*)(c + 0x604) = *(int*)(c + 0x5c);
    *(int*)(c + 0x608) = *(int*)(c + 0x60) + *(int*)(c + 0x410) - r8;
    *(int*)(c + 0x60c) = *(int*)(c + 0x64);

    _ZN18MovingMeshCollider9TransformERK9Matrix4x3s(c + 0x418, c + 0x5e0, *(s16*)(c + 0x3e2));
}
