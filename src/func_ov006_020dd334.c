extern int RandomIntInternal(int *seed);
extern int data_0209d4b8;
extern int data_ov006_0212e358[];

void func_ov006_020dd334(char *c)
{
    int sp[6];
    int i;
    int r2;
    int r3;
    int r1;
    char *p;

    for (i = 0; i < 3; i++) {
        sp[i] = (int)((((unsigned int)RandomIntInternal(&data_0209d4b8) >> 16) & 0x7fff) << 3) >> 15;
    }
    for (i = 0; i < 3; i++) {
        sp[i + 3] = (sp[i] + (int)((((unsigned int)RandomIntInternal(&data_0209d4b8) >> 16) & 0x7fff) * 6) >> 15) + 1;
        sp[i + 3] &= 7;
    }

    r2 = 0;
    r3 = 0;
    r1 = 0;
    p = c;
    do {
        *(int *)(p + 0x4ac0) = ((r3 << 5) + 0x10) << 12;
        *(int *)(p + 0x4ac4) = data_ov006_0212e358[r2] << 12;
        r3++;
        if (r3 >= 8) {
            r3 = 0;
            r2++;
        }
        *(unsigned char *)(p + 0x4ad1) = 1;
        *(unsigned char *)(p + 0x4ad2) = 1;
        r1++;
        p += 0x18;
    } while (r1 < 0x18);

    *(unsigned char *)(c + sp[0] * 0x18 + 0x4000 + 0xad4) = 1;
    *(unsigned char *)(c + sp[3] * 0x18 + 0x4000 + 0xad4) = 1;
    *(unsigned char *)(c + (sp[1] + 8) * 0x18 + 0x4000 + 0xad4) = 1;
    *(unsigned char *)(c + (sp[4] + 8) * 0x18 + 0x4000 + 0xad4) = 1;
    *(unsigned char *)(c + (sp[2] + 0x10) * 0x18 + 0x4000 + 0xad4) = 1;
    *(unsigned char *)(c + (sp[5] + 0x10) * 0x18 + 0x4000 + 0xad4) = 1;
}