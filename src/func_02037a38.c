struct Vec3 { int x, y, z; };
struct Obj { char pad[0x4c]; struct Vec3 d; struct Vec3 a; struct Vec3 b; };

void func_02037a38(struct Obj *o)
{
    o->d.x = o->a.x + o->b.x;
    o->d.y = o->a.y + o->b.y;
    o->d.z = o->a.z + o->b.z;
}
