typedef struct { int x, y, z; } Vec3;
typedef struct {
    int pad0[3];
    Vec3 a;
    int pad1[2];
    Vec3 b;
    Vec3 c;
    Vec3 d;
    Vec3 e;
} T;
void func_ov007_020c9f10(T* self, Vec3* pos, int w, int h)
{
    Vec3* pe = &self->e;
    Vec3* pd = &self->d;
    Vec3* pc = (Vec3*)(((int)self + 0x2c) & 0xFFFFFFFFFFFFFFFF);
    int* qd = (int*)(((int)self + 0x3c) & 0xFFFFFFFFFFFFFFFF);
    int* qe = (int*)(((int)self + 0x48) & 0xFFFFFFFFFFFFFFFF);
    *pe = *pos;
    *pd = *pe;
    *pc = *pd;
    {
        Vec3* pb = (Vec3*)(((int)self + 0x20) & 0xFFFFFFFFFFFFFFFF);
        *pb = *pc;
        self->a = *pb;
        pb->x -= w / 2;
        pc->x += w / 2;
        *qd -= h / 2;
        *qe += h / 2;
    }
}
