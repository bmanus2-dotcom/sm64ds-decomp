typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef long long s64;

extern s16 data_02082214[];
extern s32 data_ov006_0213db9c[];
extern s32 _ZN4cstd5atan2E5Fix12IiES1_(s32 y, s32 x);
extern void func_ov006_020ff4ec(char *base, int idx);

void func_ov006_02100bac(char *r6, int r5)
{
    char *r3;
    u16 r0;

    r3 = r6 + (r5 << 6);
    r0 = *(u16 *)(r3 + 0x5292);
    if (r0 != 0) {
        r0--;
        *(u16 *)(r6 + 0x5292 + (r5 << 6)) = r0;
        if ((s16)*(u16 *)(r3 + 0x5292) < 0)
            *(u16 *)(r3 + 0x5292) = 0;
        return;
    }
    {
        s32 dx;
        s32 ang;
        s32 vel;
        s32 tmp;
        s32 dy;
        s32 x;
        s32 y;
        char *ip;
        s64 prod;

        ip = r3 + 0x5000;
        dx = data_ov006_0213db9c[*(int *)(ip + 0x668) * 4 + r5];
        y = *(s32 *)(ip + 0x260);
        x = *(s32 *)(ip + 0x264);
        ang = _ZN4cstd5atan2E5Fix12IiES1_(dx - (x >> 0xc), 0x80 - (y >> 0xc));
        *(u16 *)(r3 + 0x5290) = (u16)ang;
        vel = *(s32 *)(ip + 0x270);
        prod = (s64)data_02082214[((ang >> 4) << 1) + 1] * vel + 0x800;
        tmp = (s32)(prod >> 0xc);
        *(s32 *)(r6 + 0x5260 + (r5 << 6)) += tmp;
        prod = (s64)data_02082214[(ang >> 4) << 1] * vel + 0x800;
        tmp = (s32)(prod >> 0xc);
        *(s32 *)(r6 + 0x5264 + (r5 << 6)) += tmp;
        *(s32 *)(r6 + 0x5270 + (r5 << 6)) += 0x100;
        dy = (y >> 0xc) - 0x80;
        dx = (x >> 0xc) - dx;
        if (dy < -2 || dy > 3 || dx < -2 || dx > 3) {
            *(s32 *)(ip + 0x260) = 0x80000;
            *(s32 *)(ip + 0x264) = dx << 0xc;
            *(u8 *)(ip + 0x296) = 0xd;
            func_ov006_020ff4ec(r6, r5);
            *(u16 *)(r3 + 0x5292) = 0x40;
            if (r5 & 1)
                *(u16 *)(r3 + 0x5292) += 0x20;
        }
    }
}