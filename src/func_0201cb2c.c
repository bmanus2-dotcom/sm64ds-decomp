extern int data_0209d6fc;
extern int data_0209d6e8;
extern int data_0209d70c;
extern int data_0209d6ec;
extern int data_0209d708;

void func_0201cb2c(void) {
    int ip = data_0209d6fc;
    int r2 = ip + 0x20;
    data_0209d6e8 = ip;
    data_0209d70c = r2;
    int r3 = r2 + *(int*)(r2 + 4);
    data_0209d6ec = r3;
    data_0209d708 = ip + 0x30;
}
