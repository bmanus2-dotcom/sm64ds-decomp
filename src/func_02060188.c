// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
unsigned int _ZN3IRQ7DisableEv(void);
void _ZN3IRQ7RestoreEj(unsigned int);
void Crash(void);
void func_020580f0(void* p);

typedef struct {
    int* f0;     /* 0 */
    char pad4[4];
    int f8;      /* 8 */
    int fc;      /* 0xc */
    int f10;     /* 0x10 */
    int f14;     /* 0x14 */
} G;
extern G data_020a8180;

void func_02060188(int a0, int a1)
{
    G* g = &data_020a8180;
    unsigned int s = _ZN3IRQ7DisableEv();
    if (g->f8 == a0) {
        if (g->f14 != a1) Crash();
    } else {
        while (g->f8 != -3) {
            func_020580f0(&g->f10);
        }
        g->f8 = a0;
        g->f14 = a1;
    }
    g->fc++;
    *g->f0 = 0;
    _ZN3IRQ7RestoreEj(s);
}
