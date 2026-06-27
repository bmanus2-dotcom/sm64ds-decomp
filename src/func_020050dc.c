// NONMATCHING: base materialization / addressing (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0200cb58(void *obj, int index);
extern void func_0200cce4(void *obj);

int func_020050dc(void *obj) {
    func_0200cb58(obj, 0x1e);
    func_0200cce4(obj);
    int *p = (int *)((char *)obj + 0x154);
    *p = *p | 0x100;
    return 1;
}
