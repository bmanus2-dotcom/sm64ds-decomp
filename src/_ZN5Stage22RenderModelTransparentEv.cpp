//cpp
typedef unsigned char u8;
typedef unsigned short u16;

struct VBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(void *arg);
};

extern "C" {
extern char *data_0209f340;
extern char data_020755d4;
}

extern "C" void _ZN5Stage22RenderModelTransparentEv(char *c)
{
    char *p = (char *)(((int)c + 0x874) & 0xFFFFFFFFFFFFFFFF);
    char *arr = *(char **)(*(char **)p + 8);
    char *q = c + 0x8bc;
    int i;
    for (i = 0; i < *(u8 *)(data_0209f340 + 0x14); i++, q += 0xc, arr += 0x40) {
        if (*(u8 *)(q + 4) != 0) {
            u8 *bp = *(u8 **)(arr + 0x34);
            u16 j;
            for (j = 0; j < *(u16 *)(arr + 0x30); j++) {
                char *e = *(char **)(p + 4) + *bp * 0x30;
                if ((*(int *)(e + 0x24) & 0x1f0000) != 0x1f0000)
                    *(int *)(((int)e + 0x24) & 0xFFFFFFFFFFFFFFFF) &= ~0x80000000;
                else
                    *(int *)(((int)e + 0x24) & 0xFFFFFFFFFFFFFFFF) |= 0x80000000;
                bp++;
            }
        }
    }
    ((VBase *)(c + 0x86c))->m5(&data_020755d4);
}
