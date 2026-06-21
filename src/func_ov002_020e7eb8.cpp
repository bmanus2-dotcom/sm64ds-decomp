//cpp
typedef int Fix12;
struct Vector3_16f { Fix12 x, y, z; };
struct Callback;
namespace Particle {
struct System {
    static System *New(unsigned int, unsigned int, Fix12, Fix12, Fix12,
                       const Vector3_16f *, Callback *);
};
}
extern "C" {
extern void func_ov002_020e8244(Vector3_16f *out, void *self);

void func_ov002_020e7eb8(void *self)
{
    Vector3_16f v;
    int ok = (*(unsigned short *)((char *)self + 0xc) == 0xb3);
    if (!ok)
        return;
    func_ov002_020e8244(&v, self);
    *(void **)((char *)self + 0x4c0) =
        Particle::System::New(*(unsigned int *)((char *)self + 0x4c0),
                              0x10e, v.x, v.y, v.z, 0, 0);
}
}
