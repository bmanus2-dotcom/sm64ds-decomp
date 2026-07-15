// NONMATCHING: loop a4-hoist / regperm residual (div=13, mwccarm 1.2/sp2p3).
typedef long long s64;
typedef short s16;
typedef unsigned short u16;
extern int _ZN4cstd4fdivEii(int, int);
extern int func_02053200(int x);
struct M { int _00, _01, _10, _11; };
extern void func_ov004_020b1c68(void* a0, int a1, int a2, int a3, int a4, struct M* a5);
void func_ov004_020b3b38(char* c) {
    if (*(int*)(c + 0x24) == 0) return;
    int m = (int)(((s64)*(int*)(c + 0x24) * 0xcc + 0x800) >> 12);
    char* el = c + 0x34;
    int scale = (int)(((s64)_ZN4cstd4fdivEii(m, 0x1000) * 0x1000 + 0x800) >> 12);
    int v = func_02053200(m);
    struct M mat = {0};
    mat._00 = v; mat._11 = v;
    scale = 0x1000 - scale;
    u16 lim = 0xffff; u16 flag;
    do {
        int q = (unsigned)(*(int*)el << 7) >> 0x17;
        q = (q << 16) >> 16;
        if (q > 0x100) {
            q = q - 0x200;
            q = (q << 16) >> 16;
        }
        func_ov004_020b1c68(el,
            *(s16*)(c + 0x10) - (((q * scale) << 4) >> 16),
            *(s16*)(c + 0x12), *(int*)(c + 0x1c), *(int*)(c + 0x18), &mat);
        flag = *(u16*)(el + 6);
        el += 8;
    } while (flag != lim);
}
