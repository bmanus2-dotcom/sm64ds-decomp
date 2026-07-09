// NONMATCHING: dual-timer dispatch tree (div~36, 0x16c vs 0x190); sibling func_ov006_0211fd44
typedef unsigned char u8;

extern void func_ov006_0211d5a8(char *c);
extern void func_ov006_0211f9fc(char *c);
extern void func_ov006_0211e0c8(char *c);
extern void func_ov006_0211e7d8(char *c);
extern void func_ov006_0211dec0(char *c);
extern void func_ov006_0211f6fc(char *c);
extern int func_ov006_0211de7c(char *c);
extern void func_ov006_0211d69c(char *c);
extern void func_ov006_0211de54(char *c);
extern void func_ov006_0211cc2c(char *c);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int id);

extern u8 data_0209d454;

void func_ov006_0211fe78(char *c)
{
    if (*(short *)(c + 0x4c0c) != 0) {
        *(short *)(c + 0x4c0c) -= 1;
        if (*(short *)(c + 0x4c0c) > 0) {
            return;
        }
        if (*(u8 *)(c + 0x4c1f) != 0) {
            func_ov006_0211e0c8(c);
            *(short *)(c + 0x4c0e) = 0x60;
            return;
        }
        func_ov006_0211e0c8(c);
        func_ov006_0211e7d8(c);
        *(short *)(c + 0x4c0e) = 0x60;
        return;
    }
    func_ov006_0211d5a8(c);
    func_ov006_0211f9fc(c);
    func_ov006_0211dec0(c);
    func_ov006_0211f6fc(c);
    if (func_ov006_0211de7c(c) != 0) {
        return;
    }
    if (*(short *)(c + 0x4c0e) != 0) {
        func_ov006_0211d69c(c);
        *(short *)(c + 0x4c0e) -= 1;
        if (*(short *)(c + 0x4c0e) < 0) {
            *(short *)(c + 0x4c0e) = 0;
        }
        return;
    }
    func_ov006_0211de54(c);
    *(int *)(c + 0x4be8) = 4;
    *(short *)(c + 0x4c0c) = 0x60;
    *(int *)0x4001000 = *(int *)0x4001000 & ~0xe000;
    data_0209d454 &= ~1;
    _ZN5Sound12PlayBank2_2DEj(0x1f7);
    func_ov006_0211cc2c(c);
    if (*(u8 *)(c + 0x4c1f) != 0) {
        _ZN5Sound12PlayBank2_2DEj(0x1f2);
    }
}