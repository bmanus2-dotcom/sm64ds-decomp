// NONMATCHING: different op / idiom (div=67). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned NumStars(void);
extern void _ZN9ActorBase18MarkForDestructionEv(void *o);
extern void func_0201267c(void *a, void *b);
extern void _Z14ApproachLinearRiii(int *p, int t, int s);
extern int Vec3_HorzAngle(void *a, void *b, int c);
extern void _Z14ApproachLinearRsss(short *p, short t, short s);
extern void func_ov063_0211a964(void *c, int b);

typedef struct { int x, y, z; } V3;

void func_ov063_02116a1c(void *cc)
{
    char *c = (char*)cc;
    V3 v;
    int a;

    v.x = *(int*)(c + 0x51c);
    v.y = *(int*)(c + 0x520);
    v.z = *(int*)(c + 0x524);
    *(int*)(c + 0x584) = 0x2000;

    a = *(unsigned char*)(c + 0x5cc);
    if (a == 0) {
        *(unsigned short*)(c + 0x5d4) &= ~8;
        if (NumStars() < 0xf) {
            _ZN9ActorBase18MarkForDestructionEv(c);
            return;
        }
        if (((unsigned)(*(unsigned short*)(c + 0x5d4)) << 0x1b) >> 0x1f) {
            *(unsigned short*)(c + 0x5d4) |= 8;
            *(unsigned char*)(c + 0x5c8) = 0xb4;
            *(int*)(c + 0x80) = *(int*)(c + 0x584);
            *(int*)(c + 0x84) = *(int*)(c + 0x584);
            *(int*)(c + 0x88) = *(int*)(c + 0x584);
            *(int*)(c + 0x188) = *(int*)(c + 0x590) * *(int*)(c + 0x584);
            *(int*)(c + 0x18c) = *(int*)(c + 0x594) * *(int*)(c + 0x584);
            *(unsigned char*)(c + 0x5cc) += 1;
        }
    } else if (a == 1) {
        if (*(int*)(c + 0x580) < 0x3e8000) {
            func_0201267c(c + 0x74, c + 0x5cc);
            *(unsigned char*)(c + 0x5cc) += 1;
        }
        *(int*)(c + 0x98) = 0;
    } else {
        _Z14ApproachLinearRiii((int*)(c + 0x98), 0x30000, 0x1800);
        v.x = -0x3e8000;
        v.z = 0xfdcd8000;
        if (*(int*)(c + 0x64) < (int)0xfec78000) {
            if (*(unsigned char*)(c + 0x5c8) <= 0x14) {
                *(unsigned char*)(c + 0x5c8) = 0;
            } else {
                *(unsigned char*)(c + 0x5c8) -= 0x14;
            }
        }
    }

    *(int*)(c + 0xa8) = 0;
    a = Vec3_HorzAngle(c + 0x5c, &v, 0);
    _Z14ApproachLinearRsss((short*)(c + 0x94), (short)a, (short)0x5a8);
    func_ov063_0211a964(c, 1);
}
