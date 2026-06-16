extern int func_ov090_021332e8(char*, int*);
extern int data_ov090_02134594[];

int func_ov077_02126a50(char *c) {
    unsigned short h = *(unsigned short*)(c + 0x100);
    if (h == 0) {
        func_ov090_021332e8(c, data_ov090_02134594);
    }
    return 1;
}
