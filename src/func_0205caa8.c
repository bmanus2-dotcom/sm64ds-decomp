// NONMATCHING: base materialization / addressing (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int x);
extern void func_0205c864(int *thiz, int v);
extern void func_0205c788(int *p, int n);

int func_0205caa8(int *thiz)
{
    int saved = _ZN3IRQ7DisableEv();
    int b = (int)((thiz[4] & 2) != 0);
    if (b != 0) {
        int *p;
        func_0205c864(thiz, thiz[4]);
        thiz[4] |= 0x80;
        p = (int *)thiz[6];
        if (p != 0) {
            int n;
            do {
                n = p[1];
                func_0205c788(p, 3);
                p = (int *)n;
            } while (n != 0);
        }
        thiz[6] = 0;
        thiz[7] = 0;
        thiz[8] = 0;
        thiz[9] = 0;
        thiz[10] = 0;
        thiz[11] = 0;
        thiz[13] = 0;
        thiz[12] = thiz[13];
        thiz[4] &= ~0xa2;
    }
    _ZN3IRQ7RestoreEj(saved);
    return 1;
}
