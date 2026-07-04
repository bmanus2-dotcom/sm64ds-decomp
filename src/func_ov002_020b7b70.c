// NONMATCHING: base materialization / addressing (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern u8 data_0209f2d8;

int func_ov002_020b7b70(char* c)
{
    int state;
    int* p;

    state = *(int*)(c + 0x3f0);
    if (state == 5 || state == 7 || state == 9) {
        *(u16*)(c + 0x100) = 0xd2;
        if ((int)(data_0209f2d8 == 1) == 0) *(u16*)(c + 0x100) = 0x78;
        *(u16*)(c + 0x404) = *(u16*)(c + 0x100);
    }

    state = *(int*)(c + 0x3f0);
    if (state == 0x12) {
        *(u16*)(c + 0x100) = 0x12c;
        *(u16*)(c + 0x404) = *(u16*)(c + 0x100);
    }

    state = *(int*)(c + 0x3f0);
    if (state == 0xb) {
        *(u16*)(c + 0x100) = 0xb4;
        *(u16*)(c + 0x404) = *(u16*)(c + 0x100);
    }

    p = (int*)(c + 0x12c);
    *p = *p | 0x8000;
    return 1;
}
