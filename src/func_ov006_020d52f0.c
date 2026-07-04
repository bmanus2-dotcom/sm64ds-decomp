// NONMATCHING: base materialization / addressing (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_ov004_020adb1c(int self);
extern void func_ov006_020d3ba0(char *c);
void func_ov006_020d52f0(char *c, int arg)
{
    if (arg == 0) {
        int *p;
        if (*(unsigned int *)(c + 0xbc) >= 0x7cf)
            goto end;
        p = (int *)(c + 0xbc);
        *p = *p + 1;
        if (*(int *)(c + 0xbc) > 0x270e)
            *(int *)(c + 0xbc) = 0x270e;
    } else {
        *(int *)(c + 0x5000 + 0x3e8) = 0;
        *(int *)(c + 0xbc) = 0;
        if (*(int *)(c + 0xbc) > 0x270e)
            *(int *)(c + 0xbc) = 0x270e;
    }
end:
    *(int *)(c + 0xb4) = func_ov004_020adb1c(*(int *)(c + 0x5000 + 0x3e8));
    func_ov006_020d3ba0(c);
}
