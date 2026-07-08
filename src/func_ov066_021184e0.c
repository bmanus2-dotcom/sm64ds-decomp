extern int func_ov066_021168ec(void *c);
extern void func_ov066_021162e8(void *c);
extern void func_ov066_0211632c(void *c);
extern void func_ov066_02116ac4(void *c, int strength);
extern unsigned char data_ov066_0211ae0c;

int func_ov066_021184e0(char *c) {
    int m;
    unsigned char v;
    if (func_ov066_021168ec(c) != 0 && func_ov066_021168ec(c) != 4) {
        *(int *)(c + 0xb0) = 0;
        func_ov066_021162e8(c);
        return 1;
    }
    func_ov066_0211632c(c);
    switch (*(int *)(c + 0x4a0)) {
    case 0:
        if (data_ov066_0211ae0c == *(int *)(c + 0x49c)) {
            *(int *)(c + 0x9c) = -0x14000;
            *(int *)(c + 0xa8) = 0x64000;
            *(int *)(((long long)(int)(c + 0x4a0)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
        }
        break;
    case 1:
        if (*(int *)(c + 0x9c) != 0) {
            if (*(int *)(c + 0x4a8) >= *(int *)(c + 0x60)) {
                *(int *)(c + 0x60) = *(int *)(c + 0x4a8);
                *(int *)(c + 0xa8) = 0;
                *(int *)(c + 0x9c) = 0;
                func_ov066_02116ac4(c, 0x7d0000);
                m = *(int *)(c + 0x49c);
                v = data_ov066_0211ae0c;
                if (v & m) {
                    data_ov066_0211ae0c = v ^ m;
                }
                *(int *)(c + 0x4a0) = 0;
            }
        }
        break;
    }
    return 1;
}
