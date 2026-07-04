// NONMATCHING: different op / idiom (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
typedef unsigned char u8;

extern int RandomIntInternal(int *seed);
extern int data_0209d4b8;

void func_ov006_02100f7c(char *c, int i)
{
    int off = i * 0x40;
    int A, B;

    *(int *)(c + 0x5264 + off) = *(int *)(c + 0x5264 + off) + *(int *)(c + 0x526c + off);
    A = *(int *)(c + 0x5264 + off);
    B = *(int *)(c + 0x526c + off);
    if (B <= 0x4000)
        *(int *)(c + 0x526c + off) = *(int *)(c + 0x526c + off) + 0x200;
    if ((A >> 0xc) < 0xa0)
        return;

    *(int *)(c + 0x5264 + off) = 0xa0000;
    *(u8 *)(c + 0x5296 + off) = 0xa;
    *(int *)(c + 0x526c + off) = 0;
    *(u16 *)(c + 0x5292 + off) = 0x40;
    if ((((unsigned int)RandomIntInternal(&data_0209d4b8) >> 16) & 0x7fff) << 1 >> 0xf) {
        *(int *)(c + 0x5268 + off) = 0x1000;
        *(u8 *)(c + 0x529a + off) = 0;
    } else {
        *(int *)(c + 0x5268 + off) = -0x1000;
        *(u8 *)(c + 0x529a + off) = 1;
    }
}
