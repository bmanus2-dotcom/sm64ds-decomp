// NONMATCHING: different op / idiom (div=98). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0201267c(char* c, int n);
extern void _Z14ApproachLinearRiii(int* p, int target, int step);
extern short Vec3_HorzAngle(const void* a, const void* b);
extern void _Z14ApproachLinearRsss(short* p, short target, short step);
extern char* func_ov063_0211a964(char* c, int n);

struct Vec3 { int x, y, z; };

void func_ov063_02116fac(char* c)
{
    struct Vec3 v;
    int r4 = 0xc00;
    v.x = *(int*)(c + 0x51c);
    v.y = *(int*)(c + 0x520);
    v.z = *(int*)(c + 0x524);
    *(int*)(c + 0x584) = 0x1000;

    switch (*(unsigned char*)(c + 0x5cc)) {
    case 0:
        *(unsigned short*)(c + 0x5d4) &= ~8;
        if (*(unsigned short*)(c + 0x5d4) << 0x1b >> 0x1f != 0) {
            (*(unsigned char*)(c + 0x5cc))++;
            *(unsigned char*)(c + 0x5c8) = 0xb4;
            *(unsigned short*)(c + 0x5d4) |= 8;
        }
        break;
    case 1:
        if (*(int*)(c + 0x580) < 0x258000) {
            (*(unsigned char*)(c + 0x5cc))++;
            func_0201267c(c + 0x74, 0xf8);
        }
        *(int*)(c + 0x98) = 0;
        break;
    case 2:
        _Z14ApproachLinearRiii((int*)(c + 0x98), 0x3a000, 0x1800);
        {
            v.x = -0x3e8000;
            v.y = 0;
            v.z = 0xfea84000;
            if (*(int*)(c + 0x64) < (int)0xfee08000) {
                (*(unsigned char*)(c + 0x5cc))++;
            }
        }
        break;
    case 3:
        _Z14ApproachLinearRiii((int*)(c + 0x98), 0, 0x9000);
        v.x = -0x3e8000;
        v.y = 0;
        v.z = -0xfa0000;
        *(short*)(c + 0x5bc) = Vec3_HorzAngle(c + 0x5c, &v);
        r4 = 0x1000;
        if (*(short*)(c + 0x8e) == *(short*)(c + 0x5bc) && *(int*)(c + 0x98) == 0) {
            (*(unsigned char*)(c + 0x5cc))++;
        }
        break;
    case 4:
        if (*(unsigned short*)(c + 0x100) == 6) {
            *(int*)(c + 0xa8) = 0xf000;
            *(int*)(c + 0x9c) = -0x4000;
            *(int*)(c + 0xa0) = -0xf000;
        }
        if (*(int*)(c + 0x60) < *(int*)(c + 0x520)) {
            *(int*)(c + 0x60) = *(int*)(c + 0x520);
            (*(unsigned char*)(c + 0x5cc))++;
            *(int*)(c + 0x9c) = 0;
            *(int*)(c + 0xa0) = 0;
        }
        break;
    case 5:
        _Z14ApproachLinearRiii((int*)(c + 0x98), 0x3a000, 0x1800);
        v.x = -0x3e8000;
        v.y = 0;
        v.z = 0xfea84000;
        r4 = 0x1000;
        if (*(int*)(c + 0x64) < (int)0xfec78000) {
            (*(unsigned char*)(c + 0x5cc))++;
        }
        break;
    case 6:
        *(int*)(c + 0x98) = 0;
        *(unsigned char*)(c + 0x5c8) = 0;
        *(unsigned short*)(c + 0x5d4) &= ~8;
        break;
    }

    if (*(unsigned char*)(c + 0x5cc) != 4) {
        *(int*)(c + 0xa8) = 0;
        *(short*)(c + 0x5bc) = Vec3_HorzAngle(c + 0x5c, &v);
    }
    _Z14ApproachLinearRsss((short*)(c + 0x94), *(short*)(c + 0x5bc), (short)r4);
    func_ov063_0211a964(c, 1);
}
