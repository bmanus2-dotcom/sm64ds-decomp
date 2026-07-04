// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void _ZN12CylinderClsn5ClearEv(void* p);

int func_ov071_02120200(char* c)
{
    short* sub = (short*)(c + 0x300);
    {
        int* p = (int*)(c + 0xb0);
        *p = *p & ~0x10000001;
    }
    *(int*)(c + 0x5c) = *(int*)(c + 0x384);
    *(int*)(c + 0x60) = *(int*)(c + 0x388);
    *(int*)(c + 0x64) = *(int*)(c + 0x38c);
    *(short*)(c + 0x94) = sub[0x53];      /* [0x3a6] */
    *(short*)(c + 0x8c) = 0;
    *(short*)(c + 0x8e) = sub[0x53];
    *(short*)(c + 0x90) = 0;
    *(int*)(c + 0x98) = 0;
    sub[0x54] = 0x1e;                      /* [0x3a8] */
    _ZN12CylinderClsn5ClearEv(c + 0x160);
    *(int*)(c + 0x39c) = 0;
    return 1;
}
