//cpp
struct VObj {
    virtual void vfunc0();
};
struct Camera;

extern "C" void func_ov006_020c0aa8(Camera *self);
extern "C" int func_ov006_020da5e8(void *a, void *b);
extern "C" int func_ov006_020da4ac(void *a, int b);
extern "C" int func_ov004_020afa20(int a0, int a1, int a2, int a3, int a4);
extern "C" void func_ov004_020b1bc8(char *a0, int a1, int a2, int a3);
extern "C" void func_ov004_020b1e34(void *a0, int a1, int a2, int a3);
extern "C" void func_ov004_020adb1c(int self);
extern "C" void func_ov004_020b6430(void);
extern "C" void func_ov006_020d9a14(char *thiz);
extern "C" void func_ov006_020c1804(void *a);

extern int data_ov006_02134010[6];
extern int data_ov006_02134028;

extern "C" int func_ov006_020da9c4(char *c)
{
    short state;
    int excl;
    int i;
    int slot;
    short flags;
    int max;

    func_ov006_020c0aa8((Camera *)(c + 0x4660));

    state = *(short *)(c + 0x5388);
    if (state > 3 && state < 0x11) {
        excl = -1;
        if (state > 0xe) {
            flags = *(short *)(c + 0x5396);
            if (flags & 8) {
                if (func_ov006_020da5e8(c + 0x51a8, c + 0x5298) == 1) {
                    excl = 6 - func_ov006_020da4ac(c + 0x51a8, 0);
                }
            }
        }

        i = 0;
        slot = 0xc;
        for (; i < 6; i++) {
            if (i != excl) {
                func_ov004_020afa20(data_ov006_02134010[i], 0x28, slot, -1, -1);
            }
            slot += 0x10;
        }
        func_ov004_020afa20(data_ov006_02134028, 0x28, 0x38, -1, -1);
    }

    func_ov004_020b1bc8(c, 0xc, 0xc, 0);
    func_ov004_020b1e34(c, 0xe0, 0x14, 1);

    max = *(int *)(c + 0xb4);
    if (*(short *)(c + 0x5398) < max) {
        *(short *)(c + 0x5398) = (short)max;
    }
    func_ov004_020adb1c(*(short *)(c + 0x5398));

    func_ov004_020b6430();
    func_ov006_020d9a14(c);

    {
        int j;
        char *b6;
        VObj *b5;
        b6 = c + 0xc0;
        {
            char *tmp5 = c + 0x51a8;
            b5 = (VObj *)(((int)tmp5 + 0xc0) & 0xFFFFFFFFFFFFFFFF);
        }
        for (j = 4; j >= 0; j--) {
            unsigned char rval = *(unsigned char *)(b6 + 0x5000 + 0x1d2);
            if (*(short *)(c + 0x538e) == rval) {
                goto flagcheck1;
            }
            if (*(short *)(c + 0x5390) != rval) {
                goto call1;
            }
        flagcheck1:
            if (*(short *)(c + 0x5396) & 8) {
            call1:
                { b5->vfunc0(); }
            }
            b6 -= 0x30;
            b5 = (VObj *)((char *)b5 - 0x30);
        }
    }

    {
        int j;
        char *b6;
        VObj *b5;
        b6 = c + 0xc0;
        {
            char *tmp5 = c + 0x5298;
            b5 = (VObj *)(((int)tmp5 + 0xc0) & 0xFFFFFFFFFFFFFFFF);
        }
        for (j = 4; j >= 0; j--) {
            unsigned char rval = *(unsigned char *)(b6 + 0x5000 + 0x2c2);
            if (*(short *)(c + 0x5392) == rval) {
                goto flagcheck2;
            }
            if (*(short *)(c + 0x5394) != rval) {
                goto call2;
            }
        flagcheck2:
            if (*(short *)(c + 0x5396) & 8) {
            call2:
                { b5->vfunc0(); }
            }
            b6 -= 0x30;
            b5 = (VObj *)((char *)b5 - 0x30);
        }
    }

    func_ov006_020c1804(c + 0x4f38);
    return 1;
}
