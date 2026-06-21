//cpp
typedef int Fix12;
struct Actor;
struct SharedFilePtr;

struct MovingCylinderClsn {
    void Init(Actor* actor, Fix12 a, Fix12 b, unsigned int c, unsigned int d);
};

namespace Model {
    void LoadFile(SharedFilePtr& f);
}

extern SharedFilePtr data_ov002_0210d9a8;

struct Self {
    char pad0[8];
    unsigned int flags; // 0x8
    char pad1[0xc8];
    MovingCylinderClsn clsn; // 0xd4
};

extern "C" int func_ov002_020f07dc(Self* self)
{
    self->clsn.Init((Actor*)self, 0x64000, 0x40000, 0x800002, 0);
    *(unsigned char*)((char*)self + 0x10d) = self->flags & 0xf;
    *(unsigned char*)((char*)self + 0x10e) = (self->flags >> 8) & 0xf;
    *(unsigned char*)((char*)self + 0x10f) = 0;
    *(int*)((char*)self + 0x108) = 0;
    *(unsigned char*)((char*)self + 0x110) = 0;
    *(unsigned char*)((char*)self + 0x113) = 0;
    Model::LoadFile(data_ov002_0210d9a8);
    return 1;
}
