typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern u32 data_020a6480[];
extern void func_0205b358(void);
extern void func_0205b524(void);

void func_0205a82c(void) {
    if (data_020a6480[0] != 0) return;
    data_020a6480[0] = 1;
    func_0205b358();
    func_0205b524();
}
