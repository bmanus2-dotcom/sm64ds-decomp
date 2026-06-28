//cpp
// func_ov060_02113d20 at 0x02113d20
// Matched byte-for-byte with mwccarm 1.2/sp2p3 (ov060).
struct Vector3 { int x, y, z; };

struct Actor {
    Actor *ClosestWithActorID(unsigned int id);
};

extern "C" int func_ov060_02118544(void *c, void *v);
extern "C" void func_ov060_021185c4(void *c);

extern "C" int func_ov060_02113d20(Actor *self)
{
    Vector3 v;
    Actor *closest = self->ClosestWithActorID(0x11c);
    if (closest) {
        v.x = *(int *)((char *)self + 0x5c);
        v.y = *(int *)((char *)self + 0x60);
        v.z = *(int *)((char *)self + 0x64);
        if (func_ov060_02118544(closest, &v)) {
            func_ov060_021185c4(closest);
            return 1;
        }
    }
    return 0;
}
