// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov007_020c42f8(void);
extern void func_ov007_020c4684(void *a, int b, int c, int d, int e, void *f);

struct Vec3s { short x, y, z; };

void func_ov007_020c421c(char *r4)
{
    struct Vec3s v;
    int diff;
    int t74, t78;
    v.z = 0;
    v.y = v.z;
    v.x = v.y;
    *(volatile int *)0x4000444 = 0;
    func_ov007_020c42f8();
    func_ov007_020c4684(r4, *(unsigned short *)(r4 + 0x44),
                        (*(int *)(r4 + 0x50) >> 12) & 0xff,
                        *(unsigned char *)(r4 + 0x4e),
                        *(int *)r4, &v);
    if (*(int *)r4 & 4) {
        diff = (*(int *)(r4 + 0x50) >> 12) - *(unsigned char *)(r4 + 0x7c);
        t78 = *(int *)(r4 + 0x78);
        t74 = *(int *)(r4 + 0x74);
        *(volatile int *)0x400046c = t74;
        *(volatile int *)0x400046c = t78;
        *(volatile int *)0x400046c = 0x1000;
        if (diff < 0) diff = 0;
        func_ov007_020c4684(r4, 0, diff & 0xff,
                            *(unsigned char *)(r4 + 0x7d),
                            0, r4 + 0x7e);
    }
    *(volatile int *)0x4000448 = 1;
}
