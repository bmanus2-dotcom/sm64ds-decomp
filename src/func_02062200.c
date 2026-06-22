typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern int func_020614d0(int x);
extern void func_0206165c(int i, int val);
extern int func_02061558(int a, int b);

int func_02062200(int x) {
    int r = func_020614d0(x);
    if (r != 0) return r;
    func_0206165c(1, x);
    r = func_02061558(1, 0);
    if (r == 0) return 2;
    return r;
}
