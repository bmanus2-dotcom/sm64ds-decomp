struct Vec3 { int x, y, z; };
struct Obj { char pad[0x58]; struct Vec3 a; struct Vec3 b; };

void func_02037a04(struct Obj *o, struct Vec3 *d1, struct Vec3 *d2)
{
    d1->x = o->a.x;
    d1->y = o->a.y;
    d1->z = o->a.z;
    d2->x = o->b.x;
    d2->y = o->b.y;
    d2->z = o->b.z;
}
