// NONMATCHING: register allocation (div=26). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void _ZN4CP1519InvalidateDataCacheEjj(unsigned int a, unsigned int b);
extern int func_02060f60(void *thiz, int a, int b);
extern void func_0205a61c(void *a, int b, unsigned int c);
extern void func_0206081c(void *thiz);

void func_0206071c(char *thiz)
{
    int *p20 = (int *)(thiz + 0x20);
    int *p1c = (int *)(thiz + 0x1c);
    int *p18 = (int *)(thiz + 0x18);
    char *e0 = thiz + 0xe0;
    int local = 1;
    do {
        unsigned int n = *(unsigned int *)(thiz + 0x20);
        if (n > 0x100) n = 0x100;
        _ZN4CP1519InvalidateDataCacheEjj((unsigned int)e0, 0x100);
        *(int *)(*(int *)thiz + 0xc) = *(int *)(thiz + 0x18);
        *(char **)(*(int *)thiz + 0x10) = e0;
        *(unsigned int *)(*(int *)thiz + 0x14) = n;
        if (func_02060f60(thiz, 6, local) == 0) break;
        func_0205a61c(e0, *(int *)(thiz + 0x1c), n);
        *p18 = *p18 + n;
        *p1c = *p1c + n;
        *p20 = *p20 - n;
    } while (*(int *)(thiz + 0x20) != 0);
    func_0206081c(thiz);
}
