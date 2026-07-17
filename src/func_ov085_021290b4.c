extern signed char data_0209f2f8;
extern int func_020138dc(void);
extern int func_02013a44(void);
extern unsigned short ObjectMessageIDToActualMessageID(short);

unsigned short func_ov085_021290b4(char* c) {
    int* r5 = *(int**)(c + 0x1f8);
    unsigned short r4 = *(unsigned short*)(c + 0x200 + 8);
    if (data_0209f2f8 == 0x32) {
        int v = func_020138dc();
        switch (v) {
        case 0x1c:
            return 0x134;
        case 0: {
            int msg = ObjectMessageIDToActualMessageID((short)r4);
            int sum = msg + r5[2];
            return (unsigned short)sum;
        }
        default:
            return 0x133;
        }
    }
    if (*(unsigned char*)(c + 0x20b) == 1) {
        if (func_02013a44() != 0) {
            int n = r5[2];
            int t = 0xb0a;
            t = t + n;
            return ObjectMessageIDToActualMessageID((short)(unsigned short)t);
        }
    }
    {
        int msg = ObjectMessageIDToActualMessageID((short)r4);
        int sum = msg + r5[2];
        return (unsigned short)sum;
    }
}
