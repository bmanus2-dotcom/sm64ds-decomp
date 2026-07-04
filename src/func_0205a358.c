//cpp
// NONMATCHING: different op / idiom (div=26). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern int data_020a6460;
extern void func_02059fa8(int ch);
extern int _ZN3IRQ7DisableEv(void);
extern int _ZN3IRQ13GetIRQHandlerEj(unsigned int x);
extern void _ZN3IRQ13SetIRQHandlerEjPFvvE(unsigned int x, void *h);
extern void _ZN3IRQ10EnableIRQsEj(unsigned int x);
extern void _ZN3IRQ7RestoreEj(int saved);
extern void func_0205a290(void);

void func_0205a358(int a0, int a1, int a2, void (*a3)(int), int a4) {
    int *g;
    int saved;
    if (a2 == 0) {
        if (a3 != 0) a3(a4);
        return;
    }
    while (data_020a6460 != 0) ;
    while ((((*(volatile unsigned int*)0x4000600 & 0x7000000) >> 0x18) & 2) == 0) ;
    g = (int*)data_020a6460;
    g[0] = 1;
    g[1] = a0;
    g[2] = a1;
    g[3] = a2;
    g[4] = (int)a3;
    g[5] = a4;
    func_02059fa8(a0);
    saved = _ZN3IRQ7DisableEv();
    ((int*)data_020a6460)[6] = (*(volatile unsigned int*)0x4000600 & 0xc0000000) >> 0x1e;
    ((int*)data_020a6460)[7] = _ZN3IRQ13GetIRQHandlerEj(0x200000);
    *(volatile unsigned int*)0x4000600 = (*(volatile unsigned int*)0x4000600 & ~0xc0000000) | 0x40000000;
    _ZN3IRQ13SetIRQHandlerEjPFvvE(0x200000, (void*)func_0205a290);
    _ZN3IRQ10EnableIRQsEj(0x200000);
    func_0205a290();
    _ZN3IRQ7RestoreEj(saved);
}
}
