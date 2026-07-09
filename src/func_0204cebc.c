typedef short s16;
typedef long long s64;

extern void func_02053380(s16 *in, s16 *out);
extern s16 data_02099fc4[];

void func_0204cebc(char *obj)
{
    s16 sp0;
    s16 sp2;
    s16 sp4;
    s16 sp6;
    s16 sp8;
    s16 spA;
    s16 t0;
    s16 t1;
    s16 t2;
    s16 t3;
    s16 t4;
    s16 t5;

    sp0 = data_02099fc4[0];
    sp2 = data_02099fc4[1];
    sp4 = data_02099fc4[2];
    func_02053380((s16 *)(obj + 0x3c), &sp6);
    if (sp0 == sp6 && sp2 == sp8 && sp4 == spA) {
        sp0 = 0x1000;
        sp2 = 0;
        sp4 = 0;
    }

    t0 = (s16)((((s64)sp8 * sp4 + 0x800) >> 12) - (((s64)spA * sp2 + 0x800) >> 12));
    *(s16 *)(obj + 0x5c) = t0;

    t1 = (s16)((((s64)spA * sp0 + 0x800) >> 12) - (((s64)sp6 * sp4 + 0x800) >> 12));
    *(s16 *)(obj + 0x5e) = t1;

    t2 = (s16)((((s64)sp6 * sp2 + 0x800) >> 12) - (((s64)sp8 * sp0 + 0x800) >> 12));
    *(s16 *)(obj + 0x60) = t2;

    t3 = *(s16 *)(obj + 0x60);
    t4 = *(s16 *)(obj + 0x5e);
    t5 = (s16)((((s64)sp8 * t3 + 0x800) >> 12) - (((s64)spA * t4 + 0x800) >> 12));
    *(s16 *)(obj + 0x62) = t5;

    t3 = *(s16 *)(obj + 0x5c);
    t2 = *(s16 *)(obj + 0x60);
    t5 = (s16)((((s64)spA * t3 + 0x800) >> 12) - (((s64)sp6 * t2 + 0x800) >> 12));
    *(s16 *)(obj + 0x64) = t5;

    t4 = *(s16 *)(obj + 0x5e);
    t3 = *(s16 *)(obj + 0x5c);
    t5 = (s16)((((s64)sp6 * t4 + 0x800) >> 12) - (((s64)sp8 * t3 + 0x800) >> 12));
    *(s16 *)(obj + 0x66) = t5;
}