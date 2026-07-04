// NONMATCHING: register allocation (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void* _ZN5Actor13ClosestPlayerEv(void);
extern unsigned char data_ov066_0211ae04;
extern unsigned char data_ov066_0211ae08;

void func_ov066_0211a2e4(int a, int b)
{
    void* p;
    if (data_ov066_0211ae04 != 1) return;
    if (b == 0) return;
    p = _ZN5Actor13ClosestPlayerEv();
    if (p == 0) return;
    if (*(int*)((char*)p + 0x64) < (int)0xff387000) {
        data_ov066_0211ae08++;
    }
}
