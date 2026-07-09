// NONMATCHING: size 0x174 vs ROM 0x168 (+0xc); HW-reg/timer tail scheduling.
extern unsigned char data_0209d460;
extern int data_ov006_0212e850[];

void func_ov006_020f0bf0(char *c, int i)
{
    int n;
    unsigned short *timer;
    volatile unsigned short *reg4a;
    char *slot;
    int v;
    char *pos;
    char *active;

    n = i * 0x18;
    timer = (unsigned short *)(c + 0x47b0 + n);
    if (*timer != 0) {
        *timer = (unsigned short)(*timer - 1);
        if ((short)*timer < 0)
            *timer = 0;
        return;
    }

    reg4a = (volatile unsigned short *)0x400004a;
    *reg4a = (unsigned short)((*reg4a & ~0x3f00u) | 0x1800u | 0x2000u);
    *reg4a = (unsigned short)((*reg4a & ~0x3fu) | 0x14u);
    *(volatile unsigned int *)0x04000000 =
        (*(volatile unsigned int *)0x04000000 & ~0xe000u) | 0x8000u;
    data_0209d460 = 4;

    slot = c + n + 0x4000;
    *(int *)(slot + 0x7a0) = data_ov006_0212e850[i] << 12;
    *(int *)(slot + 0x7a4) = 0x60000;
    *(unsigned char *)(slot + 0x7b5) = 1;

    active = c + 0x47b6 + n;
    *active = 1;

    if (i == 0) {
        *(short *)(c + 0x47a8 + n) = (short)0x8000;
        pos = c + 0x47a8 + n;
    } else {
        *(int *)(c + 0x47a8 + n) = -0x8000;
        pos = c + 0x47a8 + n;
    }

    v = *(int *)(c + 0xbc);
    while (v >= 5)
        v -= 5;
    if (v != 0) {
        *active = 2;
        if (i != 0)
            *(int *)pos = -0x7000;
        else
            *(int *)pos = 0x7000;
    }

    *(int *)(c + n + 0x4000 + 0x7ac) = 0;
}