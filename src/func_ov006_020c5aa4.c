// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef struct { int x, y, z; } Vec3;
extern int LenVec3(Vec3 *v);
extern void Vec3_Sub(Vec3 *out, Vec3 *a, Vec3 *b);
extern int NormalizeVec3IfNonZero(Vec3 *v);
extern void Vec3_MulScalarInPlace(int *v, int s);

struct Obj {
    int pad0;
    int f4, f8, fc;
    int f10, f14, f18, f1c;
    char gap20[0x9c - 0x20];
    Vec3 f9c;
    Vec3 fa8;
    Vec3 fb4;
    char gapc0[0xdc - 0xc0];
    int fdc;
    char gape0[0xe6 - 0xe0];
    short fe6;
};

extern int data_ov006_0213af40[2];

void func_ov006_020c5aa4(struct Obj *o)
{
    Vec3 a, b, da, db, t;
    int la;
    o->fa8.x = o->f4;
    o->fa8.y = o->f8;
    o->fa8.z = o->fc;
    o->fdc = LenVec3(&o->fa8);
    o->fe6 = 0;
    a.x = o->f10;
    a.y = o->f1c;
    a.z = 0;
    b.x = o->f14;
    b.y = o->f18;
    b.z = 0;
    Vec3_Sub(&da, &a, &o->f9c);
    la = LenVec3(&da);
    Vec3_Sub(&db, &b, &o->f9c);
    if (la < LenVec3(&db)) {
        o->fb4.x = a.x;
        o->fb4.y = a.y;
        o->fb4.z = a.z;
    } else {
        o->fb4.x = b.x;
        o->fb4.y = b.y;
        o->fb4.z = b.z;
    }
    Vec3_Sub(&t, &o->fb4, &o->f9c);
    o->fa8.x = t.x;
    o->fa8.y = t.y;
    o->fa8.z = t.z;
    if (NormalizeVec3IfNonZero(&o->fa8) == 0) {
        o->fa8.x = o->f4;
        o->fa8.y = o->f8;
        o->fa8.z = o->fc;
    } else {
        Vec3_MulScalarInPlace((int*)&o->fa8, o->fdc);
    }
    *(int*)((char*)o + 0x30) = data_ov006_0213af40[0];
    *(int*)((char*)o + 0x34) = data_ov006_0213af40[1];
}
