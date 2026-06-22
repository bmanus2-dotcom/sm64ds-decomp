struct Vec3 { int x, y, z; };
struct AB { int a; int b; };
struct Obj { int a; int b; struct Vec3 v; };

void func_02037eb0(struct Obj *o, struct AB ab, struct Vec3 *v)
{
    o->a = ab.a;
    o->b = ab.b;
    o->v.x = v->x;
    o->v.y = v->y;
    o->v.z = v->z;
}
