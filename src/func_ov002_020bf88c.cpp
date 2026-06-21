//cpp
typedef int Fix12i;
namespace Particle {
void RunningSlidingDustAt(Fix12i, Fix12i, Fix12i);
}
extern "C" {
extern void func_02022b04(Fix12i x, Fix12i y, Fix12i z);
extern int data_0208e430;

void func_ov002_020bf88c(char *self)
{
    if (*(unsigned char *)(self + 0x707))
        return;
    if (data_0208e430 == 0x2e)
        return;
    if (*(unsigned char *)(self + 0x703))
        Particle::RunningSlidingDustAt(*(Fix12i *)(self + 0x5c),
                                       *(Fix12i *)(self + 0x60),
                                       *(Fix12i *)(self + 0x64));
    else
        func_02022b04(*(Fix12i *)(self + 0x5c),
                      *(Fix12i *)(self + 0x60),
                      *(Fix12i *)(self + 0x64));
}
}
