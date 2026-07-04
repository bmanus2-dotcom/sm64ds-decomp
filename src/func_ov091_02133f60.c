struct Vec3 { int x, y, z; };

void *_ZN5Actor13ClosestPlayerEv(void *thiz);
short Vec3_HorzAngle(const struct Vec3 *a, const struct Vec3 *b);
int ApproachAngle(short *cur, int target, int a, int b, int c);
int Vec3_Dist(const struct Vec3 *a, const struct Vec3 *b);
int func_ov091_02134044(void *c, void *p);

extern char data_ov091_021356b0[];

int func_ov091_02133f60(char *c)
{
    void *pl = _ZN5Actor13ClosestPlayerEv(c);
    struct Vec3 v;
    short ang;
    struct Vec3 *src;
    if (pl == 0) goto done;

    src = (struct Vec3*)(((int)pl + 0x5c) & 0xFFFFFFFFFFFFFFFF);
    v.x = src->x;
    v.y = src->y;
    v.z = src->z;
    ang = Vec3_HorzAngle((struct Vec3*)(c + 0x5c), &v);
    ApproachAngle((short*)(c + 0x94), ang, 0xa, 0x200, 0x100);
    if (*(unsigned short*)(c + 0x100) != 0) goto done;
    if (Vec3_Dist((struct Vec3*)(c + 0x5c), &v) >= 0x3e8000) goto done;
    if (ang >= 0x1000) goto done;
    func_ov091_02134044(c, data_ov091_021356b0);
done:
    return 1;
}
