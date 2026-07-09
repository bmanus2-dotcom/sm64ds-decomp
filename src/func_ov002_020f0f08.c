typedef unsigned short u16;
typedef unsigned char u8;

struct Mtx43 { int m[12]; };

extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int id, int x, int y, int z);
extern void _ZN9ActorBase18MarkForDestructionEv(char *c);
extern void *_ZN5Actor10FindWithIDEj(unsigned int id);
extern void Matrix4x3_FromTranslation(struct Mtx43 *m, int x, int y, int z);

int func_ov002_020f0f08(char *c)
{
    int sp[3];
    void *obj;
    int dy;

    if (*(u16 *)(c + 0x14c) != 0)
        return 1;

    *(int *)(c + 0xa8) += *(int *)(c + 0x9c);
    if (*(int *)(c + 0xa8) < *(int *)(c + 0xa0))
        *(int *)(c + 0xa8) = *(int *)(c + 0xa0);
    *(int *)(c + 0x60) += *(int *)(c + 0xa8);

    if (*(u8 *)(c + 0x14e) == 0) {
        if (*(int *)(c + 0x60) < *(int *)(c + 0x140)) {
            *(int *)(c + 0x60) = *(int *)(c + 0x140);
            *(int *)(c + 0xa8) = 0xf000;
            *(u8 *)(c + 0x14e) = *(u8 *)(c + 0x14e) + 1;
        }
    } else if (*(u8 *)(c + 0x14e) == 1) {
        if (*(int *)(c + 0x60) < *(int *)(c + 0x140)) {
            _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0xd2, *(int *)(c + 0x5c), *(int *)(c + 0x60), *(int *)(c + 0x64));
            _ZN9ActorBase18MarkForDestructionEv(c);
        }
    }

    sp[0] = *(int *)(c + 0x5c);
    sp[1] = *(int *)(c + 0x60);
    sp[2] = *(int *)(c + 0x64);

    if (*(int *)(c + 0x138) != 0) {
        obj = _ZN5Actor10FindWithIDEj(*(unsigned int *)(c + 0x138));
        if (obj != 0) {
            sp[0] = *(int *)((char *)obj + 0x5c);
            sp[1] = *(int *)((char *)obj + 0x60);
            sp[2] = *(int *)((char *)obj + 0x64);
            dy = *(int *)(c + 0x60) - *(int *)(c + 0x140);
            sp[1] = dy + *(int *)(c + 0x148) + sp[1];
        }
    }

    Matrix4x3_FromTranslation((struct Mtx43 *)(c + 0xf0), sp[0] >> 3, sp[1] >> 3, sp[2] >> 3);
    return 1;
}