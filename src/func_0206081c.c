// NONMATCHING: different op / idiom (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int saved);
extern void func_0205807c(char* p);
extern void func_02058048(char* p);
typedef void (*CB)(void*);
void func_0206081c(char* obj) {
    CB cb = *(CB*)(obj + 0x28);
    void* arg = *(void**)(obj + 0x2c);
    unsigned int saved = _ZN3IRQ7DisableEv();
    *(int*)(obj + 0x34) &= ~0xc;
    func_0205807c(obj + 0xd4);
    if (*(int*)(obj + 0x34) & 0x10) {
        func_02058048(obj + 0x3c);
    }
    _ZN3IRQ7RestoreEj(saved);
    if (cb != 0) {
        cb(arg);
    }
}
