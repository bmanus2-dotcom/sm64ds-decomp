//cpp
// NONMATCHING: base materialization / addressing (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void func_0205a61c(int dst, int src, unsigned int n);
extern void _ZN4CP1527FlushAndInvalidateDataCacheEjj(unsigned int a, unsigned int b);
extern void _ZN4CP1516DrainWriteBufferEv(void);
extern int func_02060f60(void *o, int a, int b);
extern void func_0206081c(void *o);

void func_0206062c(char *self) {
    char *e0 = self + 0xe0;
    int one = 1;
    int *p18 = (int*)(self + 0x18);
    unsigned int n;
    for (;;) {
        n = *(unsigned int*)(self + 0x20);
        if (n > 0x100) n = 0x100;
        func_0205a61c(*(int*)(self + 0x18), (int)e0, n);
        _ZN4CP1527FlushAndInvalidateDataCacheEjj((unsigned int)e0, n);
        _ZN4CP1516DrainWriteBufferEv();
        *(int*)(*(char**)self + 0xc) = (int)e0;
        *(int*)(*(char**)self + 0x10) = *(int*)(self + 0x1c);
        *(int*)(*(char**)self + 0x14) = n;
        if (func_02060f60(self, 8, 0xa) == 0) break;
        if (func_02060f60(self, 9, one) == 0) break;
        *p18 += n;
        *(int*)(self + 0x1c) += n;
        *(int*)(self + 0x20) -= n;
        if (*(int*)(self + 0x20) == 0) break;
    }
    func_0206081c(self);
}
}
