// NONMATCHING: div=35; SMULL schedule floor; pure C replaces HAND-ASM
typedef short s16;
typedef unsigned short u16;
typedef long long s64;
extern int Vec3_Dist(void *a, void *b);
extern s16 Vec3_HorzAngle(void *a, void *b);
extern int func_ov095_0213579c(void *self, void *p);
extern int AngleDiff(int a, int b);
extern s16 data_02082214[];

void func_ov095_02135cdc(char *self, char *p) {
    char *pv = p + 0x5c;
    int dist = Vec3_Dist(self + 0x5c, pv);
    int angle = Vec3_HorzAngle(self + 0x5c, pv);
    int ret, fd, ad, idx, tv, ip, w, fr, bound;
    s16 *p8c, f324, cur;
    self[0x326] = 1;
    ret = func_ov095_0213579c(self, p);
    p8c = (s16 *)(((s64)(int)(self + 0x8c)) & 0xFFFFFFFFFFFFFFFFLL);
    f324 = *(s16 *)(self + 0x324);
    {
        s64 prod = (s64)dist * ret;
        cur = *p8c;
        *p8c = (s16)(cur + f324);
        fd = (int)((prod + 0x800) >> 12);
    }
    ad = AngleDiff(angle, *(s16 *)(self + 0x8e));
    idx = ((u16)(s16)ad >> 4) << 1;
    idx = idx + 1;
    f324 = *(s16 *)(self + 0x324);
    tv = data_02082214[idx];
    ip = (int)(((s64)fd * tv + 0x800) >> 12);
    if (f324 * fd < 0)
        w = (int)(((s64)ip * 0xa3 + 0x800) >> 12);
    else
        w = (int)(((s64)ip * 0x51 + 0x800) >> 12);

    fr = (int)(((s64)ret * 0x32000 + 0x800) >> 12);
    {
        s16 *p324 = (s16 *)(self + 0x324);
        s16 v;
        w = (w + ((unsigned)(w >> 11) >> 20)) << 4;
        v = (s16)(*p324 + (w >> 16));
        *p324 = v;
        bound = ((fr + ((unsigned)(fr >> 11) >> 20)) << 4) >> 16;
        if (v > bound) *p324 = bound;
        v = *p324;
        if (v < -bound) *p324 = -bound;
    }
}
