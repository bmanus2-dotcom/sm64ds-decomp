// NONMATCHING: base materialization / addressing (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020e984c(char* c);
extern void func_ov006_020e7fb0(char* c);
extern void func_ov004_020b0cac(int c, int a1, int a2, int a3, int arg5, short arg6);
extern char* func_020beb68;

void func_ov006_020e9c20(char* c, int a)
{
    func_ov006_020e984c(c);
    *(int*)(c + 0x553c) = 0;
    if (a == 0) {
        unsigned int* p = (unsigned int*)(c + 0xbc);
        *p += 1;
        if (*(unsigned int*)(c + 0xbc) > 0x270e) *(unsigned int*)(c + 0xbc) = 0x270e;
    } else if (a == 0x12) {
        if (func_020beb68 != 0) *(int*)(func_020beb68 + 0xb4) = 0;
        *(unsigned int*)(c + 0xbc) = 0;
        if (*(unsigned int*)(c + 0xbc) > 0x270e) *(unsigned int*)(c + 0xbc) = 0x270e;
    }
    *(int*)(c + 0x51e4) = 0;
    func_ov006_020e7fb0(c + 0x4fd8);
    func_ov004_020b0cac(0xd, 0x80, 0xa8, 1, -1, 0xd);
}
