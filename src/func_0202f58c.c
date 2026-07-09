struct Obj { int f; };

extern unsigned char data_0209f5f8;
extern unsigned int data_0209f608;
extern unsigned int data_0209f60c;
extern unsigned char data_0209f5fc;
extern void func_0202f290(struct Obj* o);

void func_0202f58c(struct Obj* c)
{
    unsigned short v;
    unsigned short* r1;
    unsigned short* r0;
    unsigned short* lr;
    unsigned short* ip;
    unsigned int* r3;

    *(unsigned char*)((char*)c + 0xe) = 1;

    r1 = (unsigned short*)0x4000048;
    r0 = (unsigned short*)0x4001048;
    lr = (unsigned short*)0x400004a;
    ip = (unsigned short*)0x400104a;

    v = *r1;
    v = (v & ~0x3f) | 0x1f;
    v |= 0x20;
    *r1 = v;

    v = *r0;
    v = (v & ~0x3f) | 0x1f;
    v |= 0x20;
    *r0 = v;

    v = *r1;
    v = (v & ~0x3f00) | 0x1f00;
    v |= 0x2000;
    *r1 = v;

    v = *r0;
    v = (v & ~0x3f00) | 0x1f00;
    v |= 0x2000;
    *r0 = v;

    v = *lr;
    v &= ~0x3f;
    *lr = v;

    v = *ip;
    v &= ~0x3f;
    *ip = v;

    r3 = (unsigned int*)0x4000000;
    v = (unsigned short)*r3;
    *(unsigned int*)r3 = (*(unsigned int*)r3 & ~0xe000) | 0x6000;

    if (data_0209f5f8 != 0) {
        unsigned int* p = (unsigned int*)0x4001000;
        unsigned int t = *p;
        *p = t & ~0xe000;
    } else {
        unsigned int* p = (unsigned int*)0x4001000;
        unsigned int t = *p;
        *p = (t & ~0xe000) | 0x6000;
    }

    data_0209f608 = 0;
    data_0209f60c = 0;
    func_0202f290(c);

    data_0209f608 = 1;
    data_0209f60c = 1;
    data_0209f5fc = 0;
    func_0202f290(c);

    v = *(unsigned short*)0x4000050;
    if ((v & 0x80) == 0x80)
        *(unsigned short*)0x4000050 = 0;

    v = *(unsigned short*)0x4001050;
    if ((v & 0x80) == 0x80)
        *(unsigned short*)0x4001050 = 0;
}