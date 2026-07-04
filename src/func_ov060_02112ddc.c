//cpp
// NONMATCHING: base materialization / addressing (div=37). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" void func_ov060_02113564(char *c);
extern "C" void func_ov060_021134ac(char *c);
extern "C" int func_ov060_02113404(char *c);
extern "C" int func_ov060_021130c0(char *c);
extern "C" int func_ov060_02112ee0(char *c);

extern "C" void func_ov060_02112ddc(char *self)
{
    switch (*(unsigned char*)(self + 0x423)) {
    case 0:
        func_ov060_02113564(self);
        return;
    case 1:
        func_ov060_021134ac(self);
        return;
    case 2:
        if (func_ov060_02113404(self) != 0) {
            *(short*)(self + 0x3fe) = 0;
            if (*(unsigned char*)(self + 0x414) == 2) {
                *(unsigned char*)(self + 0x423) = 0xa;
                return;
            }
            (*(unsigned char*)(self + 0x423))++;
        }
        return;
    case 3:
        if (func_ov060_021130c0(self) != 0)
            (*(unsigned char*)(self + 0x423))++;
        return;
    case 10:
        if (func_ov060_02112ee0(self) != 0)
            (*(unsigned char*)(self + 0x423))++;
        return;
    case 11:
        return;
    }
}
