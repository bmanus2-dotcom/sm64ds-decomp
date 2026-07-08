extern void _ZN3G2x13SetBlendAlphaEPVttttt(volatile void *reg,
    unsigned short a, unsigned short b, int c, unsigned short d);
extern void func_ov006_020cd424(unsigned int n, int arg1);
extern void func_ov006_020d0b04(int a);
extern void func_ov006_02120ca0(void);
extern int func_ov004_020ad674(void);
extern void func_ov006_020c8a9c(int a0, int a1);
extern void func_ov006_02120a44(char *p);
extern int RandomIntInternal(int *seed);
extern void func_ov006_02121750(char *c, short v);
extern int func_02054d88(void);
extern void MultiStore16(unsigned short val, char *dst, int nbytes);
extern void func_ov006_02121f04(char *o);

extern volatile short data_020a0dbc[];
extern int data_ov006_02142f60;
extern int data_ov006_0213fb18[];
extern int data_0209e650;

void func_ov006_02121fa4(char *o)
{
    volatile unsigned short fill;
    int q;

    _ZN3G2x13SetBlendAlphaEPVttttt((volatile void *)0x4000050, 1, 0x3e, 0x10, 0x10);

    *(short *)(o + 0x5db4) = data_020a0dbc[0];
    *(short *)(o + 0x5db6) = data_020a0dbc[1];
    *(short *)(o + 0x5db0) = data_020a0dbc[0];
    *(short *)(o + 0x5db2) = data_020a0dbc[1];

    data_ov006_02142f60 = 0;
    *(int *)(o + 0xbc) = 0;
    if ((unsigned int)*(int *)(o + 0xbc) > 0x270e)
        *(int *)(o + 0xbc) = 0x270e;
    q = (((*(int *)(o + 0xbc) % 5) << 12)) / 4;
    *(int *)(o + 0x5d94) =
        (int)(((long long)(0x1000 - q) * 0x20 + 0x800) >> 12) +
        (int)(((long long)q * 0x50 + 0x800) >> 12);
    *(int *)(o + 0x5d98) = *(int *)(o + 0x5d94);
    *(int *)(o + 0x5d9c) = 0;
    func_ov006_020cd424(*(int *)(o + 0xbc), *(int *)(o + 0x5d94));

    func_ov006_020d0b04(*(int *)(o + 0xbc));
    func_ov006_02120ca0();
    func_ov006_020c8a9c(0, data_ov006_0213fb18[func_ov004_020ad674()]);

    func_ov006_02120a44(o + 0x5d84);

    *(short *)(o + 0x5db8) = 0;
    *(short *)(o + 0x5dc2) = 0;
    *(short *)(o + 0x5dbc) =
        (((int)(((unsigned int)RandomIntInternal(&data_0209e650) & 0x7fffffff) >> 0x13)
            * 0x2d0) >> 12) + 0x2d0;
    *(short *)(o + 0x5dbe) = 0;
    *(short *)(o + 0x5dc0) = 1;
    *(int *)(o + 0x5da4) = 0;
    *(int *)(o + 0x5da8) = 0;

    func_ov006_02121750(o, 0);

    {
        char *dst = (char *)func_02054d88();
        fill = 0;
        MultiStore16(fill, dst, 0x6000);
    }

    func_ov006_02121f04(o);
}
