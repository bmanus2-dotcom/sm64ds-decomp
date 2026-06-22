typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef short s16;

extern s16 data_02086384[];
extern int func_0205acfc(int a, int b, int c);

void func_0204f82c(void** obj, int b, int idx) {
    unsigned char* p = (unsigned char*)*obj;
    if (p == 0) return;
    func_0205acfc(p[0x3c], b, data_02086384[idx]);
}
