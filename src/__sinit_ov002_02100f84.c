// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_020731dc(void*, void*, void*);
extern int data_ov002_0210ddd0[];
extern int data_ov002_0210dddc[];
extern int data_ov002_0210dde8[];
extern int data_ov002_0210ddf4[];
extern int func_020072c0[];
extern int data_ov002_0210ddac[];
extern int data_ov002_0210ddb8[];
extern int data_ov002_0210ddc4[];
extern int data_ov002_0210dda0[];

void __sinit_ov002_02100f84(void) {
    *(unsigned int*)data_ov002_0210ddd0 = 0;
    *(unsigned int*)((char*)data_ov002_0210ddd0 + 4) = 0x190000;
    *(unsigned int*)((char*)data_ov002_0210ddd0 + 8) = 0x12c000;
    func_020731dc(data_ov002_0210ddd0, func_020072c0, data_ov002_0210ddac);
    *(unsigned int*)data_ov002_0210dddc = 0;
    *(unsigned int*)((char*)data_ov002_0210dddc + 4) = -0x190000;
    *(unsigned int*)((char*)data_ov002_0210dddc + 8) = 0x12c000;
    func_020731dc(data_ov002_0210dddc, func_020072c0, data_ov002_0210ddb8);
    *(unsigned int*)data_ov002_0210dde8 = 0x190000;
    *(unsigned int*)((char*)data_ov002_0210dde8 + 4) = 0;
    *(unsigned int*)((char*)data_ov002_0210dde8 + 8) = 0x12c000;
    func_020731dc(data_ov002_0210dde8, func_020072c0, data_ov002_0210ddc4);
    *(unsigned int*)data_ov002_0210ddf4 = -0x190000;
    *(unsigned int*)((char*)data_ov002_0210ddf4 + 4) = 0;
    *(unsigned int*)((char*)data_ov002_0210ddf4 + 8) = 0x12c000;
    func_020731dc(data_ov002_0210ddf4, func_020072c0, data_ov002_0210dda0);
}
