// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_020393a4(int* p, int v);
extern void Platform_UpdateModelPosAndRotY(void* c);
extern int Platform_IsClsnInRange(void* c, int a, int b);
extern void Platform_UpdateClsnPosAndRot(void* c);
int func_ov022_021117cc(char* c) {
    func_020393a4((int*)(c+0x124), 0x150000);
    if (*(unsigned char*)(c+0x324)) {
        int* py = (int*)(c+0x60);
        *py = *py - 0x2000;
        int lim = *(int*)(c+0x320) - 0xc8000;
        if (*(int*)(c+0x60) < lim) *(int*)(c+0x60) = lim;
        *(unsigned char*)(c+0x324) = 0;
    } else {
        int* py = (int*)(c+0x60);
        *py = *py + 0x2000;
        int lim = *(int*)(c+0x320);
        if (*(int*)(c+0x60) > lim) *(int*)(c+0x60) = lim;
    }
    Platform_UpdateModelPosAndRotY(c);
    if (Platform_IsClsnInRange(c, 0, 0)) {
        Platform_UpdateClsnPosAndRot(c);
    }
    return 1;
}
