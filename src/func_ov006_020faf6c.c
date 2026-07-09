extern long long _ZN4cstd4sqrtEy(unsigned long long a);
extern void func_ov006_020fb8fc(char *c, int a2, int a3, int a4, int a5, int a6);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int a);

void func_ov006_020faf6c(char *c, int slot)
{
    char *base;
    int sb;
    int dist;
    int dx;
    int dz;

    if (*(unsigned char *)(c + slot * 0x1c + 0x5bc8) == 0) {
        return;
    }

    base = c;
    sb = 0;
    do {
        if (*(unsigned char *)(base + 0x4f0c) != 0) {
            if (*(unsigned char *)(base + 0x4f0d) >= 2) {
                dx = *(int *)(base + slot * 0x1c + 0x5bb0) - *(int *)(base + 0x4edc);
                dz = *(int *)(base + slot * 0x1c + 0x5bb4) - *(int *)(base + 0x4ed8);
                dist = (int)_ZN4cstd4sqrtEy((unsigned long long)
                    ((long long)(dx >> 12) * (dx >> 12) + (long long)(dz >> 12) * (dz >> 12)));
                if (dist <= 0x18) {
                    *(short *)(c + 0x5c2a) = 0x20;
                    *(unsigned char *)(base + 0x4f0c) = 0;
                    *(unsigned char *)(base + 0x4f0e) = 0;
                    func_ov006_020fb8fc(c, *(int *)(c + slot * 0x1c + 0x5bb0),
                                        *(int *)(c + slot * 0x1c + 0x5bb4), 2, 0, 0);
                    {
                        int i = 0;
                        char *p = c;
                        do {
                            if (*(unsigned char *)(p + 0x468c) != 0) {
                                if (*(unsigned char *)(p + 0x468f) != 0) {
                                    if (*(unsigned char *)(p + 0x468f) < 5) {
                                        *(unsigned char *)(p + 0x468f) = 6;
                                        *(short *)(p + 0x4688) = 0x10;
                                    }
                                }
                            }
                            i++;
                            p += 0x38;
                        } while (i < 0x1e);
                    }
                    *(unsigned char *)(c + slot * 0x1c + 0x5bc7) = 0;
                    *(unsigned char *)(c + slot * 0x1c + 0x5bc6) = 0;
                    *(unsigned char *)(c + 0x5c34) = 0;
                    _ZN5Sound12PlayBank2_2DEj(0x18a);
                    return;
                }
            }
        }
        sb++;
        base += 0x38;
    } while (sb < 0x30);
}