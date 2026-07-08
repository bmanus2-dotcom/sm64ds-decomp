typedef unsigned char u8;

extern int data_0213c264;
extern int data_0213c2ac;
extern int data_0212e468[];
extern void func_ov004_020b0104(void* a0, int a1, int a2, int a3, int a4, int a5);

void func_ov006_020e1c68(void* self) {
    char* p;
    char* b;
    int i;
    int sl, sb;
    int arrj;

    p = (char*)self;
    for (i = 0; i < 5; i++) {
        b = p + 0x4000;
        if (*(u8*)(b + 0x689) && *(u8*)(b + 0x68a)) {
            sl = *(int*)(b + 0x660) >> 12;
            sb = *(int*)(b + 0x664) >> 12;
            func_ov004_020b0104(&data_0213c264, sl, sb, -1, 1, 0);
            func_ov004_020b0104(&data_0213c2ac, sl, sb + 8, -1, 2, 0);
        }
        p += 0x2c;
    }

    sl = 5 - *(u8*)((char*)self + 0x4ee6);
    if (sl < 0) sl = 0;
    if (sl <= 0) return;
    for (sb = 0; sb < sl; sb++) {
        arrj = data_0212e468[sb];
        func_ov004_020b0104(&data_0213c264, arrj, 0xb0, -1, 1, sb);
        func_ov004_020b0104(&data_0213c2ac, arrj, 0xb8, -1, 2, sb);
    }
}
