//cpp
typedef int Fix12i;
struct SharedFilePtr { void Release(); };
namespace Particle {
struct System {
    static System *NewSimple(unsigned int, Fix12i, Fix12i, Fix12i);
};
}
extern "C" {
extern SharedFilePtr data_ov002_0210d9d8;
extern SharedFilePtr data_ov002_0210da30;

int func_ov002_020affe8(char *self)
{
    unsigned int v = *(unsigned int *)(self + 0x384);
    if (v != 0xb && v != 0xc) {
        int isLoad = (*(unsigned short *)(self + 0xc) == 0x114);
        if (isLoad)
            data_ov002_0210d9d8.Release();
        else
            data_ov002_0210da30.Release();
    }
    if (*(unsigned int *)(self + 0x384) - 0xb <= 1)
        Particle::System::NewSimple(0xd2,
                                    *(Fix12i *)(self + 0x5c),
                                    *(Fix12i *)(self + 0x60) + 0x28000,
                                    *(Fix12i *)(self + 0x64));
    return 1;
}
}
