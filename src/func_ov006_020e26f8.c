typedef unsigned char u8;

extern u8 data_020a0e40;
extern u8 data_020a0de8[];
extern u8 data_020a0dea[];
extern u8 data_020a0deb[];

#pragma opt_strength_reduction off

void func_ov006_020e26f8(char *self, int idx)
{
    u8 i;
    int n;
    int v;
    int w;
    int x;
    int y;
    int dy;
    int dx;
    char *slot;
    char *base74;
    char *base60;
    char *r2base;

    i = data_020a0e40;
    if (data_020a0de8[i] != 0) {
        n = idx * 0x2c;
        base74 = self + 0x4674;
        base60 = self + 0x4660;
        v = *(int *)(base74 + n);
        *(int *)(base60 + n) = v + (data_020a0dea[i] << 0xc);
        v = *(int *)(base60 + n);
        w = v >> 0xc;
        if (w < 0xe) {
            *(int *)(base60 + n) = 0xe000;
        }
        if (w > 0xf2) {
            *(int *)(base60 + n) = 0xf2000;
        }
        slot = self + n + 0x4000;
        v = *(int *)(base60 + n);
        x = (v >> 0xc) - data_020a0dea[i];
        y = (*(int *)(slot + 0x664) >> 0xc) - data_020a0deb[i];
        *(int *)(base74 + n) = x << 0xc;
        *(int *)(slot + 0x678) = y << 0xc;
        return;
    }

    n = idx * 0x2c;
    *(u8 *)(self + n + 0x4688) = 0;
    r2base = self + 0x4000;
    v = *(int *)(r2base + 0xeb0);
    w = *(int *)(self + n + 0x4660);
    x = *(int *)(self + n + 0x4664);
    y = *(int *)(r2base + 0xeb4);
    dy = (v - w) >> 0xc;
    if (dy < -0x2e) {
        return;
    }
    dx = (y - x) >> 0xc;
    if (dy > 0x2e) {
        return;
    }
    if (dx < -0x14) {
        return;
    }
    if (dx > 0x14) {
        return;
    }
    if (dx <= 0x14) {
        *(int *)(r2base + 0xeb4) = x + 0x15000;
    }
}