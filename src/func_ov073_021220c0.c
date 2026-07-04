// NONMATCHING: different op / idiom (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned short DecIfAbove0_Short(unsigned short* p);
extern void _Z14ApproachLinearRiii(int* p, int a, int b);
extern void _ZN5Actor9UpdatePosEP12CylinderClsn(void* a, void* clsn);
extern void func_ov073_021223a4(void* c, void* p);
extern short data_02082214[];
extern int data_02092138;
extern int data_ov073_021234a0;

int func_ov073_021220c0(char* c)
{
    *(int*)(c + 0x328) = 0x400;
    if (DecIfAbove0_Short((unsigned short*)(c + 0x330)) != 0) {
        {
            short* q = (short*)(c + 0x332);
            *q = *q + 0x800;
        }
        {
            int t = *(int*)(c + 0x328);
            short tv = data_02082214[((unsigned short)*(short*)((char*)(c + 0x300) + 0x32) >> 4) * 2];
            *(short*)(c + 0x8c) = t + (int)(((long long)t * tv + 0x800) >> 12);
        }
        _Z14ApproachLinearRiii((int*)(c + 0x328), 0, 0x40000);
        return 1;
    }
    *(short*)(c + 0x8c) = 0;
    *(int*)(c + 0x9c) = -0xa000;
    _ZN5Actor9UpdatePosEP12CylinderClsn(c, 0);
    if (*(unsigned char*)(c + 0x32c) != 0) return 1;
    {
        int v = data_02092138 + 0x96000;
        if (v <= *(int*)(c + 0x60)) return 1;
        *(int*)(c + 0x60) = v;
        *(short*)(c + 0x330) = 0;
        *(int*)(c + 0x9c) = 0;
        *(int*)(c + 0xa8) = 0;
        func_ov073_021223a4(c, &data_ov073_021234a0);
    }
    return 1;
}
