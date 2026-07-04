// NONMATCHING: base materialization / addressing (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _Z15ApproachLinear2Rsss(short* dst, short to, short step);
extern void func_0203d630(int* p, int m);

void func_ov004_020adeb0(char* c)
{
    _Z15ApproachLinear2Rsss((short*)(c + 0x1a), 0, 1);
    func_0203d630((int*)(c + 8), 0xff8);
    *(int*)(c + 8) += *(int*)(c + 0x10);
    *(int*)(c + 0xc) += *(int*)(c + 0x14);
    *(int*)(c + 0) += *(int*)(c + 8);
    *(int*)(c + 4) += *(int*)(c + 0xc);
}
