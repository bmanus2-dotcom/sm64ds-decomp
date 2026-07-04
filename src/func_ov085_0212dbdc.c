// NONMATCHING: different op / idiom (div=39). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
extern char* _ZN5Actor13ClosestPlayerEv(void);
extern void func_0201f32c(int a);
extern void func_ov002_020c3f2c(void);
extern void func_ov085_0212e728(char* c, void* p);
extern unsigned char data_0209d66c[];
extern char data_ov085_021307f0[];

int func_ov085_0212dbdc(char* c)
{
    char* player = _ZN5Actor13ClosestPlayerEv();
    int v;
    if (player == 0)
        return 1;
    *(int*)(c + 0x2c8) += 1;
    v = *(int*)(c + 0x2c8);
    switch (v) {
    case 1:
        func_0201f32c(2);
        break;
    case 0x14:
        func_ov002_020c3f2c();
        break;
    case 0x28:
        data_0209d66c[0] = 1;
        break;
    case 0x8c:
        func_0201f32c(3);
        break;
    case 0xee:
        data_0209d66c[0] = 1;
        break;
    case 0xf0:
        *(short*)(player + 0x8c) = 0;
        *(short*)(player + 0x8e) = *(short*)(c + 0x2d4);
        *(short*)(player + 0x90) = 0;
        *(short*)(player + 0x92) = 0;
        *(short*)(player + 0x94) = *(short*)(c + 0x2d4);
        *(short*)(player + 0x96) = 0;
        func_ov085_0212e728(c, data_ov085_021307f0);
        break;
    }
    return 1;
}
