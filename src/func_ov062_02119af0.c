//cpp
// NONMATCHING: register allocation (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
namespace cstd { int atan2(int y, int x); }
extern "C" int Vec3_Dist(const Vector3 *a, const Vector3 *b);
struct PathPtr {
    int GetNode(Vector3 &v, unsigned int i);
};

extern "C" int func_ov062_02119af0(char *p) {
    int dx = *(int *)(p + 0x3cc) - *(int *)(p + 0x5c);
    int dz = *(int *)(p + 0x3d4) - *(int *)(p + 0x64);
    int dxc = *(int *)(p + 0x3cc) - *(int *)(p + 0x3c0);
    int dzc = *(int *)(p + 0x3d4) - *(int *)(p + 0x3c8);
    *(short *)(p + 0x3a8) = (short)cstd::atan2(dx, dz);
    int dot = (dzc >> 0xc) * (dz >> 0xc) + (dxc >> 0xc) * (dx >> 0xc);
    if (dot > 0) {
        if (Vec3_Dist((Vector3 *)(p + 0x5c), (Vector3 *)(p + 0x3cc)) < (*(int *)(p + 0x98) >> 1)) {
            int *cnt = (int *)(p + 0x3bc);
            *(int *)(p + 0x3c0) = *(int *)(p + 0x3cc);
            *(int *)(p + 0x3c4) = *(int *)(p + 0x3d0);
            *(int *)(p + 0x3c8) = *(int *)(p + 0x3d4);
            *cnt = *cnt + 1;
            if (*(int *)(p + 0x3bc) >= *(int *)(p + 0x3b8)) {
                *(int *)(p + 0x3bc) = 0;
            }
            if (*(int *)(p + 0x3bc) == 0) {
                return -1;
            }
            ((PathPtr *)(p + 0x3d8))->GetNode(*(Vector3 *)(p + 0x3cc), 0);
            return 1;
        }
    }
    return 0;
}
