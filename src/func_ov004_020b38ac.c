typedef long long s64;
typedef unsigned short u16;
extern int func_02053200(int x);
extern void func_ov004_020b1c68(void *a0, int a1, int a2, int a3, int a4, int a5);

void func_ov004_020b38ac(char *sl)
{
    int s[4];
    char *sb;
    int base;
    int step;
    int w0;
    int *sp8;
    int zero;
    u16 lim;

    {
        int tmp = *(int *)(sl + 0x24);
        sb = sl + 0x34;
        base = tmp >> 2;
    }
    step = 0x1000;
    w0 = step;
    sp8 = s;
    zero = 0;
    lim = 0xffff;
    do {
        int d = base - step;
        int weight = w0;
        int w;
        if (d < 0)
            d = -d;
        if (d < 0x1000) {
            s64 t = (s64)(0x1000 - d) << 10;
            t = t + 0x800;
            weight = weight + (int)(t >> 12);
        }
        w = func_02053200(weight);
        sp8[0] = zero;
        sp8[1] = zero;
        sp8[2] = zero;
        sp8[3] = zero;
        s[0] = w;
        s[3] = w;
        func_ov004_020b1c68(sb, *(short *)(sl + 0x10), *(short *)(sl + 0x12),
                            *(int *)(sl + 0x1c), *(int *)(sl + 0x18), (int)sp8);
        {
            u16 field = *(u16 *)(sb + 6);
            step += 0x1000;
            sb += 8;
            if (field == lim)
                break;
        }
    } while (1);
}
