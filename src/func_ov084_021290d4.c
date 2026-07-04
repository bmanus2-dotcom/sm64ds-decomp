// NONMATCHING: register allocation (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov084_021290d4(char* c) {
    unsigned short* p = (unsigned short*)(c + 0x400);
    if (p[0x2c] != 0) {
        if (*(int*)(c + 0x434) == 1) {
            p[0x2c] = 0;
        } else {
            *(unsigned short*)(c + 0x458) = *(unsigned short*)(c + 0x458) - 1;
        }
        return;
    }
    if (*(unsigned char*)(c + 0x113) < 6) {
        *(int*)(c + 0x448) = 0x1f4000;
        return;
    }
    {
        unsigned int v = p[0x2b];
        if (v <= 0xa) {
            *(int*)(c + 0x448) = 0x1f4000;
            return;
        }
        *(int*)(c + 0x448) = 0x1f4000 - (((v - 0xa) * 0x14) << 12);
        if (*(int*)(c + 0x448) < 0xa000) {
            *(int*)(c + 0x448) = 0xa000;
        }
    }
}
