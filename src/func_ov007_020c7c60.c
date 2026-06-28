struct Vec3 { int x, y, z; };
extern void SubVec3(struct Vec3 *a, struct Vec3 *b, struct Vec3 *c);
extern void AddVec3(struct Vec3 *a, struct Vec3 *b, struct Vec3 *c);
extern void func_02053320(int s, int *a, int *b, int *out);

void func_ov007_020c7c60(char **self, int r6, int r4)
{
    struct Vec3 d2, scaled, d1;
    int m, s;

    SubVec3((struct Vec3 *)*(void **)self[0], (struct Vec3 *)*(void **)self[1], &d1);
    SubVec3(&d1, (struct Vec3 *)(self + 3), &d2);

    m = -r6;
    scaled.x = (int)(((long long)m * d2.x + 0x800) >> 12);
    scaled.y = (int)(((long long)m * d2.y + 0x800) >> 12);
    scaled.z = (int)(((long long)m * d2.z + 0x800) >> 12);

    AddVec3((struct Vec3 *)(self[0] + 0x10), &scaled, (struct Vec3 *)(self[0] + 0x10));
    SubVec3((struct Vec3 *)(self[1] + 0x10), &scaled, (struct Vec3 *)(self[1] + 0x10));

    s = -r4;
    func_02053320(s, (int *)(self[0] + 4), (int *)(self[0] + 0x10), (int *)(self[0] + 0x10));
    func_02053320(s, (int *)(self[1] + 4), (int *)(self[1] + 0x10), (int *)(self[1] + 0x10));
}
