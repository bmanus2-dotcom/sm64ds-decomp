// NONMATCHING: different op / idiom (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern void func_0205a61c(int a, int b, int c);

void func_02064554(int self, int sel, int idx, s16 a3)
{
    char *c = (char *)(self + 0x1d4 + idx * 0x68);
    char *o = (char *)(self + 0x138);

    if (sel != 0xd && *(u8 *)(c + 2) == *(u8 *)(c + 3))
        return;

    *(s32 *)(o + 0) = 0xc;
    *(s16 *)(o + 0xa) = (s16)(1 << idx);
    *(u8 *)(c + 3) = *(u8 *)(c + 2);
    *(s8 *)(o + 0xd) = *(u8 *)(c + 2);
    *(s16 *)(o + 0xe) = a3;

    switch (sel) {
    case 2:
        *(s16 *)(o + 0x14) = *(s16 *)(c + 0xa);
        *(s16 *)(o + 0x16) = *(s16 *)(c + 6);
        *(s16 *)(o + 0x18) = *(s16 *)(c + 4);
        break;
    case 8:
        *(s32 *)(o + 0x14) = *(s32 *)(c + 0x10);
        break;
    case 14:
        break;
    case 10:
        {
            u8 v = *(u8 *)(c + 0xd);
            if (v > 9) {
                *(s8 *)(o + 0x1d) = 0;
                break;
            }
            *(s8 *)(o + 0x1d) = v;
            func_0205a61c(*(s32 *)(c + 0x20), (int)(o + 0x14), *(u8 *)(o + 0x1d));
        }
        break;
    }

    *(s32 *)(o + 4) = sel;
    {
        void (*fn)(char *) = *(void (**)(char *))(o + 0x10);
        if (fn)
            fn(o);
    }
}
