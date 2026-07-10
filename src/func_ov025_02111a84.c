typedef struct { int x, y, z; } Vec3;

extern void _ZN5Actor9UpdatePosEP12CylinderClsn(char *a, void *clsn);
extern void _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(char *a, const Vec3 *v, int power);
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int id, int x, int y, int z);
extern void func_0201267c(unsigned int id, const Vec3 *v);

void func_ov025_02111a84(char *c)
{
    struct {
        Vec3 v2;
        Vec3 v1;
    } s;

    _ZN5Actor9UpdatePosEP12CylinderClsn(c, 0);
    if (*(int *)(c + 0xa8) >= 0)
        *(int *)(c + 0x9c) = -0x4000;
    else
        *(int *)(c + 0x9c) = -0x8000;
    if (*(int *)(c + 0x60) > *(int *)(c + 0x394))
        return;
    *(int *)(c + 0x60) = *(int *)(c + 0x394);
    s.v1.x = *(int *)(c + 0x5c);
    s.v1.y = *(int *)(c + 0x60);
    s.v1.z = *(int *)(c + 0x64);
    _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(c, &s.v1, 0x7d0000);
    *(unsigned char *)(c + 0x39e) = 0x3c;
    *(unsigned char *)(int)(((long long)(int)(c + 0x39f)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
    *(int *)(c + 0x398) = 6;
    s.v2.x = *(int *)(c + 0x5c);
    s.v2.y = *(int *)(c + 0x60);
    s.v2.z = *(int *)(c + 0x64);
    s.v2.y += 0x3c000;
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x2e, s.v2.x, s.v2.y, s.v2.z);
    func_0201267c(0xc7, (const Vec3 *)(c + 0x74));
}
