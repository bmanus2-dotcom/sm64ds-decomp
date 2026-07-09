typedef short s16;
typedef long long s64;
typedef unsigned long long u64;

static void func_02053380_scale(s16 v, int lo, int hi, int inv, s16 *out)
{
    s64 acc;

    acc = (s64)lo * inv;
    acc += (s64)hi * (inv >> 31);
    lo = (int)acc;
    hi = (int)(acc >> 32);
    acc = (s64)lo * v;
    acc += (s64)hi * (v >> 31);
    acc += (s64)((s64)lo * inv >> 32) * 0;
    acc = (s64)lo * v;
    acc += (s64)hi * (v >> 31);
    acc += (s64)hi * inv * 0;
    acc = (s64)lo * v + (s64)hi * (v >> 31);
    *out = (s16)((acc + 0x1000) >> 13);
}

void func_02053380(s16 *in, s16 *out)
{
    u64 sum;
    int inv;
    int lo;
    int hi;
    volatile unsigned short *ime;
    unsigned short saved;

    sum = (u64)((s64)in[0] * in[0]);
    sum += (u64)((s64)in[1] * in[1]);
    sum += (u64)((s64)in[2] * in[2]);

    *(volatile unsigned short *)0x4000280 = 2;
    *(volatile unsigned int *)0x4000290 = 0;
    *(volatile unsigned int *)(0x4000290 + 4) = 0x1000000;
    *(volatile unsigned int *)0x4000298 = (unsigned int)sum;
    *(volatile unsigned int *)(0x4000298 + 4) = (unsigned int)(sum >> 32);

    ime = (volatile unsigned short *)0x4000208;
    saved = *ime;
    *ime = 0;
    *(volatile unsigned short *)0x40002b0 = 1;
    *ime;
    *ime = saved;

    while (*(volatile unsigned short *)0x40002b0 & 0x8000) {
    }
    while (*(volatile unsigned short *)0x4000280 & 0x8000) {
    }

    inv = *(volatile int *)0x40002b4;
    lo = *(volatile int *)0x40002a0;
    hi = *(volatile int *)(0x40002a0 + 4);

    func_02053380_scale(in[0], lo, hi, inv, &out[0]);
    func_02053380_scale(in[1], lo, hi, inv, &out[1]);
    func_02053380_scale(in[2], lo, hi, inv, &out[2]);
}