// NONMATCHING: different op / idiom (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int s32;
extern s32 func_ov066_021168b0(char* c);
extern void func_ov066_02119454(char* c, int* p);
extern unsigned char data_ov066_0211abe0;
extern unsigned char data_ov066_0211ae10;
extern unsigned char data_ov066_0211ae0c;
extern int data_ov066_0211b03c;

s32 func_ov066_02118a50(char* c) {
    s32 r = func_ov066_021168b0(c);
    if (r == 0) return 1;
    if (data_ov066_0211abe0 == 3) {
        if (!(data_ov066_0211ae10 & 1)) data_ov066_0211ae0c = 2;
        else data_ov066_0211ae0c = 1;
    } else {
        data_ov066_0211ae0c = data_ov066_0211abe0;
    }
    {
        unsigned char* p = (unsigned char*)(c + 0x4d9);
        *p += 1;
    }
    data_ov066_0211ae10 += 1;
    data_ov066_0211ae10 &= 1;
    func_ov066_02119454(c, &data_ov066_0211b03c);
    return 1;
}
