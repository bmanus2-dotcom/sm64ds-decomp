typedef struct { int a, b; } Pair2;

extern void func_020127a4(int a, int b, int c, int d);
extern void func_ov004_020adfc4(int a, int b, void* c, void* d, void* e);
extern int data_ov006_0212e418[];

void func_ov006_020dd658(char* self, int i)
{
    int off = i * 0x1c;
    int oldvel;
    int v;
    int posi;
    char* p;
    Pair2 s1;
    Pair2 s2;

    oldvel = *(int*)(self + 0x466c + off);
    *(int*)(self + 0x4664 + off) = *(int*)(self + 0x4664 + off) + oldvel;
    *(int*)(self + 0x466c + off) = *(int*)(self + 0x466c + off) + 0x600;
    if (oldvel <= 0 && *(int*)(self + 0x466c + off) >= 0) {
        v = *(int*)(self + off + 0x4660) >> 0xc;
        v = (v - 0x80) >> 1;
        if (v >= 0x3c) v = 0x3c;
        if (v <= -0x3c) v = -0x3c;
        func_020127a4(2, 0xec, 0xffff, v);
    }
    p = self + off + 0x4000;
    posi = *(int*)(self + 0x4664 + off) >> 0xc;
    if (*(int*)(self + 0x466c + off) < 0) return;
    if (posi <= data_ov006_0212e418[*(unsigned char*)(p + 0x674)] - 0x20) return;
    *(char*)(p + 0x675) = 4;
    *(char*)(p + 0x676) = 0;
    *(char*)(p + 0x677) = 0;
    *(unsigned short*)(((long long)(int)(self + 0x4d08)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
    s1.b = *(int*)(self + 0x4664 + off);
    s1.a = *(int*)(p + 0x660);
    s2.a = 0x6c000;
    s2.b = -0x80000;
    func_ov004_020adfc4(1, 0x20, &s1, &s1, &s2);
}
