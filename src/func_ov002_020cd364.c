extern void func_ov002_020dc020(void *c);
extern void _ZN12CylinderClsn5ClearEv(void *p);
extern void _ZN12CylinderClsn6UpdateEv(void *p);

void func_ov002_020cd364(char *c) {
    func_ov002_020dc020(c);
    _ZN12CylinderClsn5ClearEv(c + 0x314);
    _ZN12CylinderClsn6UpdateEv(c + 0x314);
    *(short *)(c + 0x600 + 0xa4) = 2;
    *(unsigned char *)(c + 0x6e3) = 5;
}
