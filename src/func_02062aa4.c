//cpp
// NONMATCHING: different op / idiom (div=27). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" int func_02061548(void);
extern "C" void _ZN4CP1519InvalidateDataCacheEjj(u32 addr, u32 sz);
extern "C" void MultiCopyHalf(const void *src, void *dst, u32 count);

extern "C" void func_02062aa4(char *c)
{
    int h = func_02061548();
    char *r5 = *(char **)(c + 0x1c);
    if (*(u16 *)(c + 2) != 0) {
        *(u16 *)(r5 + 0x41c) = 3;
        return;
    }
    {
        u16 v = *(u16 *)(c + 4);
        if (v == 7) return;
        if (v == 9) return;
        if (v != 0x15) return;
    }
    u32 r4 = *(u16 *)(c + 0x10);
    if (r4 == *(u16 *)(r5 + 0x414)) {
        *(u16 *)(r5 + 0x41c) = 3;
        return;
    }
    if (r4 > 0x100)
        r4 = 0x100;
    _ZN4CP1519InvalidateDataCacheEjj(*(u32 *)(h + 4) + 0x184, 2);
    if (r4 < 4)
        return;
    char *src = *(char **)(c + 0xc);
    if (*(u16 *)src == 0)
        return;
    if ((1u << *(u16 *)(*(u32 *)(h + 4) + 0x184)) == 0)
        return;
    MultiCopyHalf(src, r5 + (*(u16 *)(r5 + 0x408) << 8), r4);
    *(u16 *)(r5 + *(u16 *)(r5 + 0x408) * 2 + 0x400) = *(u16 *)(c + 0x1a) >> 1;
    *(u16 *)(r5 + 0x408) = (*(u16 *)(r5 + 0x408) + 1) % 4;
}
