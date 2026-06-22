extern void func_020731dc(void*, void*, void*);
extern int data_ov002_0211116c[];
extern int func_020072c0[];
extern int data_ov002_02111160[];

void __sinit_ov002_0210804c(void) {
    *(unsigned int*)data_ov002_0211116c = 0x80000;
    *(unsigned int*)((char*)data_ov002_0211116c + 4) = 0;
    *(unsigned int*)((char*)data_ov002_0211116c + 8) = 0x60000;
    func_020731dc(data_ov002_0211116c, func_020072c0, data_ov002_02111160);
}
