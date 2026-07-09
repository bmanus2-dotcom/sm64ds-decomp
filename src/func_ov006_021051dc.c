extern int __aeabi_idiv(int, int);
extern void func_ov006_02104cfc(char *c, int i);

void func_ov006_021051dc(char *c)
{
    int W;
    int n1;
    int n2;
    int a;
    int b;
    int i;
    int j;
    int x;
    unsigned char *p;

    if (*(short *)(c + 0x4ec4) != 0) {
        (*(short *)(c + 0x4ec4))--;
        if (*(short *)(c + 0x4ec4) < 0)
            *(short *)(c + 0x4ec4) = 0;
        return;
    }
    if (*(unsigned char *)(c + 0x4fe5) >= *(unsigned char *)(c + 0x4fde)) {
        *(short *)(c + 0x4ec0) = 0x50;
        *(int *)(c + 0x4ca8) = 6;
        *(unsigned char *)(c + 0x4fe6) = 0;
        return;
    }
    x = *(unsigned char *)(c + (*(unsigned char *)(c + 0x4fe5)) + 0x4fae);
    W = *(int *)(c + 0x4cbc);
    n1 = 3;
    n2 = 3;
    a = __aeabi_idiv(x, W);
    b = x % W;
    if (b == 0 || b == W - 1)
        n1 = 2;
    if (a == 0 || a == W - 1)
        n2 = 2;
    if (b > 0)
        b--;
    else
        b = 0;
    if (a > 0)
        a--;
    else
        a = 0;
    for (i = 0; i < n2; i++) {
        for (j = 0; j < n1; j++) {
            p = (unsigned char *)c + (W * (b + i) + (a + j) + 0x4f1e);
            *(unsigned char *)(c + (W * (b + i) + (a + j) + 0x4efa)) = 1;
            *p ^= 1;
            *(short *)(c + ((W * (b + i) + (a + j)) << 1) + 0x4e78) = 8;
        }
    }
    func_ov006_02104cfc(c, x);
    *(short *)(c + ((x << 1) + 0x4e78)) = 0;
    *(short *)(c + 0x4ec4) = 0x30;
    (*(unsigned char *)(c + 0x4fe5))++;
}