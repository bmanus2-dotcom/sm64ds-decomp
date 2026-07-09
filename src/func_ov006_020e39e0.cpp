//cpp
// NONMATCHING: star-combo score popup (div~999, size 0x280 vs 0x1bc). 0x3c-slot
// loop with func_ov004 score calls; struct offset layout needs refine pass.
extern "C" int func_ov004_020adbc0(void);
extern "C" void func_ov004_020adb1c(int score);

extern "C" void func_ov006_020e39e0(char *c, int idx, int row, int col)
{
    int i;
    char *a;
    char *b;
    int sum0;
    int sum1;
    char *slot;
    char *dst;
    unsigned short val;

    if (*(unsigned char *)(c + 0x4ff4) != 0)
        return;
    for (i = 0; i < 0x3c; i++) {
        a = c + row * 0x30 + col * 0x18;
        b = c + row * 0x30 + idx * 0x18;
        sum0 = *(int *)(a + 0x4660) + *(int *)(b + 0x4660);
        sum1 = *(int *)(a + 0x4664) + *(int *)(b + 0x4664);
        slot = c + i * 0x18;
        *(unsigned char *)(c + 0x4ff4) = 1;
        *(unsigned char *)(c + 0x4ff5 + i) = 1;
        *(int *)(slot + 0x4fe0) = sum0 >> 1;
        *(int *)(slot + 0x4fe4) = sum1 >> 1;
        *(unsigned short *)(slot + 0x4ff0) = 0x40;
        *(int *)(slot + 0x4fe8) = 0;
        *(int *)(slot + 0x4fec) = 0;
        if (*(unsigned char *)(a + 0x468d) != 0 && *(unsigned char *)(b + 0x468d) != 0) {
            dst = c + 0x4ff2;
            val = (unsigned short)((*(unsigned char *)(c + 0x55bf) + 1) * 10);
            *(unsigned short *)(dst + i * 2) = val;
            dst = dst + i * 2;
        } else if (*(unsigned char *)(a + 0x468d) == 0) {
            if (*(unsigned char *)(b + 0x468d) != 0) {
                dst = c + 0x4ff2;
                val = (unsigned short)((*(unsigned char *)(c + 0x55bf) + 1) * 10);
                *(unsigned short *)(dst + i * 2) = val;
                dst = dst + i * 2;
            } else {
                dst = c + 0x4ff2;
                val = (unsigned short)((*(unsigned char *)(c + 0x55bf) + 1) * 100);
                *(unsigned short *)(dst + i * 2) = val;
                *(unsigned char *)(c + 0x4ff5 + i) = 2;
                dst = dst + i * 2;
            }
        } else {
            dst = c + 0x4ff2;
            val = (unsigned short)((*(unsigned char *)(c + 0x55bf) + 1) * 100);
            *(unsigned short *)(dst + i * 2) = val;
            *(unsigned char *)(c + 0x4ff5 + i) = 2;
            dst = dst + i * 2;
        }
        *(unsigned char *)(c + 0x55bf) = (unsigned char)(*(unsigned char *)(c + 0x55bf) + 1);
        if (*(unsigned char *)(c + 0x55bf) >= 0x17)
            *(unsigned char *)(c + 0x55bf) = 0x17;
        func_ov004_020adb1c((int)(*(unsigned short *)dst + func_ov004_020adbc0()));
        col++;
        row += 0x18;
        if (col >= 0x3c)
            return;
    }
}