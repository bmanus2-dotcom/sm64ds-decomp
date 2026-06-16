extern void func_020731dc(void*, void*, void*);
extern int data_ov027_02113d10[];
extern int func_020072c0[];
extern int data_ov027_02113d04[];

void __sinit_ov027_02112f70(void) {
    *(unsigned int*)data_ov027_02113d10 = 0x27a52b;
    *(unsigned int*)((char*)data_ov027_02113d10 + 4) = 0xdf2000;
    *(unsigned int*)((char*)data_ov027_02113d10 + 8) = 0x2626bb;
    func_020731dc(data_ov027_02113d10, func_020072c0, data_ov027_02113d04);
}
