#pragma opt_strength_reduction off
#pragma opt_common_subs off
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void func_ov004_020afdd0(void* a0, int a1, int a2, int a3, int a4);
extern void func_0203cd80(int *m, short angle);
extern void func_ov006_02126a98(char *c);
extern int func_ov004_020b04c0(void);
extern void func_ov004_020b2220(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void func_ov004_020b2444(int a1, int a2, int num, int a4, int a5, int sel, int idx);
extern s32 func_ov004_020ad674(void);
extern void func_ov004_020b0380(void* a0, int a1, int a2, void* a3);
extern void func_ov006_02129690(void *a);
extern void func_ov006_02125804(char *c);

extern void* data_ov006_02139d24[2];
extern void* data_ov006_02138d64[];
extern void* data_ov006_02139c24;
extern void* data_ov006_02139c80[];
extern void* data_ov006_02139d18;
extern void* data_ov006_02139c38;
extern void* data_ov006_0213fff0[];

int func_ov006_02127d10(char *c)
{
    int m[3];
    int vecArr[3];

    *(int*)(((long long)(int)(c + 0xb9d8)) & 0xFFFFFFFFFFFFFFFFLL) = *(int*)(((long long)(int)(c + 0xb9d8)) & 0xFFFFFFFFFFFFFFFFLL) + 1;
    if (*(int*)(c + 0xb9d8) >= 0x20) {
        *(int*)(c + 0xb9d8) = 0;
    }

    {
        int base = *(int*)(c + 0xba04);
        int t = (((*(int*)(c + 0xab3c) >> 0xc) - base) * 0x7c) / (*(int*)(c + 0xba00) - base);
        func_ov004_020afdd0(data_ov006_02139d24[0], 0xf0, t + 0x22, -1, 0);
    }
    func_ov004_020afdd0(data_ov006_02139d24[1], 0xf0, 0x60, -1, 0);

    m[2] = 0xfffff008;
    m[1] = 0;
    m[0] = 0;
    func_0203cd80(m, -0x2000);
    *(volatile int*)0x040004c8 =
        (((short)m[0] >> 3) & 0x3ff) |
        ((((short)m[1] >> 3) & 0x3ff) << 10) |
        ((((short)m[2] >> 3) & 0x3ff) << 20);
    *(int*)0x040004cc = 0x7fff;

    {
        int v = *(int*)(c + 0xaba0);
        int t = v / 2 + v * 4;
        vecArr[0] = t;
        vecArr[1] = t;
        vecArr[2] = t;
        if (*(int*)(c + 0xaba0) > 0) {
            void *self = (void*)(((long long)(int)(c + 0xaba4)) & 0xFFFFFFFFFFFFFFFFLL);
            void (*fn)(void*, int*) = *(void(**)(void*, int*))((char*)(*(void**)self) + 0x14);
            fn(self, vecArr);
        }
    }

    func_ov006_02126a98(c);

    for (int i1 = 0; i1 < 0x80; i1++) {
        char *p = c + i1;
        if (*(u8*)(p + 0xac58) == 1) {
            int t6 = *(int*)(c + 0xab6c);
            int t5 = *(int*)(((long long)(int)(c + i1 * 8 + 0xacdc)) & 0xFFFFFFFFFFFFFFFFLL);
            if (t5 >= t6 - 0x20000 && t5 < t6 + 0x1a0000 + (func_ov004_020b04c0() << 0xc)) {
                if (*(int*)(c + i1 * 4 + 0xb0d8) == 1) {
                    int cnt = *(int*)(c + 0xb9d8);
                    int idx = (cnt / 4) & 7;
                    if (*(u8*)(p + 0xb2d8) == 1) idx += 8;
                    int a1 = (*(int*)(c + i1 * 8 + 0xacd8) - *(int*)(c + 0xab68)) >> 0xc;
                    int a2 = ((t5 - t6) >> 0xc) - 0x110;
                    func_ov004_020afdd0(data_ov006_02138d64[idx], a1, a2, -1, -1);
                } else {
                    int a1 = (*(int*)(c + i1 * 8 + 0xacd8) - *(int*)(c + 0xab68)) >> 0xc;
                    int a2 = ((t5 - t6) >> 0xc) - 0x110;
                    func_ov004_020afdd0(data_ov006_02139c24, a1, a2, -1, 2);
                }
            }
        }
    }

    for (int i2 = 0; i2 < 0x80; i2++) {
        if (*(u8*)(c + i2 + 0xb358) == 1) {
            int t7 = *(int*)(c + 0xab6c);
            int t6 = *(int*)(((long long)(int)(c + i2 * 8 + 0xb5dc)) & 0xFFFFFFFFFFFFFFFFLL);
            if (t6 >= t7 - 0x40000 && t6 < t7 + 0x1c0000 + (func_ov004_020b04c0() << 0xc)) {
                switch (*(int*)(c + i2 * 4 + 0xb3d8)) {
                case 0:
                case 1:
                case 2: {
                    int a1 = (*(int*)(c + i2 * 8 + 0xb5d8) - *(int*)(c + 0xab68)) >> 0xc;
                    int a2 = ((t6 - t7) >> 0xc) - 0x110;
                    func_ov004_020afdd0(data_ov006_02139d18, a1, a2, -1, 1);
                    break;
                }
                case 3: {
                    int v = *(int*)(c + i2 * 8 + 0xb5d8);
                    int sel = (v < 0x80000) ? 1 : 0;
                    int a1 = (v - *(int*)(c + 0xab68)) >> 0xc;
                    int a2 = ((t6 - t7) >> 0xc) - 0x110;
                    func_ov004_020afdd0(data_ov006_02139c80[sel], a1, a2, -1, 1);
                    break;
                }
                }
            }
        }
    }

    {
        int a1 = (*(int*)(c + 0xab48) - *(int*)(c + 0xab68)) >> 0xc;
        int a2 = ((*(int*)(c + 0xab4c) - *(int*)(c + 0xab6c)) >> 0xc) - 0x110;
        func_ov004_020afdd0(data_ov006_02139c38, a1, a2, -1, 2);
    }

    {
        int t4 = *(int*)(c + 0xb9fc);
        if (t4 <= 0xf0 && t4 > 0x3c) {
            int q = t4 / 60;
            if (q >= 4) q = 3;
            func_ov004_020b2220(0x80, 0x60, q, -1, -1, 0x800, 0);
        } else {
            int mode = *(int*)(c + 0xb9f4);
            if (mode == 1 || mode == 2
                || (mode == 3 && *(int*)(c + 0xba10) > 0)
                || (mode == 4 && *(int*)(c + 0xba0c) <= 0x3c)) {
                int v = *(int*)(c + 0xb9dc);
                int q60 = v / 60;
                int rem60 = v % 60;
                int r7 = rem60 * 100;
                int centis = r7 / 60;
                int r4;
                int tens;
                int ones;
                if (v < 0x258) {
                    r4 = 0xc;
                } else if (v >= 0x276) {
                    r4 = -0x104;
                } else {
                    r4 = ((0x258 - v) * 0x110) / 30 + 0xc;
                }
                func_ov004_020b2444(0x84, r4, q60, -1, -1, 1, 0);
                tens = centis / 10;
                func_ov004_020b2444(0x9c, r4, tens, -1, -1, 1, 0);
                ones = centis % 10;
                if (ones == 5 || ones == 0) {
                    func_ov004_020b2444(0xac, r4, ones, -1, -1, 1, 0);
                } else {
                    func_ov004_020b2444(0xac, r4, ones + 1, -1, -1, 1, 0);
                }
                {
                    int idx = func_ov004_020ad674();
                    func_ov004_020b0380(*(void**)((char*)data_ov006_0213fff0[idx] + 0xc), 0x5c, r4, 0);
                }
                {
                    int idx = func_ov004_020ad674();
                    func_ov004_020b0380(*(void**)((char*)data_ov006_0213fff0[idx] + 0x1c), 0x90, r4, 0);
                }
            }
        }
    }

    func_ov006_02129690(c);
    func_ov006_02125804(c);
    return 1;
}
