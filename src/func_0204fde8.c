// NONMATCHING: different op / idiom (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0205abb8(int a, int b, int c, int d);
extern void* func_0205afb4(void);
extern void func_0205b070(int a);
extern void func_0205afe0(void* p);
extern void func_0204fda4(char* obj);
void func_0204fde8(char* obj) {
    if ((int)(*(int*)(obj + 0xc) << 0x1e) >> 0x1f) {
        void* p;
        func_0205abb8(*(int*)(obj + 0x2c), 0, 1 << *(int*)(obj + 0x28), 0);
        *(int*)(obj + 0xc) &= ~2;
        p = func_0205afb4();
        func_0205b070(1);
        func_0205afe0(p);
        func_0204fda4(obj);
    }
}
