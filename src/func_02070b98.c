// NONMATCHING: different op / idiom (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef short s16;
void func_02070c68(void* x);
void func_020715e0(void* thiz, int val);

void func_02070b98(void* a0, int a1, int a2, void* d)
{
    int n;
    char* c = (char*)d;
    int i;
    n = *(s16*)((char*)a0 + 2);
    func_02070c68(c);
    if (*(u8*)(c + 5) > 9) return;
    if (n > 0x20) n = 0x20;
    func_020715e0(c, n);
    while (*(u8*)(c + 4) < n) {
        c[5 + *(u8*)(c + 4)] = 0;
        *(u8*)(c + 4) += 1;
    }
    *(s16*)(c + 2) -= *(u8*)(c + 4) - 1;
    if (*(u8*)(c + 4) <= 0) return;
    for (i = 0; i < *(u8*)(c + 4); i++) {
        *(u8*)(c + i + 5) += 0x30;
    }
}
