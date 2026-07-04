// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;

struct Vector3 { int x, y, z; };

extern void _ZN11RaycastLineC1Ev(void *self);
extern void _ZN11RaycastLine13SetObjAndLineERK7Vector3S2_P5Actor(void *self, struct Vector3 *a, struct Vector3 *b, void *actor);
extern int _ZN11RaycastLine10DetectClsnEv(void *self);
extern void *_ZN11RaycastLine10GetClsnPosEv(void *self);
extern int _ZNK10ClsnResult9GetClsnIDEv(void *self);
extern void *_ZN5Actor10FindWithIDEj(u32 id);
extern void _ZN11RaycastLineD1Ev(void *self);

int func_ov002_020c607c(char *self, int p1, int p2, int *outptr)
{
    char rc[0x78];
    void *found;
    struct Vector3 a, b;
    int az, bz, bx;
    *(int *)(self + 0x36c) = 0;
    *outptr = (int)0x80000000;
    _ZN11RaycastLineC1Ev(rc);
    az = *(int *)(self + 0x64);
    a.x = *(int *)(self + 0x5c);
    a.y = p1;
    a.z = az;
    bz = *(int *)(self + 0x64);
    bx = *(int *)(self + 0x5c);
    b.x = bx;
    b.z = bz;
    b.y = p2;
    _ZN11RaycastLine13SetObjAndLineERK7Vector3S2_P5Actor(rc, &a, &b, self);
    if (_ZN11RaycastLine10DetectClsnEv(rc) != 0) {
        struct Vector3 pos;
        _ZN11RaycastLine10GetClsnPosEv(&pos);
        *outptr = pos.y;
        if (_ZNK10ClsnResult9GetClsnIDEv(rc + 0x10) != -1) {
            found = _ZN5Actor10FindWithIDEj((u32)_ZNK10ClsnResult9GetClsnIDEv(rc + 0x10));
            *(int *)(self + 0x36c) = (int)found;
            if (found != 0) {
                if (*(u32 *)((char *)found + 0xb0) & 0x1000000) {
                    _ZN11RaycastLineD1Ev(rc);
                    return 1;
                }
                if (*(u32 *)((char *)found + 0xb0) & 0x2000000) {
                    _ZN11RaycastLineD1Ev(rc);
                    return 2;
                }
            }
        }
    }
    _ZN11RaycastLineD1Ev(rc);
    return 0;
}
