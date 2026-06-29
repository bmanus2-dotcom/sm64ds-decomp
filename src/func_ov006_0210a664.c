typedef int Bool;

struct Scene;

extern Bool func_ov004_020b04f4(struct Scene* self);
extern void _ZN8Particle9RenderAllEv(void);

Bool func_ov006_0210a664(struct Scene* self)
{
    if (!func_ov004_020b04f4(self))
        return 0;
    _ZN8Particle9RenderAllEv();
    return 1;
}
