typedef short s16;
typedef struct Vector3 { int x, y, z; } Vector3;
typedef struct RaycastGround { char filler[0x44]; int clsnY; char rest[0x8]; } RaycastGround;

extern void _ZN13RaycastGroundC1Ev(RaycastGround *self);
extern void _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(RaycastGround *self, Vector3 *pos, void *actor);
extern int _ZN13RaycastGround10DetectClsnEv(RaycastGround *self);
extern void _ZN13RaycastGroundD1Ev(RaycastGround *self);
extern int LenVec3(Vector3 *v);
extern void Vec3_Sub(Vector3 *out, Vector3 *a, Vector3 *b);
extern int _ZN4cstd4fdivEii(int a, int b);
extern void Vec3_MulScalarInPlace(int *v, int s);
extern void Vec3_Add(Vector3 *out, Vector3 *a, Vector3 *b);
extern int func_020092c4(int arg0, Vector3 *out, Vector3 *target);
extern s16 Vec3_HorzAngle(const Vector3 *v0, const Vector3 *v1);

extern int data_02086f58[];

void func_0200b798(char *actor, s16 *cfg, int arg2)
{
    RaycastGround ray;
    Vector3 sp;
    Vector3 sp18;
    Vector3 sp24;
    Vector3 sp30;
    Vector3 spC;
    int tbl;
    int len;
    int lim;
    long long acc;

    if (*(unsigned char *)((char *)cfg + 1) == 0xff) {
        tbl = 0;
    } else {
        tbl = *(unsigned char *)((char *)cfg + 1);
    }

    sp.x = (int)cfg[1] << 12;
    sp.y = (int)cfg[2] << 12;
    sp.z = (int)cfg[3] << 12;

    _ZN13RaycastGroundC1Ev(&ray);
    _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(&ray, &sp, actor);
    if (_ZN13RaycastGround10DetectClsnEv(&ray) != 0) {
        sp.y = ray.clsnY;
    }

    spC.x = *(int *)(actor + 0x98) - sp.x;
    spC.y = *(int *)(actor + 0xa0) - sp.z;
    spC.z = arg2 + sp.y;

    sp18.x = arg2 + sp.y;
    sp18.y = spC.x;
    sp18.z = spC.y;

    acc = (long long)spC.x * (long long)*(int *)(data_02086f58 + tbl * 3 + 2);
    sp24.x = sp.x + (int)((acc + 0x800) >> 12);
    acc = (long long)spC.y * (long long)*(int *)(data_02086f58 + tbl * 3 + 2);
    sp24.z = sp.z + (int)((acc + 0x800) >> 12);
    sp24.y = sp18.x;

    len = LenVec3(&sp18);
    if (len < 0x220000) {
        sp24.y = sp18.x + (0x220000 - len);
    }

    Vec3_Sub(&sp24, &sp18, (Vector3 *)(actor + 0x80));
    spC = sp24;
    len = LenVec3(&spC);

    if ((*(int *)(actor + 0x154) & 0xc00) != 0) {
        lim = *(int *)(data_02086f58 + tbl * 3);
    } else {
        lim = *(int *)(data_02086f58 + tbl * 3 + 1);
    }

    if (len > lim) {
        Vec3_MulScalarInPlace((int *)&spC, _ZN4cstd4fdivEii(lim, len));
        Vec3_Add(&sp30, (Vector3 *)(actor + 0x80), &spC);
        sp18 = sp30;
    }

    if ((*(int *)(actor + 0x154) & 4) != 0) {
        *(int *)(actor + 0x8c) = sp18.x;
        *(int *)(actor + 0x90) = sp18.y;
        *(int *)(actor + 0x94) = sp18.z;
    } else {
        func_020092c4((int)actor, (Vector3 *)(actor + 0x8c), &sp18);
    }

    *(s16 *)(actor + 0x17c) = Vec3_HorzAngle((Vector3 *)(actor + 0x80),
                                             (Vector3 *)(actor + 0x8c));
    _ZN13RaycastGroundD1Ev(&ray);
}