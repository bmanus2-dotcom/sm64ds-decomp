//cpp
// NONMATCHING: different op / idiom (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
typedef int Fix12i;
typedef short s16;
extern "C" {
extern void* _ZN5Actor13ClosestPlayerEv(void*);
extern Fix12i Vec3_Dist(const Vector3* a, const Vector3* b);
extern s16 Vec3_HorzAngle(const Vector3* a, const Vector3* b);

void func_ov062_02118258(char* c, int r4)
{
    *(void**)(c + 0x3b4) = _ZN5Actor13ClosestPlayerEv(c);

    if (*(void**)(c + 0x3b4) == 0 || Vec3_Dist((Vector3*)(c + 0x5c), (Vector3*)(c + 0x39c)) > r4) {
        *(short*)(c + 0x3c0) = Vec3_HorzAngle((Vector3*)(c + 0x5c), (Vector3*)(c + 0x39c));
        *(int*)(c + 0x3b8) = 0x61a8000;
    } else {
        Vector3 v;
        Vector3* src = (Vector3*)(*(char**)(c + 0x3b4) + 0x5c);
        v = *src;
        if (Vec3_Dist((Vector3*)(c + 0x39c), &v) > r4) {
            *(int*)(c + 0x3b8) = 0x4e20000;
            return;
        }
        *(int*)(c + 0x3b8) = Vec3_Dist((Vector3*)(c + 0x5c), &v);
        *(short*)(c + 0x3c0) = Vec3_HorzAngle((Vector3*)(c + 0x5c), &v);
    }
}
}
