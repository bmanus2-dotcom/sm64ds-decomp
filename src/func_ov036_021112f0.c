// NONMATCHING: base materialization / addressing (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_ov036_0211123c(char *t);
extern int IsClsnInRange(char *c, int a, int b);
extern int UpdateClsnPosAndRot(char *c);
int func_ov036_021112f0(char *c) {
    if (*(short*)(c+0x90) >= 0) {
        short *p = (short*)(c + 0x31e);
        *p = *p - 4;
    } else {
        short *p = (short*)(c + 0x31e);
        *p = *p + 4;
    }
    *(short*)(c+0x90) = (short)(*(short*)(c+0x90) + *(short*)(c+0x300+0x1e));
    func_ov036_0211123c(c);
    if (IsClsnInRange(c, 0, 0))
        UpdateClsnPosAndRot(c);
    return 1;
}
