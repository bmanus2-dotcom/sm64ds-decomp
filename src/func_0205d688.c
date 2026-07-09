typedef int s32;

extern int func_0205cdf4(void *self, s32 n);
extern int func_0205d3f4(void *self);

int func_0205d688(char *self, s32 a, s32 b, s32 flag)
{
    s32 pos;
    s32 remain;
    s32 count;
    int *p;

    pos = *(s32 *)(self + 0x28);
    remain = *(s32 *)(self + 0x24) - pos;
    count = b;
    if (count > remain) {
        count = remain;
    }
    *(s32 *)(self + 0x2c) = a;
    if (count < 0) {
        count = 0;
    }
    *(s32 *)(self + 0x30) = b;
    *(s32 *)(self + 0x34) = count;
    if (flag == 0) {
        p = (int *)(((long long)(int)(self + 0xc)) & 0xFFFFFFFFFFFFFFFFLL);
        *p |= 4;
    }
    func_0205cdf4(self, 0);
    if (flag != 0) {
        return count;
    }
    if (func_0205d3f4(self) != 0) {
        count = *(s32 *)(self + 0x28) - pos;
    } else {
        count = 0;
    }
    return count;
}