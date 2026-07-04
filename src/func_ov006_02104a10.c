//cpp
// NONMATCHING: register allocation (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
namespace Sound { void PlayBank2_2D(unsigned int); }
void SetSubBg0Offset(int a, int b);
extern int data_ov006_0212ecec[];

void func_ov006_02104a10(char *c, int idx)
{
    int m = idx * 0xc;
    char *b = c + 0x4690;
    unsigned short h = *(unsigned short*)(b + m);
    *(unsigned short*)(b + m) = h + 1;
    if (*(unsigned short*)(b + m) >= 0x20) {
        *(short*)(b + m) = 0;
        *(unsigned char*)(c + m + 0x4000 + 0x693) = 2;
        return;
    }
    {
        int t = data_ov006_0212ecec[(h + 1) >> 3];
        int *dst = (int*)(c + 0x468c + m);
        unsigned short st;
        *dst = t;
        st = *(unsigned short*)(c + m + 0x4600 + 0x90);
        if (st == 1 || st == 0x11) Sound::PlayBank2_2D(0x1fc);
        SetSubBg0Offset(0, *dst);
    }
}
}
