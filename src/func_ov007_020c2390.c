struct Vec3 { int x, y, z; };
extern void SubVec3(struct Vec3 *a, struct Vec3 *b, struct Vec3 *c);
extern void NormalizeVec3(struct Vec3 *a, struct Vec3 *b);

void func_ov007_020c2390(char *t)
{
    struct Vec3 v;
    SubVec3((struct Vec3 *)(t + 4), (struct Vec3 *)(t + 0x10), &v);
    NormalizeVec3(&v, &v);
    *(short *)(t + 0x1c) = v.x;
    *(short *)(t + 0x1e) = v.y;
    *(short *)(t + 0x20) = v.z;
    if (*(short *)(t + 0x1c) > 0xfff) *(short *)(t + 0x1c) = 0xfff;
    if (*(short *)(t + 0x1e) > 0xfff) *(short *)(t + 0x1e) = 0xfff;
    if (*(short *)(t + 0x20) > 0xfff) *(short *)(t + 0x20) = 0xfff;
}
