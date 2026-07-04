//cpp
// NONMATCHING: base materialization / addressing (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
namespace G2x {
    void SetBlendAlpha(volatile unsigned short* p, int a, int b, int c, int d);
}

extern "C" void func_ov006_020e8bd0(char* c, int i)
{
    int* w = (int*)(c + 0x5288 + i * 0x14);
    unsigned char* cnt = (unsigned char*)(c + 0x554e);
    int ip;

    *w = *w - (*w >> 7);
    *cnt = *cnt + 1;

    ip = *(unsigned char*)(c + 0x554e);
    G2x::SetBlendAlpha((volatile unsigned short*)0x4001050, 0, 4, 0x10 - ip, ip);

    if (*(unsigned char*)(c + 0x554e) < 0x10) return;

    *(unsigned char*)(c + 0x554e) = 0;
    *(unsigned char*)(c + i * 0x14 + 0x5292) = 0;
    *(unsigned char*)(c + i * 0x14 + 0x5290) = 0;
}
