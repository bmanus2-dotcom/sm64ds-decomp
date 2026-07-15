// NONMATCHING: size exact; loop kernel + else prologue residual (div=25, mwccarm 1.2/sp2p3).
typedef short s16;
typedef unsigned short u16;
typedef long long s64;

extern int _ZN4cstd4fdivEii(int a, int b);
extern int func_02053200(int x);
struct M { int _00, _01, _10, _11; };
extern void func_ov004_020b1c68(void* a0, int a1, int a2, int a3, int a4, struct M* a5);

void func_ov004_020b4360(char* self) {
    u16 flag;
    u16 lim = 0xffff;
    int z = 0;
    int k = 0x1000;

    if (*(int*)(self + 0x24) == 0) return;
    {
        char* el = self + 0x34;
        if (*(int*)(self + 0x24) < 0x1e000) {
            int d;
            int scale;
            if (*(int*)(self + 0x24) < 0x14000) {
                d = (int)((((s64)*(int*)(self + 0x24) << 8) + 0x800) >> 12);
                scale = (int)(((s64)_ZN4cstd4fdivEii(d, 0x1400) * 0x1400 + 0x800) >> 12);
            } else {
                int a = (int)(((s64)(*(int*)(self + 0x24) - 0x14000) * 0x66 + 0x800) >> 12);
                int b = 0x1400 - a;
                int t = _ZN4cstd4fdivEii(b - 0x1000, 0x400);
                scale = (0x1000 - t) + (int)(((s64)t * 0x1400 + 0x800) >> 12);
                d = b;
            }
            d = func_02053200(d);
            {
                struct M m = {0};
                m._00 = d;
                m._11 = d;
                scale = 0x1000 - scale;
                do {
                    int q = (unsigned)(*(int*)el << 7) >> 0x17;
                    q = (q << 16) >> 16;
                    if (q > 0x100) {
                        q = q - 0x200;
                        q = (q << 16) >> 16;
                    }
                    func_ov004_020b1c68(el,
                                        *(s16*)(self + 0x10) - (((q * scale) << 4) >> 16),
                                        *(s16*)(self + 0x12),
                                        *(int*)(self + 0x1c),
                                        *(int*)(self + 0x18),
                                        &m);
                    flag = *(u16*)(el + 6);
                    el += 8;
                } while (flag != lim);
            }
        } else {
            int idx = (*(int*)(self + 0x24) - 0x1e000) >> 2;
            int i = k;
            int wbase = k;
            struct M m2;
            int z2 = 0;
            struct M* mp = &m2;
            do {
                int diff = idx - i;
                int weight = wbase;
                if (diff < 0) diff = -diff;
                if (diff < 0x1000) {
                    weight += (int)((((s64)(0x1000 - diff) << 10) + 0x800) >> 12);
                }
                weight = func_02053200(weight);
                mp->_00 = z2;
                mp->_01 = z2;
                mp->_10 = z2;
                mp->_11 = z2;
                m2._00 = weight;
                m2._11 = weight;
                func_ov004_020b1c68(el, *(s16*)(self + 0x10), *(s16*)(self + 0x12),
                                    *(int*)(self + 0x1c), *(int*)(self + 0x18), mp);
                flag = *(u16*)(el + 6);
                i += 0x1000;
                el += 8;
            } while (flag != lim);
        }
    }
}
