// NONMATCHING: size 0x168 vs ROM 0x1f8 (-0x90); BG-offset call interleave / flag branches.
extern void SetBg2Offset(int a, int b);
extern void SetBg3Offset(int a, int b);
extern void SetSubBg2Offset(int a, int b);
extern void SetSubBg3Offset(int a, int b);
extern int func_ov004_020ae140(void *self);

int func_ov006_02128fb8(char *c)
{
    int y;
    int m;

    if (*(int *)(c + 0x4628) != 0)
        goto done;

    if (*(unsigned char *)(c + 0xb9f8) == 0) {
        *(volatile unsigned short *)0x4000304 =
            (unsigned short)(*(volatile unsigned short *)0x4000304 | 0x8000u);
        y = *(int *)(c + 0xab6c) >> 12;
        SetBg2Offset(0, y);
        SetBg3Offset(0, y);
        SetSubBg2Offset(0x100, y + 0x110);
        SetSubBg3Offset(0, y + 0x110);
        m = 0x1ff0000;
        *(volatile unsigned int *)0x4000018 = (unsigned int)(m & (y << 16));
        *(volatile unsigned int *)0x400001c = (unsigned int)(m & (y << 16));
        *(volatile unsigned int *)0x4001018 =
            (unsigned int)((m & ((y + 0x110) << 16)) | 0x100u);
        *(volatile unsigned int *)0x400101c =
            (unsigned int)(m & ((y + 0x110) << 16));
    } else {
        *(volatile unsigned short *)0x4000304 =
            (unsigned short)(*(volatile unsigned short *)0x4000304 & ~0x8000u);
        y = *(int *)(c + 0xab6c) >> 12;
        SetBg2Offset(0x100, y + 0x110);
        SetBg3Offset(0, y + 0x110);
        SetSubBg2Offset(0, y);
        SetSubBg3Offset(0, y);
        m = 0x1ff0000;
        *(volatile unsigned int *)0x4000018 =
            (unsigned int)((m & ((y + 0x110) << 16)) | 0x100u);
        *(volatile unsigned int *)0x400001c =
            (unsigned int)(m & ((y + 0x110) << 16));
        *(volatile unsigned int *)0x4001018 = (unsigned int)(m & (y << 16));
        *(volatile unsigned int *)0x400101c = (unsigned int)(m & (y << 16));
    }

done:
    if (func_ov004_020ae140(c) != 0)
        return 1;
    return 0;
}