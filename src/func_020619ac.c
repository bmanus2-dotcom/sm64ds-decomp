// NONMATCHING: register allocation (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02061548(void);
extern int func_0206152c(void);
extern void _ZN4CP1519InvalidateDataCacheEjj(u32 a, u32 b);

char* func_020619ac(char* a, unsigned int idx)
{
    int h;
    char* o;
    char* local[16];
    int i;
    h = func_02061548();
    if (func_0206152c() != 0) return 0;
    if (idx < 1) goto ret0;
    if (idx > 0xf) { ret0: return 0; }
    o = *(char**)(h + 4);
    _ZN4CP1519InvalidateDataCacheEjj((u32)o + 0x17e, 2);
    if ((*(u16*)(*(char**)(h + 4) + 0x100 + 0x7e) & (1u << idx)) == 0) return 0;
    if (*(u16*)(a + 4) == 0) return 0;
    local[0] = a + 0xa;
    i = 0;
    for (;;) {
        if (idx == *(u16*)(local[i] + 4)) return local[i];
        i++;
        local[i] = (char*)(*(u16*)(a + 6) + (u32)local[i - 1]);
        if (i >= *(u16*)(a + 4)) break;
    }
    return 0;
}
