//cpp
// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
struct V3 { int x, y, z; };
extern "C" {
void func_ov063_02119e38(char* c, int a, int b, int d);
int func_ov063_0211a0dc(char* c);
int func_ov063_0211adb4(char* c);
void func_0201267c(int a, void* p);
int _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int, unsigned int, struct V3*, void*, int, int);

void func_ov063_02116e14(char* c){
    unsigned short* fl = (unsigned short*)(c + 0x5d4);
    *fl &= ~0x40;
    if (*(unsigned short*)(c + 0x5c0) == 0) {
        func_ov063_02119e38(c, 0x64, 0x200, 0x800);
    }
    {
        int r5 = func_ov063_0211a0dc(c);
        if (func_ov063_0211adb4(c) != 0) {
            *(unsigned char*)(c + 0x5cc) = 0;
        }
        if (r5 == -1) {
            *(unsigned char*)(c + 0x5cc) = 2;
            return;
        }
        if (r5 != 1) return;
    }
    if ((unsigned int)((unsigned short)*(unsigned short*)(c + 0x5d4) << 0x19) >> 0x1f) {
        *(unsigned char*)(c + 0x5cc) = 4;
        func_0201267c(0x14a, c + 0x74);
        return;
    }
    *(unsigned char*)(c + 0x5cc) = 3;
    {
        char* r = (char*)_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
            *(unsigned short*)(c + 0x4a0), 0, (struct V3*)(c + 0x504), 0,
            *(signed char*)(c + 0x5d0), -1);
        if (r != 0) {
            *(int*)(r + 0xa4) = 0;
            *(int*)(r + 0xa8) = 0x32000;
            *(int*)(r + 0xac) = 0;
        }
    }
    *(unsigned short*)(c + 0x5d4) &= ~2;
}
}
