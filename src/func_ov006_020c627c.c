// NONMATCHING: base materialization / addressing (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void AddVec3(void* a, void* b, void* c);
extern void _Z14ApproachLinearRsss(short* x, short a, short b);
extern void func_ov006_020c49d8(void* c);
extern short data_02082214[];

void func_ov006_020c627c(char* c)
{
    int v, w;
    *(short*)(c + 0xea) += 0x200;
    {
        int a = (unsigned short)*(unsigned short*)(c + 0xea) >> 4;
        *(int*)(c + 0xac) = data_02082214[a * 2] >> 3;
    }
    AddVec3(c + 0x9c, c + 0xa8, c + 0x9c);
    v = *(int*)(c + 0xa8);
    if (v < 0) {
        if (*(int*)(c + 0x9c) < -0x68000)
            *(int*)(c + 0xa8) = -v;
    } else if (v > 0) {
        if (*(int*)(c + 0x9c) > 0x68000)
            *(int*)(c + 0xa8) = -v;
    }
    w = *(int*)(c + 0xa8);
    if (w > 0)
        _Z14ApproachLinearRsss((short*)(c + 0xe6), 0x3000, 0x200);
    else
        _Z14ApproachLinearRsss((short*)(c + 0xe6), -0x3000, 0x200);
    func_ov006_020c49d8(c);
}
