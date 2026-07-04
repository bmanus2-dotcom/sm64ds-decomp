// NONMATCHING: constant / value (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int saved);
extern void* data_020a7fc8[];
void func_0205ba64(int idx, void* val) {
    unsigned int saved = _ZN3IRQ7DisableEv();
    data_020a7fc8[idx] = val;
    if (val != 0) {
        *(unsigned int*)(0x27ffc00 + 0x388) |= (1u << idx);
    } else {
        *(unsigned int*)(0x27ffc00 + 0x388) &= ~(1u << idx);
    }
    _ZN3IRQ7RestoreEj(saved);
}
