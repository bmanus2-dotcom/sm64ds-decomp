// NONMATCHING: size 0x194 vs ROM 0x178 (+0x1c); star-slot distance ladder scheduling.
extern int _ZN4cstd4sqrtEy(unsigned long long a);
extern char data_ov006_0212e458[];

void func_ov006_020e1680(char *c)
{
    int slot;
    int i;
    int j;
    char *entry;
    int sp0;
    int sp4;
    int sp8;
    int spc;

    slot = 0;
    for (i = 0; i < 5; i++) {
        if (*(unsigned char *)(c + (i << 4) + 0x4748) == 0) {
            slot = i;
            break;
        }
    }

    entry = data_ov006_0212e458 + slot;
    sp8 = 0;
    spc = -0x28000;
    sp4 = 0x64;
    sp0 = 0x12c;

    for (j = 0; j < 5; j++) {
        char *base;
        int dx;
        int dy;
        int dist;
        char *star;

        base = c + j * 0x2c;
        if (*(unsigned char *)(base + 0x4689) == 0)
            goto next;

        dx = *(int *)(base + 0x4660) - *(int *)(c + 0x4e94);
        dy = *(int *)(base + 0x4664) - *(int *)(c + 0x4e98);
        dist = _ZN4cstd4sqrtEy((unsigned long long)(dy >> 12) * (dy >> 12)
                               + (unsigned long long)(dx >> 12) * (dx >> 12));

        star = c + (slot << 4) + 0x4000;
        *(unsigned char *)(star + 0x748) = 1;
        *(int *)(star + 0x73c) = *(int *)(base + 0x4660);
        *(int *)(star + 0x4740) = *(int *)(base + 0x4664) + 0x1000;
        *(unsigned short *)(star + 0x4746) = (unsigned short)*entry;

        if (dist <= 8)
            *(unsigned short *)(star + 0x4744) = 0x3e8;
        else if (dist <= 0x18)
            *(unsigned short *)(star + 0x4744) = 0x1f4;
        else if (dist <= 0x28)
            *(unsigned short *)(star + 0x4744) = (unsigned short)sp0;
        else if (dist <= 0x38)
            *(unsigned short *)(star + 0x4744) = (unsigned short)sp4;
        else
            *(unsigned short *)(star + 0x4744) = (unsigned short)sp8;

        if ((*(int *)(star + 0x4740) >> 12) >= -0x1f) {
            if ((*(int *)(star + 0x4740) >> 12) <= 8)
                *(int *)(star + 0x4740) = spc;
        }

        entry++;
        slot++;
    next:;
    }
}