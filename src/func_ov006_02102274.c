// NONMATCHING: size 0x1cc vs ROM 0x1f8 (-0x2c); random-bit + dual-branch tail emission order.
extern int RandomIntInternal(int *seed);
extern int func_020126e8(int a);
extern int func_02012468(int a, int b, int c, int d, int e, int f, int g, int h);
extern int data_0209d4b8;

void func_ov006_02102274(char *c, int idx)
{
    char *slot;
    unsigned short *timer;
    char *ip;
    unsigned char bit;

    slot = c + (idx << 6);
    timer = (unsigned short *)(slot + 0x5292);
    if (*timer != 0) {
        *timer = (unsigned short)(*timer - 1);
        if ((short)*timer < 0)
            *timer = 0;
        return;
    }

    ip = slot + 0x5000;
    *(unsigned char *)(ip + 0x296) = 1;

    {
        int r = RandomIntInternal(&data_0209d4b8);
        bit = (unsigned char)(((unsigned int)r >> 16 & 0x7fffu) * 2u >> 15);
        if (idx & 1)
            bit = (unsigned char)(*(unsigned char *)(c + 0x5298) ^ 1u);
        *(unsigned char *)(ip + 0x298) = bit;
    }

    if (*(unsigned char *)(ip + 0x298) != 0) {
        *(unsigned char *)(ip + 0x295) = 1;
        *(int *)(ip + 0x260) = -0x10000;
        *(int *)(ip + 0x268) = 0x200;
        if (*(int *)(c + 0x5668) == 1) {
            *(int *)(ip + 0x268) = 0xf00;
            if (idx == 0) {
                *(unsigned char *)(ip + 0x29b) = *(unsigned char *)(c + 0x529b);
            } else {
                int r = RandomIntInternal(&data_0209d4b8);
                *(unsigned char *)(ip + 0x29b) =
                    (unsigned char)(((unsigned int)r >> 16 & 0x7fffu) * 2u >> 15);
            }
        }
    } else {
        *(unsigned char *)(ip + 0x295) = 1;
        *(int *)(ip + 0x260) = 0x110000;
        *(int *)(ip + 0x268) = -0x200;
        if (*(int *)(c + 0x5668) == 1) {
            *(int *)(ip + 0x268) = -0xf00;
            if (idx == 0) {
                *(unsigned char *)(ip + 0x29b) = *(unsigned char *)(c + 0x529b);
            } else {
                int r = RandomIntInternal(&data_0209d4b8);
                *(unsigned char *)(ip + 0x29b) =
                    (unsigned char)(((unsigned int)r >> 16 & 0x7fffu) * 2u >> 15);
            }
        }
    }

    *(int *)(ip + 0x264) = -0xf8000;
    *(unsigned char *)(ip + 0x299) = 0;
    *(int *)(ip + 0x26c) = 0x2000;
    *(int *)(ip + 0x28c) = func_02012468(
        *(int *)(ip + 0x28c), 2, 0x198, 4, 0, 0, func_020126e8(*(int *)(ip + 0x260)), 0);
}