typedef short s16;

extern unsigned char data_020a0e40;
extern s16 data_0209f4a4[];
extern s16 data_02082214[];
extern void func_ov002_020cd448(char *self);

void func_ov002_020cd550(char *self)
{
    s16 v;
    s16 tgt;
    s16 cur;
    s16 step;
    s16 mag;
    int tmp;
    int idx;
    long long prod;

    v = data_0209f4a4[data_020a0e40 * 0x18];
    prod = (long long)v * (long long)-0x3f00;
    tmp = (int)((unsigned long long)(prod + 0x800) >> 12);
    tgt = (s16)(((s16)tmp) & 0xfff0);
    cur = *(s16 *)(self + 0x92);
    if (cur > 0)
        step = 0x100;
    else
        step = 0x200;
    if (cur < tgt) {
        *(s16 *)(self + 0x92) = cur + step;
        if (*(s16 *)(self + 0x92) > tgt)
            *(s16 *)(self + 0x92) = tgt;
    } else if (cur > tgt) {
        *(s16 *)(self + 0x92) = cur - step;
        if (*(s16 *)(self + 0x92) < tgt)
            *(s16 *)(self + 0x92) = tgt;
    }
    func_ov002_020cd448(self);
    mag = *(s16 *)(self + 0x92);
    if (mag < 0) {
        tmp = (int)mag * 6;
        *(s16 *)(self + 0x8c) = (s16)(tmp / 10);
    } else {
        tmp = (int)mag * 10;
        *(s16 *)(self + 0x8c) = (s16)((tmp + (tmp >> 29)) >> 3);
    }
    *(int *)(self + 0x690) = 0;
    mag = *(s16 *)(self + 0x8c);
    if (mag >= 0) {
        prod = (long long)mag * 0xc000;
        tmp = (int)((unsigned long long)(prod + 0x800) >> 12);
        *(int *)(self + 0x690) = tmp;
    }
    tmp = *(s16 *)(self + 0x8c) - 0x2000;
    if (tmp < -0x2000)
        tmp = -0x2000;
    if (tmp > 0)
        tmp = 0;
    idx = ((tmp >> 4) << 1) + 1;
    *(int *)(self + 0x694) = (int)data_02082214[idx] * -0x30;
}