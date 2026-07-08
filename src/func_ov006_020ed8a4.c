typedef struct { int a, b; } Pair2;

extern int func_ov006_020ebe6c(void);
extern int RandomIntInternal(int* seed);
extern void func_ov006_020ebd7c(int count);
extern void func_ov006_020ecdb8(void* self, int arg1, int arg2);
extern void func_ov004_020b0cac(int c, int a1, int a2, int a3, int arg5, short arg6);

extern short data_ov006_0212e80c[];
extern short data_ov006_02141fd8;
extern int data_ov006_0212e820[];
extern int data_ov006_0213c958;
extern int data_0209e650;
extern Pair2 data_ov006_0213c964;

void func_ov006_020ed8a4(char* self)
{
    int r0v;
    unsigned int rnd;
    int i;
    int val;
    char* p;
    char* ep;

    if (*(int*)(self + 0xbc) < 0xa) {
        data_ov006_02141fd8 = data_ov006_0212e80c[*(int*)(self + 0xbc)];
        data_ov006_0213c958 = data_ov006_0212e820[*(int*)(self + 0xbc)];
    } else {
        r0v = func_ov006_020ebe6c();
        data_ov006_02141fd8 = (short)r0v;
        if (r0v == 3) {
            data_ov006_0213c958 = 0xf;
        } else {
            rnd = ((unsigned int)RandomIntInternal(&data_0209e650) & 0x7fffffff) >> 0x13;
            data_ov006_0213c958 = ((int)(rnd * 3) >> 0xc) + 3;
        }
    }
    if ((unsigned int)*(int*)(self + 0xbc) < 0xa)
        func_ov006_020ebd7c(2);
    else
        func_ov006_020ebd7c(3);
    ep = self + 0x4678;
    for (i = 0; i < data_ov006_0213c958; i++) {
        func_ov006_020ecdb8(ep, i, *(int*)(self + 0xbc));
        ep += 0x98;
    }
    rnd = ((unsigned int)RandomIntInternal(&data_0209e650) & 0x7fffffff) >> 0x13;
    val = (int)(rnd * data_ov006_0213c958) >> 0xc;
    p = self + 0x4000;
    *(int*)(p + 0xf60) = (int)(self + 0x4678 + val * 0x98);
    *(int*)(*(int*)(p + 0xf60) + 0x70) = 0;
    *(int*)(p + 0x668) = 0x3c;
    func_ov004_020b0cac(0xd, 0x80, 0x50, 1, -1, 0xd);
    *(int*)(p + 0x674) = 0x3c;
    *(char*)(p + 0xf64) = 0;
    *(Pair2*)(p + 0x660) = data_ov006_0213c964;
}
