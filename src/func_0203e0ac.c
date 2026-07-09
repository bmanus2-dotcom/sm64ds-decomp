typedef unsigned short u16;
typedef unsigned char u8;

extern u16 data_020a1040[];
extern u16 data_020a1154[];
extern u16 data_020a11c4[];
extern u16 data_020a11a0[];
extern u16 data_020a117c[];

void func_0203e0ac(void)
{
    u16 t;
    u8 b;
    int i;
    u8 *src;
    u8 *dst;

    data_020a1040[6] = (u16)(data_020a1040[6] & 0x7fff);
    t = data_020a1040[6];
    data_020a1154[0x3d] = data_020a1040[7];
    data_020a1154[0x3c] = t;
    data_020a1154[0x2d] = data_020a1154[0x3d];
    data_020a1154[0x2c] = data_020a1154[0x3c];
    data_020a1154[0x2b] = data_020a1154[0x2d];
    data_020a1154[0x2a] = data_020a1154[0x2c];
    data_020a1154[0x29] = data_020a1154[0x2b];
    data_020a1154[0x28] = data_020a1154[0x2a];
    data_020a1154[0x27] = data_020a1154[0x29];
    data_020a1154[0x26] = data_020a1154[0x28];
    data_020a1154[0x25] = data_020a1154[0x27];
    data_020a1154[0x24] = data_020a1154[0x26];
    data_020a1154[0x23] = data_020a1154[0x25];
    data_020a1154[0x22] = data_020a1154[0x24];
    data_020a1154[0x21] = data_020a1154[0x23];
    data_020a1154[0x20] = data_020a1154[0x22];
    data_020a1154[0x1f] = data_020a1154[0x21];
    data_020a1154[0x1e] = data_020a1154[0x20];
    data_020a1154[0x1d] = data_020a1154[0x1f];
    data_020a1154[0x1c] = data_020a1154[0x1e];
    data_020a1154[0x1b] = data_020a1154[0x1d];
    data_020a1154[0x1a] = data_020a1154[0x1c];
    data_020a1154[0x19] = data_020a1154[0x1b];
    data_020a1154[0x18] = data_020a1154[0x1a];

    data_020a1154[6] = data_020a1040[0];
    data_020a1154[7] = data_020a1040[1];
    data_020a1154[0x38] = data_020a1040[2];
    data_020a1154[0x39] = data_020a1040[3];
    data_020a1154[0x3a] = data_020a1040[4];
    data_020a1154[0x3b] = data_020a1040[5];

    data_020a1154[0x26] = data_020a11c4[0];
    data_020a1154[0x27] = data_020a11c4[1];
    data_020a1154[0x28] = data_020a11c4[2];
    data_020a1154[0x29] = data_020a11c4[3];

    data_020a1154[0x14] = data_020a11a0[0];
    data_020a1154[0x15] = data_020a11a0[1];
    data_020a1154[0x16] = data_020a11a0[2];
    data_020a1154[0x17] = data_020a11a0[3];

    data_020a1154[2] = data_020a117c[0];
    data_020a1154[3] = data_020a117c[1];
    data_020a1154[4] = data_020a117c[2];
    data_020a1154[5] = data_020a117c[3];

    data_020a1154[0x3e] = data_020a1040[8];
    t = data_020a1154[0x3e];
    data_020a1154[0x2c] = t;
    t = data_020a1154[0x2c];
    data_020a1154[0x1a] = t;
    t = data_020a1154[0x1a];
    data_020a1154[8] = t;

    b = *((u8 *)data_020a1040 + 0x12);
    *((u8 *)data_020a1154 + 0x7e) = b;
    b = *((u8 *)data_020a1154 + 0x7e);
    *((u8 *)data_020a1154 + 0x5a) = b;
    b = *((u8 *)data_020a1154 + 0x5a);
    *((u8 *)data_020a1154 + 0x36) = b;
    b = *((u8 *)data_020a1154 + 0x36);
    *((u8 *)data_020a1154 + 0x12) = b;

    src = (u8 *)data_020a1040 + 1;
    dst = (u8 *)data_020a1154 + 1;
    for (i = 1; i < 0x11; i++) {
        b = src[0x12 - 1];
        dst[0x7e - 1] = b;
        dst[0x5a - 1] = dst[0x7e - 1];
        dst[0x36 - 1] = dst[0x5a - 1];
        dst[0x12 - 1] = dst[0x36 - 1];
        src++;
        dst++;
    }
}