typedef struct { int x, y, z; } Vec3_Fix12;

void CrossVec3(const Vec3_Fix12 *a, const Vec3_Fix12 *b, Vec3_Fix12 *out)
{
    int bz = b->z, ay = a->y, ax = a->x, by = b->y, az = a->z, bx = b->x;
    out->x = (int)(((long long)ay * bz - (long long)az * by + 0x800) >> 12);
    out->y = (int)(((long long)az * bx - (long long)ax * bz + 0x800) >> 12);
    out->z = (int)(((long long)ax * by - (long long)ay * bx + 0x800) >> 12);
}
