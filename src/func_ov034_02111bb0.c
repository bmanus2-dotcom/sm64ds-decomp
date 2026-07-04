// NONMATCHING: different op / idiom (div=19). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int SetAnim(char* anim, void* file, int a, int b, unsigned int u);
extern void* data_ov034_021138b0[];
void func_ov034_02111bb0(char *p) {
    int i;
    char *anim = p + 0x110;
    *(int*)(p+0x8e4) = 0;
    for (i = 0; i < 5; i++) {
        SetAnim(anim, ((void**)data_ov034_021138b0[i])[1], 0x40000000, 0x1000, 0);
        int *f = (int*)((p + (i<<6)) + 0x490);
        *f |= 4;
        anim += 0x64;
    }
    if (*(unsigned char*)(p+0x8db) > 1) {
        char *q = p+0x8db;
        *(unsigned char*)q = *(unsigned char*)q - 1;
    }
}
