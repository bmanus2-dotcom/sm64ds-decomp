// NONMATCHING: different op / idiom (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_ov007_0210345c;
extern short data_ov007_02103458;
extern char* data_ov007_0210346c;
extern char* data_ov007_02103460;
extern void func_ov007_020c94e4(void);
extern int func_ov007_020c44c4(char* p);

void func_ov007_020b8690(void) {
    data_ov007_0210345c = 0;
    data_ov007_02103458 = 0;
    func_ov007_020c94e4();
    if (data_ov007_0210346c != 0) {
        func_ov007_020c44c4(data_ov007_0210346c);
        data_ov007_0210346c = 0;
    }
    if (data_ov007_02103460 != 0) {
        func_ov007_020c44c4(data_ov007_02103460);
        data_ov007_02103460 = 0;
    }
}
