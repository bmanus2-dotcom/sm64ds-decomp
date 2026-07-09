// NONMATCHING: data_020a0e40 table branch + func_02012468 setup (div~28, 0x1b8 vs 0x1d4)
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 data_020a0e40;
extern u8 data_020a0de8[];
extern u8 data_020a0de9[];
extern u8 data_020a0dea[];
extern u8 data_020a0deb[];

extern int func_ov004_020ae5c4(void *a, int b, int c, int d, int e, int f, int g);
extern int func_020126e8(int a);
extern int func_02012468(int a, int b, int c, int d, int e, int f, int g, int h);

void func_ov006_0212157c(char *c)
{
    u8 e;
    int ok;
    int sp0;
    int sp4;
    int sp8;
    short x;
    short y;

    if (*(short *)(c + 0x5db8) == 0) {
        *(u8 *)(c + 0x5dc4) = 0;
        return;
    }
    e = data_020a0e40;
    ok = 0;
    if (data_020a0de8[e * 4] != 0) {
        if (data_020a0de9[e * 4] != 0) {
            ok = 1;
        }
    }
    if (ok != 0) {
        *(u16 *)(c + 0x5db0) = data_020a0dea[e * 4];
        x = *(short *)(c + 0x5db0);
        *(u16 *)(c + 0x5db4) = x;
        *(u16 *)(c + 0x5db2) = data_020a0deb[e * 4];
        y = *(short *)(c + 0x5db2);
        *(u16 *)(c + 0x5db6) = y;
        *(u8 *)(c + 0x5dc4) = 1;
        *(int *)(c + 0x5dac) = 0;
    }
    if (*(u8 *)(c + 0x5dc4) != 1) {
        return;
    }
    e = data_020a0e40;
    if (data_020a0de8[e * 4] != 0) {
        sp0 = data_020a0deb[e * 4];
        sp4 = 2;
        sp8 = 4;
        func_ov004_020ae5c4(c, *(short *)(c + 0x5db0), *(short *)(c + 0x5db2),
                            sp0, sp4, data_020a0dea[e * 4], sp8);
        e = data_020a0e40;
        *(u16 *)(c + 0x5db0) = data_020a0dea[e * 4];
        *(u16 *)(c + 0x5db2) = data_020a0deb[e * 4];
        *(int *)(c + 0x5dac) = func_02012468(*(int *)(c + 0x5dac), 2, 0x1b0, 4, 0, 0,
                                             func_020126e8(*(short *)(c + 0x5db0) << 12), 0);
        return;
    }
    if (data_020a0de8[e * 4] == 0) {
        if (data_020a0de9[e * 4] != 0) {
            *(u8 *)(c + 0x5dc5) = 1;
        }
    }
}