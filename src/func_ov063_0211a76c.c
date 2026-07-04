// NONMATCHING: push-set / frame (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern short data_02082214[];
extern short data_ov063_0211e7e0[];

void func_ov063_0211a76c(char* c, int cond, int val)
{
    int ip = *(unsigned short*)(c + 0x100) + 1;

    ip = ((ip << 0x1b) >> 0x10);
    ip = (unsigned short)ip;
    ip = ip >> 4;
    ip = (ip << 1) + 1;

    *(int*)(c + 0x98) = val;
    *(int*)(c + 0xa8) = data_02082214[ip];
    *(short*)(c + 0x94) = *(short*)(c + 0x5b6);
    if (cond == 0) return;

    {
        short* p8e = (short*)(c + 0x8e);
        short* p90 = (short*)(c + 0x90);
        *p8e = *p8e + data_ov063_0211e7e0[*(unsigned short*)(c + 0x100)];
        *p90 = *p90 + data_ov063_0211e7e0[*(unsigned short*)(c + 0x100)];
    }
}
