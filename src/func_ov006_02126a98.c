// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_02126b4c(char *c, int a, int b);

void func_ov006_02126a98(char *c)
{
    int i = 0;
    int v = *(int*)(c + 0xa000 + 0xb6c) >> 12;
    int r7 = v / 16 - 2;
    if (r7 < 0) r7 = 0;
    for (; i < 0x10; i++) {
        func_ov006_02126b4c(c, r7, 1);
        r7++;
    }
    {
        int v2 = *(int*)(c + 0xa000 + 0xb6c) >> 12;
        int r8 = (v2 + 0x110) / 16 - 2;
        int j;
        for (j = 0; j < 0x10; j++) {
            if (r8 >= *(int*)(c + 0xb000 + 0xa08)) return;
            func_ov006_02126b4c(c, r8, 0);
            r8++;
        }
    }
}
