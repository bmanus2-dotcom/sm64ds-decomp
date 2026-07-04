//cpp
// NONMATCHING: base materialization / addressing (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern unsigned short DecIfAbove0_Short(unsigned short *p);
extern void func_0203568c(int *p, int v);
extern void func_02035684(int *p, int v);
extern void func_ov002_020ef228(void *c, int arg);
extern void func_ov102_0214ae1c(void *c);
extern int func_ov102_0214b128(void *c);
}
struct Vector3 { int x, y, z; };
namespace Sound { unsigned int PlayLong(unsigned int, unsigned int, unsigned int, Vector3 const &, unsigned int); }

extern "C" int func_ov102_0214b248(char *c)
{
    if (DecIfAbove0_Short((unsigned short *)(c + 0x3ea))) {
        *(unsigned int *)(c + 0x3e4) = Sound::PlayLong(
            *(unsigned int *)(c + 0x3e4), 3, 0x188, *(Vector3 *)(c + 0x74), 0);
    }

    {
        unsigned short st = *(unsigned short *)(c + 0x3ea);
        if (st != 0 && st <= 4) {
            *(int *)(c + 0x128) &= ~0x8000;
            if (*(unsigned short *)(c + 0x3ea) == 1) {
                func_ov102_0214ae1c(c);
                return 0;
            }
            {
                int v = ((5 - *(unsigned short *)(c + 0x3ea)) << 12) / 4 + 0x1000;
                *(int *)(c + 0x88) = v;
                *(int *)(c + 0x84) = *(int *)(c + 0x88);
                *(int *)(c + 0x80) = *(int *)(c + 0x84);
                *(int *)(c + 0x114) = v * 0x3c;
                *(int *)(c + 0x118) = v * 0x50;
                func_0203568c((int *)(c + 0x144), v * 0x3c);
                func_02035684((int *)(c + 0x144), v * 0x3c);
                func_ov002_020ef228(c + 0x144, (int)c);
            }
            *(int *)(c + 0x128) &= ~4;
            if (*(unsigned short *)(c + 0x3ea) == 2) {
                *(int *)(c + 0x128) |= 0x4000;
            }
        } else {
            func_ov102_0214b128(c);
        }
    }
    return 1;
}
