//cpp
// NONMATCHING: different op / idiom (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" int func_ov004_020adbc0(void);
extern "C" void func_ov004_020adb1c(int self);

extern "C" void func_ov006_02115598(char* c, int* src, int v2, int v3, int v5)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (*(int*)(c + i * 4 + 0x478c) > 0) continue;
        if (v3 > 0) {
            *(int*)(c + i * 4 + 0x47f0) = v3;
        } else {
            func_ov004_020adb1c(v2 + func_ov004_020adbc0());
            if ((unsigned int)func_ov004_020adbc0() > 0xf423f) {
                func_ov004_020adb1c(0xf423f);
            }
        }
        *(int*)(c + i * 4 + 0x478c) = v2;
        *(int*)(c + i * 4 + 0x47a0) = v5;
        *(int*)(c + i * 4 + 0x47b4) = 0;
        *(int*)(c + i * 8 + 0x47c8) = src[0];
        *(int*)(c + i * 8 + 0x47cc) = src[1];
        return;
    }
    func_ov004_020adb1c(v2 * v5 + func_ov004_020adbc0());
    if ((unsigned int)func_ov004_020adbc0() > 0xf423f) {
        func_ov004_020adb1c(0xf423f);
    }
}
