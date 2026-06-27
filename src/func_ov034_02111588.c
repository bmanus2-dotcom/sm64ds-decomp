extern unsigned char DecIfAbove0_Byte(unsigned char *p);
extern void func_ov034_021125b8(char *c, int i);

void func_ov034_02111588(char *c) {
    if (DecIfAbove0_Byte((unsigned char *)(c + 0x8da)) != 0) return;
    func_ov034_021125b8(c, 0xa);
}
