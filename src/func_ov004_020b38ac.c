// NONMATCHING: different op / idiom (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef long long s64;
typedef unsigned short u16;
extern int func_02053200(int x);
extern void func_ov004_020b1c68(void* a0, int a1, int a2, int a3, int a4, int a5);

void func_ov004_020b38ac(char* sl)
{
    int s[4];
    char* sb = sl + 0x34;
    int base = *(int*)(sl + 0x24) >> 2;
    int r7 = 0x1000;
    u16 field;
    do {
        int d = base - r7;
        int weight = 0x1000;
        int w;
        if (d < 0) d = -d;
        if (d < 0x1000) {
            weight += (int)((((s64)(0x1000 - d) << 10) + 0x800) >> 12);
        }
        w = func_02053200(weight);
        s[0] = 0;
        s[1] = 0;
        s[2] = 0;
        s[3] = 0;
        s[0] = w;
        s[3] = w;
        func_ov004_020b1c68(sb, *(short*)(sl + 0x10), *(short*)(sl + 0x12),
                            *(int*)(sl + 0x1c), *(int*)(sl + 0x18), (int)s);
        field = *(u16*)(sb + 6);
        r7 += 0x1000;
        sb += 8;
    } while (field != 0xffff);
}
