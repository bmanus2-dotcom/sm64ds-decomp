// NONMATCHING: base materialization / addressing (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov002_020db54c(char* p, int a, int b, int d);

int func_ov002_020dab14(char* c)
{
    char* p = *(char**)(c + 0x358);
    int ok = (int)(p != 0);
    int is_bf;
    if (ok == 0) return 0;
    is_bf = (int)(*(unsigned short*)(p + 0xc) == 0xbf);
    if (is_bf != 0) {
        func_ov002_020db54c(p, 0x10000, 0x10000, *(short*)(c + 0x8e));
    }
    *(int*)(*(char**)(c + 0x358) + 0xb0) &= ~0x4000;
    *(int*)(*(char**)(c + 0x358) + 0xb0) &= ~0x100;
    *(char**)(c + 0x358) = 0;
    return 1;
}
