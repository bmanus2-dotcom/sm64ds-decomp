extern int data_ov006_0213d56c;
extern int data_ov006_021424f4;
extern void *data_ov006_02142504;
extern void func_0203d6d0(int *o, int *a, int *b);
extern void func_0203d630(int *p, int m);

void func_ov006_020f8320(char *o, int n)
{
    int t;
    int sp[2];
    int q;
    int r;

    if (n >= 0x14)
        return;
    if (*(short *)(o + 0x2a) >= 0x14) {
        t = data_ov006_0213d56c;
        t = -(((((t >> 2) << 1) - 0x70) << 12));
        *(int *)(o + 0xc) = t;
        *(int *)(o + 0x10) = 0x30000;
        data_ov006_02142504 = o;
        *(unsigned char *)(o + 0x2d) = 1;
    } else if (*(unsigned char *)(o + 0x2d) == 0) {
        t = data_ov006_0213d56c;
        t = (((t >> 2) << 1) - 0x70) << 12;
        *(int *)(o + 0xc) = t;
        *(int *)(o + 0x10) = 0x30000;
        *(unsigned char *)(o + 0x2d) = 4;
        data_ov006_021424f4 += 1;
    } else {
        *(unsigned char *)(o + 0x2d) = 4;
        data_ov006_021424f4 += 1;
        q = n / 5;
        r = n - q * 5;
        t = (r << 5) + 0x30;
        *(int *)(o + 0x14) = t << 12;
        t = ((n / 5) * 0x30) << 12;
        *(int *)(o + 0x18) = t;
        *(short *)(o + 0x2a) = (short)n;
        func_0203d6d0(sp, (int *)(o + 0x14), (int *)(o + 0xc));
        *(int *)(o + 0x1c) = sp[0];
        *(int *)(o + 0x20) = sp[1];
        func_0203d630((int *)(o + 0x1c), 0x124);
        if (*(int *)(o + 0x1c) < 0)
            *(int *)(o + 0x1c) = -*(int *)(o + 0x1c);
        if (*(int *)(o + 0x20) < 0)
            *(int *)(o + 0x20) = -*(int *)(o + 0x20);
    }
}