extern void func_ov004_020adb1c(int self);
extern void func_ov006_020c72b4(void);
extern void func_ov006_020c72c8(void);
extern int RandomIntInternal(int *seed);
extern void func_ov006_020c719c(unsigned int a0, unsigned int a1);
extern void func_ov006_020c44b4(int a, int b);
extern void func_ov006_020ee658(char *c);

extern char *func_020beb68;
extern int data_0209e650;
extern int data_ov006_0213cb48;
extern int data_ov006_02140328;

void func_ov006_020ee994(char *self, int flag)
{
    int timer;
    int level;
    int tmp;

    if (flag == 0) {
        *(int *)(self + 0xbc) += 1;
        if (*(unsigned int *)(self + 0xbc) > 0x270e) {
            *(int *)(self + 0xbc) = 0x270e;
        }
    } else if (flag == 0x12) {
        *(int *)(self + 0xbc) = 0;
        if (*(unsigned int *)(self + 0xbc) > 0x270e) {
            *(int *)(self + 0xbc) = 0x270e;
        }
        if (func_020beb68 != 0) {
            *(int *)(func_020beb68 + 0xb4) = 0;
        }
        func_ov004_020adb1c(*(int *)(self + 0xb4));
    } else {
        if (func_020beb68 != 0) {
            *(int *)(func_020beb68 + 0xb4) = *(int *)(self + 0xbc);
        }
    }

    if (*(int *)(self + 0xbc) == 0) {
        func_ov006_020c72c8();
    } else {
        func_ov006_020c72b4();
    }

    timer = *(int *)(self + 0xbc);
    level = timer;
    if (timer >= 0xf) {
        do {
            tmp = RandomIntInternal(&data_0209e650);
            tmp &= 0x7fffffff;
            tmp = (tmp >> 0x13) * 0xa;
            level = tmp >> 0xc;
        } while (level == data_ov006_0213cb48);
        data_ov006_0213cb48 = level;
    }

    func_ov006_020c719c((unsigned int)timer, (unsigned int)level);

    if (timer < 0xf) {
        data_ov006_02140328 = 3;
    } else if (timer < 0x14) {
        data_ov006_02140328 = 4;
    } else if (timer < 0x19) {
        data_ov006_02140328 = 5;
    } else {
        data_ov006_02140328 = 6;
    }

    func_ov006_020c44b4(timer, level);
    func_ov006_020ee658(self);
}