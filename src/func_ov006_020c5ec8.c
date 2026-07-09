typedef struct { int x, y, z; } Vec3;

extern int LenVec3(Vec3 *v);
extern void Vec3_Sub(Vec3 *out, Vec3 *a, Vec3 *b);
extern int NormalizeVec3IfNonZero(Vec3 *v);
extern void Vec3_MulScalarInPlace(int *v, int s);

extern int data_ov006_0213af68[2];

void func_ov006_020c5ec8(void *arg0)
{
    char *r4;
    Vec3 sp00;
    Vec3 sp0c;
    Vec3 sp18;
    Vec3 sp24;
    Vec3 sp30;
    Vec3 sp3c;
    Vec3 sp48;
    int r6;
    int r5;
    int r0;

    r4 = (char *)arg0;
    *(short *)(r4 + 0xe6) = 0;

    *(int *)(r4 + 0xa8) = *(int *)(r4 + 4);
    *(int *)(r4 + 0xac) = *(int *)(r4 + 8);
    *(int *)(r4 + 0xb0) = *(int *)(r4 + 0xc);

    *(int *)(r4 + 0xdc) = LenVec3((Vec3 *)(r4 + 0xa8));

    sp00.x = *(int *)(r4 + 0x10);
    sp00.y = *(int *)(r4 + 0x1c);
    sp00.z = 0;
    sp0c.x = *(int *)(r4 + 0x14);
    sp0c.y = *(int *)(r4 + 0x1c);
    sp0c.z = 0;
    sp18.x = (sp0c.x + sp00.x) >> 1;
    sp18.y = *(int *)(r4 + 0x18);
    sp18.z = 0;

    Vec3_Sub(&sp24, &sp00, (Vec3 *)(r4 + 0x9c));
    r6 = LenVec3(&sp24);
    Vec3_Sub(&sp30, &sp0c, (Vec3 *)(r4 + 0x9c));
    r5 = LenVec3(&sp30);
    Vec3_Sub(&sp3c, &sp18, (Vec3 *)(r4 + 0x9c));
    r0 = LenVec3(&sp3c);

    if (r0 < r5 && r0 < r6) {
        *(int *)(r4 + 0xb4) = sp18.x;
        *(int *)(r4 + 0xb8) = sp18.y;
        *(int *)(r4 + 0xbc) = sp18.z;
    } else if (r5 < r6) {
        *(int *)(r4 + 0xb4) = sp0c.x;
        *(int *)(r4 + 0xb8) = sp0c.y;
        *(int *)(r4 + 0xbc) = sp0c.z;
    } else {
        *(int *)(r4 + 0xb4) = sp00.x;
        *(int *)(r4 + 0xb8) = sp00.y;
        *(int *)(r4 + 0xbc) = sp00.z;
    }

    Vec3_Sub(&sp48, (Vec3 *)(r4 + 0xb4), (Vec3 *)(r4 + 0x9c));
    *(int *)(r4 + 0xa8) = sp48.x;
    *(int *)(r4 + 0xac) = sp48.y;
    *(int *)(r4 + 0xb0) = sp48.z;

    if (NormalizeVec3IfNonZero((Vec3 *)(r4 + 0xa8)) == 0) {
        *(int *)(r4 + 0xa8) = *(int *)(r4 + 4);
        *(int *)(r4 + 0xac) = *(int *)(r4 + 8);
        *(int *)(r4 + 0xb0) = *(int *)(r4 + 0xc);
    } else {
        Vec3_MulScalarInPlace((int *)(r4 + 0xa8), *(int *)(r4 + 0xdc));
    }

    *(int *)(r4 + 0x30) = data_ov006_0213af68[0];
    *(int *)(r4 + 0x34) = data_ov006_0213af68[1];
}