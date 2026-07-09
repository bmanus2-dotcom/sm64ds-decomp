extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);
extern unsigned char data_ov006_0212efcc[];

void func_ov006_0211db7c(char *c, int idx)
{
    int n;
    char *b;
    int t;
    unsigned short d;

    n = idx << 5;
    b = c + n;
    (*(unsigned short *)(c + 0x4bb2 + n))++;
    if (*(unsigned short *)(c + 0x4bb2 + n) >= 8) {
        *(unsigned short *)(c + 0x4bb2 + n) = 0;
        (*(unsigned char *)(c + 0x4bbd + n))++;
        if (*(unsigned char *)(b + 0x4bbd) >= 8)
            *(unsigned char *)(b + 0x4bbd) = 0;
        *(unsigned char *)(b + 0x4bb8) = data_ov006_0212efcc[*(unsigned char *)(b + 0x4bbd)];
    }
    t = *(int *)(b + 0x4ba0) >> 12;
    if (t <= 0x80) {
        *(int *)(b + 0x4ba0) = 0x80000;
    } else {
        *(int *)(c + 0x4ba0 + n) = *(int *)(c + 0x4ba0 + n) + *(int *)(b + 0x4ba8);
        if (*(int *)(b + 0x4ba8) <= -0x600)
            *(int *)(c + 0x4ba8 + n) = *(int *)(c + 0x4ba8 + n) + 0x20;
    }
    d = *(unsigned short *)(b + 0x4bb4);
    if (d != 0) {
        (*(unsigned short *)(b + 0x4bb4))--;
        return;
    }
    _ZN5Sound12PlayBank2_2DEj(0x1f3);
    *(unsigned char *)(b + 0x4bba) = 2;
    *(unsigned char *)(b + 0x4bbd) = 0;
    *(unsigned char *)(b + 0x4bb8) = 0;
    *(unsigned short *)(b + 0x4bb2) = 0;
    *(int *)(b + 0x4ba8) = 0;
}