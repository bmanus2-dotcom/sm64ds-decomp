// NONMATCHING: base materialization / addressing (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int);
extern void func_020580f0(void *p);

int func_0205c864(int *thiz)
{
    unsigned int saved;
    int notset, ret, b, loop;
    saved = (unsigned int)_ZN3IRQ7DisableEv();
    notset = (thiz[4] & 8) ? 1 : 0;
    ret = (notset == 0) ? 1 : 0;
    if (ret) {
        b = (thiz[4] & 0x10) ? 1 : 0;
        if (b == 0) goto skip;
        *(int*)((char*)thiz + 0x10) |= 0x40;
        do {
            func_020580f0((char*)thiz + 0xe);
            loop = (thiz[4] & 0x40) ? 1 : 0;
        } while (loop);
    skip:
        *(int*)((char*)thiz + 0x10) |= 8;
    }
    _ZN3IRQ7RestoreEj(saved);
    return ret;
}
