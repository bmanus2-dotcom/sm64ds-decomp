extern unsigned short *_ZN3G2S12GetBG1ScrPtrEv(void);
extern unsigned short data_ov003_020b174c[];

void func_ov003_020b0730(void *self, int arg)
{
    unsigned char *s = (unsigned char *)self;
    int i;
    unsigned int mask = 0x3ff;
    unsigned int v1000 = 0x1000;
    unsigned int v2000 = 0x2000;
    int z = 0;

    for (i = 0; i < 2; i++) {
        unsigned short *p = _ZN3G2S12GetBG1ScrPtrEv();
        unsigned short d = data_ov003_020b174c[i];
        unsigned int v;
        int j;
        unsigned short *row;

        row = p + d;
        switch (arg) {
        default:
            v = v1000;
            break;
        case 0: {
            unsigned int t;
            if ((s[0x91] == i) && (s[0x93] == 0))
                t = v2000;
            else
                t = v1000;
            v = (unsigned short)t;
            break;
        }
        }
        for (j = z; j < 0x20; j++) {
            unsigned int a;
            a = row[0] & mask;
            a = a | v;
            row[0] = a;
            a = row[0x20] & mask;
            a = a | v;
            row[0x20] = a;
            a = row[0x40] & mask;
            a = a | v;
            row[0x40] = a;
            a = row[0x60] & mask;
            a = a | v;
            row[0x60] = a;
            row += 1;
        }
    }
}
