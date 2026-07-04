// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 data_0209d45c;
extern u8 data_0209d454;
extern u8 data_0209d460;
extern u8 data_0209d458;

extern int _ZN2GX10LoadBGPlttEPKvjj(const void* p, u32 a, u32 b);
extern int _ZN3GXS10LoadBGPlttEPKvjj(const void* p, u32 a, u32 b);
extern void MultiCopy_Int(int* dst, int* src, int len);

typedef int (*VFN)(void* thiz);

void func_ov004_020aeed8(char* c)
{
    data_0209d45c = 0;
    data_0209d454 = 0;

    *(u32*)0x4000000 &= ~0x1f00;
    *(u32*)0x4001000 &= ~0x1f00;
    {
        u32 v = *(u32*)(c + 0x224);
        *(u16*)0x4000304 = (*(u16*)0x4000304 & ~0x8000) | (v << 15);
    }
    *(u32*)0x4000000 = (*(u32*)0x4000000 & ~0xe000) | ((u32)data_0209d460 << 13);
    *(u32*)0x4001000 = (*(u32*)0x4001000 & ~0xe000) | ((u32)data_0209d458 << 13);

    _ZN2GX10LoadBGPlttEPKvjj(c + 0x4228, 0x20, 0x1e0);
    _ZN3GXS10LoadBGPlttEPKvjj(c + 0x4228 + 0x200, 0, 0x80);

    if ((*(VFN*)((*(char**)c) + 0x68))(c) == 2)
        return;

    MultiCopy_Int((int*)(c + 0x2228), (int*)0x6606000, 0x2000);

    data_0209d45c = *(u8*)(c + 0x21c);
    data_0209d454 = *(u8*)(c + 0x220);

    if ((*(VFN*)((*(char**)c) + 0x68))(c) == 2)
        return;

    *(u32*)0x4000000 = (*(u32*)0x4000000 & ~0x1f00) | ((u32)data_0209d45c << 8);
    *(u32*)0x4001000 = (*(u32*)0x4001000 & ~0x1f00) | ((u32)data_0209d454 << 8);
}
