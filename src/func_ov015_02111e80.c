// NONMATCHING: base materialization / addressing (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov015_02111fb8(void *self, int idx);
void func_ov015_02111e80(int *c)
{
    int *p = (int *)((char *)c + 0x334);
    *p = *p - 1;
    if ((*(int *)(((int)c + 0x334) & 0xFFFFFFFFFFFFFFFF)) > 0)
        return;
    if ((*(int *)(((int)c + 0x32c) & 0xFFFFFFFFFFFFFFFF)) == 0)
        func_ov015_02111fb8(c, 3);
    else
        func_ov015_02111fb8(c, 4);
}
