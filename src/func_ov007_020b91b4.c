// NONMATCHING: register allocation (div=27). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern char *data_ov007_02104ba0;
extern char *data_ov007_02104b9c;
extern char *data_ov007_0210342c;

extern void func_ov007_020c92d0(void *p);
extern int func_ov007_020c8f98(void *p);
extern int func_ov007_020c5db0(void *p);
extern int func_ov007_020c3be0(int t, int a, int b);
extern int func_ov007_020c5d5c(void *o);
extern int func_ov007_020bbd24(int a);
extern void func_ov007_020c4dfc(void *c, int a1, int a2, int a3);
extern int _ZN4cstd3divEii(int a, int b);
extern void func_ov007_020c4f50(void *c, int a1, int a2, int a3, int a4);
extern void func_ov007_020c4e98(void *c, int a1, int a2, int a3, int a4, int a5, int a6);

#define A data_ov007_02104ba0
#define B data_ov007_02104b9c
#define C data_ov007_0210342c

void func_ov007_020b91b4(void)
{
    int r7;
    char *r6;
    int r5;
    int r4;
    short st;
    int t;

    r6 = *(char **)A;
    func_ov007_020c92d0(*(char **)(A + 8));
    r4 = *(int *)(*(char **)(A + 8) + 0xc);
    func_ov007_020c8f98(*(char **)(A + 0x44));
    func_ov007_020c8f98(*(char **)(A + 0x48));
    *(int *)(A + 0x14) = func_ov007_020c5db0(*(char **)A);
    r5 = func_ov007_020c3be0(*(int *)(A + 0x40), 0, 0x59e8);

    t = *(int *)(A + 0x3c);
    if (t >= 0x1000) {
        r7 = 0x200;
    } else if (t <= 0) {
        r7 = 0xc0;
    } else {
        r7 = (int)(((long long)(0x1000 - t) * 0xc0 + ((long long)t << 9)) >> 0xc);
    }

    st = *(short *)(*(char **)(A + 8));
    switch (st) {
    case 0:
    case 1:
        if (*(int *)(*(char **)(A + 8) + 0xc) == 0) {
            char *a0 = *(char **)A;
            *(int *)(a0 + 0xac) = 0;
            *(int *)(a0 + 0xb0) = 0;
            *(int *)(A + 0x34) = 0;
            *(int *)(A + 0x18) = func_ov007_020c5d5c(*(char **)A);
            *(int *)B = 0;
        }
        {
            int b = func_ov007_020bbd24(*(short *)(*(char **)(A + 8)) == 0 ? 0 : 1);
            func_ov007_020c4dfc(r6, r7, r5, 0x1f);
            if (b == 0) {
                return;
            }
        }
        *(int *)(A + 0x30) = 0;
        *(short *)(*(char **)(A + 8) + 2) = 8;
        return;
    case 2:
        if (r4 == 0) {
            *(int *)(*(char **)(B + 4) + 0x50) = 0;
            *(int *)(*(char **)(B + 8) + 0x50) = 0;
            *(int *)B = 0x1000;
        }
        {
            int q;
            if (r4 <= 0) {
                q = 0;
            } else if (r4 >= 0x28) {
                q = 0x1000;
            } else {
                q = _ZN4cstd3divEii(r4 << 0xc, 0x28);
            }
            *(int *)(*(char **)(B + 8) + 0x50) = q * 0xc;
            if (q < 0x1000) {
                return;
            }
        }
        *(short *)(*(char **)(A + 8) + 2) = 5;
        return;
    case 3:
    case 4:
    case 5:
        {
            int *p = (int *)(*(char **)(B + 8) + 0x50);
            if (st == 4) {
                *p += 0x1000;
                if (*p >= 0x1f000) {
                    *p = 0x1f000;
                    *(int *)(*(char **)(B + 4) + 0x50) = 0x1f000;
                    *(short *)(*(char **)(A + 8) + 2) = 5;
                }
            } else if (st == 3) {
                if (r4 == 0) {
                    *(int *)(*(char **)(B + 4) + 0x50) = 0;
                }
                *p -= 0x1000;
                if (*p <= 0xc000) {
                    *p = 0xc000;
                    *(short *)(*(char **)(A + 8) + 2) = 5;
                }
            }
        }
        if (*(int *)(A + 0x30) != 0) {
            return;
        }
        func_ov007_020c4f50(r6, r7, r5, 0x1f, 1);
        return;
    case 6:
    case 7:
        {
            int r8v;
            int sb;
            int q;
            if (st == 6) {
                r8v = *(int *)(r6 + 8);
            } else {
                r8v = *(int *)(r6 + 8) - 1;
            }
            if (r4 <= 0) {
                q = 0;
            } else if (r4 >= 0xf) {
                q = 0x1000;
            } else {
                q = _ZN4cstd3divEii(r4 << 0xc, 0xf);
            }
            if (*(short *)(*(char **)(A + 8)) == 6) {
                q = 0x1000 - q;
            }
            sb = (q * 0x1f) >> 0xc;
            if (sb <= 0) {
                sb = 1;
            }
            func_ov007_020c4e98(r6, r7, r5, 0x1f, r8v, func_ov007_020c3be0(q, 0x18df, r5), sb);
            if (r4 < 0xf) {
                return;
            }
        }
        *(short *)(*(char **)(A + 8) + 2) = 5;
        *(int *)(*(char **)(C + 0x50) + 0x2c) |= 1;
        return;
    case 8:
        if (*(int *)(A + 0x30) != 0) {
            *(short *)(*(char **)(A + 8) + 2) = 1;
            return;
        }
        func_ov007_020c4f50(r6, r7, r5, 0x1f, 1);
        return;
    }
}
