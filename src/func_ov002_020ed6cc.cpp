//cpp
struct Vector3 { int x, y, z; };
extern "C" int Vec3_HorzDist(const Vector3 *a, const Vector3 *b);
extern "C" int DecIfAbove0_Byte(unsigned char *p);

struct Obj {
    char pad5c[0x5c];
    Vector3 v5c;        /* +0x5c */
    char pad3cc[0x3cc - 0x68];
    Vector3 v3cc;       /* +0x3cc */
    char pad41f[0x41f - 0x3d8];
    unsigned char f41f; /* +0x41f */
};

extern "C" int func_ov002_020ed6cc(Obj *self) {
    int dist = Vec3_HorzDist(&self->v3cc, &self->v5c);
    self->v3cc.x = self->v5c.x;
    self->v3cc.y = self->v5c.y;
    self->v3cc.z = self->v5c.z;
    if (dist < 0x32000) {
        if (DecIfAbove0_Byte(&self->f41f) != 0) goto ret0;
        return 1;
    }
    self->f41f = 0xf;
ret0:
    return 0;
}
