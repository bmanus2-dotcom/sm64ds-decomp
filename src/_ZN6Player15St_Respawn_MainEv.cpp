//cpp
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern "C" {
extern void FUN_02029980(void);
extern void FUN_02029934(void);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(void *c, u32 a, int b, int f, u32 g);
extern int _ZN6Player12FinishedAnimEv(void *c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void *c, void *s);
extern void func_ov002_020bedd4(void *c);
extern u8 data_0209f250;
extern int data_ov002_02110154[];
}

extern "C" int _ZN6Player15St_Respawn_MainEv(char *c)
{
    switch (*(u8 *)(c + 0x6e3)) {
    case 0: {
        u16 t = *(u16 *)(c + 0x6a4);
        if (t != 0) {
            if (t == 1) {
                *(int *)(c + 0x9c) = -0x4000;
                if (*(u8 *)(c + 0x6d8) == data_0209f250) {
                    FUN_02029980();
                    *(u16 *)(c + 0x6a6) = 0x26;
                }
            }
        } else {
            if (*(u8 *)(c + 0x6de) == 0) {
                u32 zero = 0;
                _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x55, 0x40000000, 0x1000, zero);
                *(u8 *)(((int)c + 0x6e3) & 0xFFFFFFFFFFFFFFFF) += 1;
            }
        }
        break;
    }
    case 1:
        if (_ZN6Player12FinishedAnimEv(c) != 0) {
            int z = 0;
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x47, z, 0x1000, z);
            *(u8 *)(((int)c + 0x6e3) & 0xFFFFFFFFFFFFFFFF) += 1;
        }
        break;
    case 2:
        if (*(u16 *)(c + 0x6a6) == 0) {
            if (*(u8 *)(c + 0x6d8) == data_0209f250) {
                FUN_02029934();
            }
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_02110154);
        }
        break;
    }
    func_ov002_020bedd4(c);
    return 1;
}
