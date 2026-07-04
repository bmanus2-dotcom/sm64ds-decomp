// NONMATCHING: extra logic (you do more) (div=52). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_020731dc(short* a, void* b, void* node);
extern char func_0203b98c[];

extern short data_ov004_020bfe74[];
extern short data_ov004_020bfe78[];
extern short data_ov004_020bfe7c[];
extern short data_ov004_020bfe80[];
extern short data_ov004_020bfe84[];
extern short data_ov004_020bfe88[];
extern short data_ov004_020bfe8c[];
extern short data_ov004_020bfe90[];
extern short data_ov004_020bfe94[];
extern short data_ov004_020bfe98[];
extern short data_ov004_020bfe9c[];
extern short data_ov004_020bfea0[];
extern short data_ov004_020bfea4[];
extern short data_ov004_020bfea8[];
extern short data_ov004_020bfeac[];
extern short data_ov004_020bfeb0[];
extern short data_ov004_020bfeb4[];

extern char data_ov004_020bfe20[];
extern char data_ov004_020bfdd8[];
extern char data_ov004_020bfdcc[];
extern char data_ov004_020bfde4[];
extern char data_ov004_020bfe68[];
extern char data_ov004_020bfe50[];
extern char data_ov004_020bfe44[];
extern char data_ov004_020bfe38[];
extern char data_ov004_020bfe2c[];
extern char data_ov004_020bfe14[];
extern char data_ov004_020bfe08[];
extern char data_ov004_020bfdb4[];
extern char data_ov004_020bfdf0[];
extern char data_ov004_020bfda8[];
extern char data_ov004_020bfe5c[];
extern char data_ov004_020bfdc0[];
extern char data_ov004_020bfdfc[];

void __sinit_ov004_020b9b24(void)
{
    data_ov004_020bfe74[0] = 0x20;
    data_ov004_020bfe74[1] = 0x10;
    func_020731dc(data_ov004_020bfe74, func_0203b98c, data_ov004_020bfe20);
    data_ov004_020bfe78[0] = 0x20;
    data_ov004_020bfe78[1] = 0x10;
    func_020731dc(data_ov004_020bfe78, func_0203b98c, data_ov004_020bfdd8);
    data_ov004_020bfe7c[0] = 0x18;
    data_ov004_020bfe7c[1] = 0x10;
    func_020731dc(data_ov004_020bfe7c, func_0203b98c, data_ov004_020bfdcc);
    data_ov004_020bfe80[0] = 0x1c;
    data_ov004_020bfe80[1] = 0x10;
    func_020731dc(data_ov004_020bfe80, func_0203b98c, data_ov004_020bfde4);
    data_ov004_020bfe84[0] = 0x1c;
    data_ov004_020bfe84[1] = 0x10;
    func_020731dc(data_ov004_020bfe84, func_0203b98c, data_ov004_020bfe68);
    data_ov004_020bfe88[0] = 0x30;
    data_ov004_020bfe88[1] = 0x10;
    func_020731dc(data_ov004_020bfe88, func_0203b98c, data_ov004_020bfe50);
    data_ov004_020bfe8c[0] = 0x18;
    data_ov004_020bfe8c[1] = 0x10;
    func_020731dc(data_ov004_020bfe8c, func_0203b98c, data_ov004_020bfe44);
    data_ov004_020bfe90[0] = 0x30;
    data_ov004_020bfe90[1] = 0x10;
    func_020731dc(data_ov004_020bfe90, func_0203b98c, data_ov004_020bfe38);
    data_ov004_020bfe94[0] = 0x30;
    data_ov004_020bfe94[1] = 0x10;
    func_020731dc(data_ov004_020bfe94, func_0203b98c, data_ov004_020bfe2c);
    data_ov004_020bfe98[0] = 0x30;
    data_ov004_020bfe98[1] = 0x10;
    func_020731dc(data_ov004_020bfe98, func_0203b98c, data_ov004_020bfe14);
    data_ov004_020bfe9c[0] = 0x3c;
    data_ov004_020bfe9c[1] = 0x10;
    func_020731dc(data_ov004_020bfe9c, func_0203b98c, data_ov004_020bfe08);
    data_ov004_020bfea0[0] = 0x1c;
    data_ov004_020bfea0[1] = 0x10;
    func_020731dc(data_ov004_020bfea0, func_0203b98c, data_ov004_020bfdb4);
    data_ov004_020bfea4[0] = 0x8;
    data_ov004_020bfea4[1] = 0x10;
    func_020731dc(data_ov004_020bfea4, func_0203b98c, data_ov004_020bfdf0);
    data_ov004_020bfea8[0] = 0x8;
    data_ov004_020bfea8[1] = 0x10;
    func_020731dc(data_ov004_020bfea8, func_0203b98c, data_ov004_020bfda8);
    data_ov004_020bfeac[0] = 0x18;
    data_ov004_020bfeac[1] = 0x10;
    func_020731dc(data_ov004_020bfeac, func_0203b98c, data_ov004_020bfe5c);
    data_ov004_020bfeb0[0] = 0x28;
    data_ov004_020bfeb0[1] = 0x10;
    func_020731dc(data_ov004_020bfeb0, func_0203b98c, data_ov004_020bfdc0);
    data_ov004_020bfeb4[0] = 0x20;
    data_ov004_020bfeb4[1] = 0x10;
    func_020731dc(data_ov004_020bfeb4, func_0203b98c, data_ov004_020bfdfc);
}
