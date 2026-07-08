//cpp
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual void v18(int);
};
typedef void (Obj::*PMF)(int);

extern "C" {
    void func_ov006_020f0044(void *c);
    void func_ov006_020f10ec(void *c);
    void func_ov006_020f0274(void *c);
    void func_ov004_020b0a54(int arg);
}
extern PMF data_ov006_02142254[];

extern "C" void func_ov006_020f300c(char *self) {
    int count;
    int i;
    int id;
    int j;
    int v;
    char *p51;

    func_ov006_020f0044(self);
    func_ov006_020f10ec(self);
    func_ov006_020f0274(self);

    count = 0;
    for (i = 0; i < 0x78; i++) {
        char *p = self + i + 0x5000;
        if (*(unsigned char *)(p + 0x2ed) != 0 &&
            (id = *(unsigned char *)(p + 0x1fd)) == 9) {
            count++;
            (((Obj *)self)->*data_ov006_02142254[id])(i);
        }
    }
    if (count != 0) return;

    for (j = 0; j < 0x78; j++) {
        unsigned char *q =
            (unsigned char *)(((long long)(int)((self + j) + 0x53dd)) & 0xFFFFFFFFFFFFFFFFLL);
        if (*q == 1) *q = 0;
    }

    p51 = self + 0x5100;
    if (*(unsigned short *)(p51 + 0x6a) == 0) return;
    *(unsigned short *)(p51 + 0x64) = 1;
    *(unsigned short *)(((long long)(int)(self + 0x516a)) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
    if (*(short *)(p51 + 0x6a) > 0) return;
    *(unsigned short *)(p51 + 0x6a) = 0;
    *(unsigned short *)(p51 + 0x64) = 0;

    if (*(unsigned char *)(self + 0x5459) != 0) {
        v = *(int *)(self + 0xbc);
        while (v >= 5) v -= 5;
        if (v != 4) {
            ((Obj *)self)->v18(-1);
        } else {
            func_ov004_020b0a54(1);
        }
    } else {
        func_ov004_020b0a54(0x12);
    }
    *(unsigned char *)(self + 0xc3) = 0;
}
