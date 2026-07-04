//cpp
// NONMATCHING: different op / idiom (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
typedef unsigned short u16;
short* _ZN2G212GetBG0ScrPtrEv(void);
void MultiStore16(u16 val, short* dst, int n);
struct E { signed char* ptr; int pad; };
extern struct E data_ov003_020b117c[];

void func_ov003_020adcbc(int n, int r1, int r2) {
    volatile u16 t0, t1, t2, t3, t4;
    int tens = n / 10;
    int ones = n % 10;
    short* scr = _ZN2G212GetBG0ScrPtrEv();
    short* d = scr + (r2 + (r1 << 5));
    t0 = tens == 0 ? 0xff : tens + 0x30;
    MultiStore16(t0, d, 2);
    t1 = ones + 0x30;
    MultiStore16(t1, d + 1, 2);
    t2 = 0xff;
    MultiStore16(t2, d + 2, 2);
    d += 3;
    int cnt = 0x1d - r2;
    signed char* s = data_ov003_020b117c[n].ptr;
    if (*s != 0) {
        do {
            t3 = *s;
            MultiStore16(t3, d, 2);
            s++;
            d++;
            cnt--;
        } while (*s != 0);
    }
    if (cnt > 0) {
        int i = 0;
        do {
            t4 = 0xff;
            MultiStore16(t4, d, 2);
            i++;
            d++;
        } while (i < cnt);
    }
}
}
