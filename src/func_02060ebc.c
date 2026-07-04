// NONMATCHING: base materialization / addressing (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_0205a61c(void* dst, void* src, int len);

typedef struct {
    char pad0[0x18];
    int f18;
    int f1c;
    int f20;
} G;
extern G data_020a8180;

typedef struct {
    char pad0[8];
    int f8;
} Arg;

int func_02060ebc(Arg* a)
{
    G* g = &data_020a8180;
    int base = g->f18 & ~0x1ff;
    if (base == a->f8) {
        int off = g->f18 - base;
        int len = 0x200 - off;
        if ((unsigned int)len > (unsigned int)g->f20) len = g->f20;
        func_0205a61c((char*)a + 0x20 + off, (void*)g->f1c, len);
        g->f18 += len;
        g->f1c += len;
        g->f20 -= len;
    }
    return g->f20 != 0;
}
