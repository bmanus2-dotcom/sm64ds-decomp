extern void func_ov004_020ae5c4(void *a, int b, int c, int d, int e, int f, int g);
extern int func_020126e8(int a);
extern int func_02012468(int a, int b, int c, int d, int e, int f, int g, int h);

extern unsigned char data_020a0e40[];
extern unsigned char data_020a0de8[];
extern unsigned char data_020a0de9[];
extern unsigned char data_020a0dea[];
extern unsigned char data_020a0deb[];

void func_ov006_02123938(char *c)
{
    int sp[4];
    unsigned char idx;
    int cond;

    if (*(short *)(c + 0x7ba4) != 0) {
        if (*(unsigned char *)(c + 0x7bab) == 0) {
            *(unsigned char *)(c + 0x7baa) = 0;
            return;
        }
    }

    idx = data_020a0e40[0];
    if (data_020a0de8[idx * 4] != 0) {
        if (data_020a0de9[idx * 4] != 0) {
            cond = 1;
        } else {
            cond = 0;
        }
    } else {
        cond = 0;
    }

    if (cond != 0) {
        *(short *)(c + 0x7b9c) = (short)data_020a0dea[idx * 4];
        *(short *)(c + 0x7ba0) = *(short *)(c + 0x7b9c);
        *(short *)(c + 0x7b9e) = (short)data_020a0deb[idx * 4];
        *(short *)(c + 0x7ba2) = *(short *)(c + 0x7b9e);
        *(unsigned char *)(c + 0x7baa) = 1;
        *(int *)(c + 0x7b8c) = 0;
        if (*(unsigned char *)(c + 0x7baa) != 1) {
            return;
        }
    }

    if (data_020a0de8[idx * 4] != 0) {
        sp[0] = data_020a0deb[idx * 4];
        sp[1] = 2;
        sp[2] = 4;
        func_ov004_020ae5c4(c, *(short *)(c + 0x7b9c), *(short *)(c + 0x7b9e),
                            data_020a0dea[idx * 4], sp[0], sp[1], sp[2]);
        *(short *)(c + 0x7b9c) = (short)data_020a0dea[idx * 4];
        *(short *)(c + 0x7b9e) = (short)data_020a0deb[idx * 4];
        sp[0] = 0;
        sp[1] = func_020126e8(*(short *)(c + 0x7b9c) << 12);
        sp[2] = 0;
        sp[3] = 0;
        *(int *)(c + 0x7b8c) = func_02012468(*(int *)(c + 0x7b8c), 2, 0x1b0, 4, 0, 0, sp[1], 0);
        return;
    }

    if (data_020a0de9[idx * 4] != 0) {
        *(unsigned char *)(c + 0x7bab) = 1;
    }
}