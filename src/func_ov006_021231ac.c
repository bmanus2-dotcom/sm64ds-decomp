extern void func_0203cd80(int* m, int angle);
extern void func_ov006_02120c08(void);
extern void func_ov006_020eef58(void);
extern int func_0203d880(void);
extern int func_ov004_020ad674(void);
extern void func_ov004_020afcf8(void* a0, void* a1, int a2, void* a3);
extern int func_ov004_020afa20(int a0, int a1, int a2, int a3, int a4);
extern void func_ov004_020b1a5c(int a0, int a1);
extern void func_ov006_020caadc(void);
extern void func_ov006_020d09e0(void);
extern void func_ov006_020ced84(void);
extern void func_ov006_02122a4c(void);

extern int data_ov006_0213b0f0;
extern int data_ov006_02134ecc;
extern int* data_ov006_0213fc48[];
extern int data_ov006_02140830;

int func_ov006_021231ac(int self)
{
    int sp4;
    int sp8;
    int spc;
    int sp10;
    int r2;
    int r1;
    int r4;
    int r0;
    int r3;
    int r9;
    int r10;
    int r8;
    int r11;
    int r7;
    int r5;
    int r6;

    sp4 = self;
    sp8 = 0;
    spc = 0;
    sp10 = 0xfffff008;
    func_0203cd80(&sp8, -0x4000);

    r1 = sp8;
    r0 = spc;
    r4 = sp10;
    r2 = r0 << 16;
    r3 = 0x3ff;
    r1 = r1 << 16;
    r0 = r4 << 16;
    r4 = r3 & (r1 >> 19);
    r1 = r3 & (r2 >> 19);
    r2 = r3 & (r0 >> 19);
    r1 = r4 | (r1 << 10);
    r3 = r1 | (r2 << 20);
    *(int*)0x40004c8 = r3;
    *(int*)0x40004cc = 0x7fff;
    *(int*)0x40004cc = 0x40007fff;

    func_ov006_02120c08();
    func_ov006_020eef58();

    if (*(unsigned short*)(sp4 + 0x4664) == 1) {
        r9 = 0x6e;
        r10 = data_ov006_0213b0f0;
        r0 = func_0203d880();
        if (r0 == 5)
            goto lang_adj;
        r0 = func_0203d880();
        if (r0 == 4) {
lang_adj:
            r9 -= 4;
        }

        r8 = 0;
        r11 = data_ov006_02134ecc;
        r7 = (int)data_ov006_0213fc48;
        r5 = 0;
        r4 = -1;
        r6 = 0xc;

        do {
            if (r8 < r10) {
                func_ov004_020afa20(r11, r9, r6, r4, r4);
            } else {
                r0 = func_ov004_020ad674();
                r0 = *(int*)(r7 + (r0 << 2));
                func_ov004_020afcf8((void*)*(int*)(r0 + 4), (void*)r9, r6, (void*)r5);
            }
            r8++;
            r9 += 0x12;
        } while (r8 < 3);
    }

    func_ov004_020b1a5c(data_ov006_02140830, 6);

    if (*(short*)(sp4 + 0x7ba8) == 0) {
        func_ov006_020caadc();
        func_ov006_020d09e0();
        func_ov006_020ced84();
    }

    func_ov006_02122a4c();
    return 1;
}