// NONMATCHING: different op / idiom (div=43). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int __aeabi_idiv(int a, int b);

struct Vtx {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
};

struct T {
    char pad0[0x80];
    struct Vtx *p80;     /* 0x80 */
    char pad1[0xa6 - 0x84];
    unsigned char ba6;   /* 0xa6 */
    unsigned char ba7;   /* 0xa7 */
};

void func_ov075_0211b260(struct T *t)
{
    int s0, s4, s8, sc;
    int i, j;
    int acc;
    int uu, vv;

    s0 = 0;
    if (t->ba7 <= 0) return;
    s8 = 0;
    sc = 0;
    s4 = 0;
    j = 0;

    acc = sc;
    do {
        i = s4;
        if (t->ba6 > 0) {
            do {
                struct Vtx *e = &t->p80[j * t->ba7 + i];
                int b, c;
                e->f0 = acc;
                e->f4 = s0;
                e->f8 = s8;
                e->f10 = 0x1ff00000;
                uu = __aeabi_idiv(0x80000, t->ba6 - 1);
                vv = __aeabi_idiv(0x80000, t->ba7 - 1);
                c = ((0x80000 - vv * j) << 8) >> 16;
                b = ((uu * i) << 8) >> 16;
                e->f14 = (unsigned short)b | ((unsigned short)c << 16);
                if (i == t->ba6 - 2) {
                    acc = 0x1f4000;
                } else {
                    acc += __aeabi_idiv(0x1f4000, t->ba6 - 1);
                }
                i++;
            } while (i < t->ba6);
        }
        if (j == t->ba7 - 2) {
            s0 = 0x1f4000;
        } else {
            s0 += __aeabi_idiv(0x1f4000, t->ba7 - 1);
        }
        acc = sc;
        j++;
    } while (j < t->ba7);
}
