// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020e95e4(char *c);
extern void func_ov006_020e7e74(char *c);
extern void func_ov006_020e93e8(char *c);
extern void func_ov004_020b0aa0(int arg);
void func_ov006_020e97b0(char *c)
{
    if (*(unsigned short*)(c + 0x5548) != 0) {
        unsigned short *d = (unsigned short*)(c + 0x5548);
        *d = *d - 1;
        if (*(short*)(c + 0x5548) < 0)
            *(short*)(c + 0x5548) = 0;
        return;
    }
    func_ov006_020e95e4(c);
    func_ov006_020e7e74(c + 0x4fd8);
    func_ov006_020e93e8(c);
    *(int*)(c + 0x5540) = 1;
    func_ov004_020b0aa0(0x1d);
    if (*(unsigned char*)(c + 0xc4) == 0) {
        *(unsigned char*)(c + 0xc3) = 1;
        *(unsigned char*)(c + 0xc4) = 1;
        *(short*)(c + 0xc0) = 0;
    }
}
