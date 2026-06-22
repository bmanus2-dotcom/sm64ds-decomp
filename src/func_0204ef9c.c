typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

int func_0204ef9c(void* p) {
    if (*(u32*)p != 0x4352414e) return 0;
    if (*(u16*)((char*)p + 4) != 0xfffe) return 0;
    return *(u16*)((char*)p + 6) == 0x100;
}
