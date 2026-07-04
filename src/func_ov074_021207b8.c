// NONMATCHING: push-set / frame (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_ov074_02121a20(void *c, int idx);
extern int _ZN9Animation8FinishedEv(void *);
int func_ov074_021207b8(char *c)
{
    if (func_ov074_02121a20(c, 6) && _ZN9Animation8FinishedEv(c + 0x260)) {
        *(short *)(c + 0x8e) = *(short *)(c + 0x8e) + 0x8000;
        return 1;
    }
    return 0;
}
