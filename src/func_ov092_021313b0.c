//cpp
// NONMATCHING: register allocation (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x,y,z; };
typedef unsigned short u16;
typedef short s16;
struct PathPtr {
    int GetNode(Vector3 &v, unsigned int i) const;
};
extern "C" s16 Vec3_HorzAngle(const struct Vector3 *v0, const struct Vector3 *v1);

extern "C" void func_ov092_021313b0(void *t) {
    char *c = (char*)t;
    Vector3 old;
    old.x = *(int*)(c+0x580);
    old.y = *(int*)(c+0x584);
    old.z = *(int*)(c+0x588);
    int *cnt = (int*)(c+0x57c);
    (*cnt)++;
    if (*cnt >= *(int*)(c+0x578))
        *cnt = 0;
    ((PathPtr*)(c+0x58c))->GetNode(*(Vector3*)(c+0x580), (unsigned int)*cnt);
    Vector3 *nw = (Vector3*)(c+0x580);
    if (nw->x == old.x && nw->z == old.z) {
        *(int*)(c+0x568) = 1;
        return;
    }
    u16 a = (u16)Vec3_HorzAngle(&old, nw);
    if (a >= 0x2000 && a < 0x6000) *(int*)(c+0x568) = 5;
    else if (a >= 0x6000 && a < 0xa000) *(int*)(c+0x568) = 3;
    else if (a >= 0xa000 && a < 0xe000) *(int*)(c+0x568) = 4;
    else *(int*)(c+0x568) = 2;
}
