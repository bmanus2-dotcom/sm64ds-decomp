// NONMATCHING: loop/regalloc + call order (div~12, 0x1a4 vs 0x1b0); sibling func_ov006_020d8cc4
typedef unsigned char u8;

extern void func_ov006_020d836c(char *c);
extern void func_ov006_020d634c(char *c, int i);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int id);

void func_ov006_020d8d84(char *c)
{
    int i;
    int hit;
    int any;
    char *e;
    u8 mode;

    func_ov006_020d836c(c);
    if (*(short *)(c + 0x62e8) != 0) {
        *(short *)(c + 0x62e8) -= 1;
        if (*(short *)(c + 0x62e8) < 0) {
            *(short *)(c + 0x62e8) = 0;
        }
        return;
    }
    mode = *(u8 *)(c + 0x62f8);
    if (mode != 0) {
        any = 0;
        hit = 0;
        i = 0;
        do {
            e = c + (i << 6) + 0x4000;
            if (*(u8 *)(e + 0x698) != 0) {
                if (*(u8 *)(c + (i << 6) + 0x4697) != 6) {
                    *(u8 *)(c + (i << 6) + 0x4697) = 6;
                    *(u8 *)(e + 0x69b) = 0;
                    *(int *)(e + 0x670) = 0x4000;
                    hit++;
                    if (*(u8 *)(e + 0x696) != 0) {
                        any = 1;
                    }
                }
            }
            i++;
        } while (i < 0x70);
        if (hit != 0) {
            _ZN5Sound12PlayBank2_2DEj(0x1e6);
            if (*(u8 *)(c + 0x62f8) == 1) {
                func_ov006_020d634c(c, 0);
                func_ov006_020d634c(c, 1);
            } else {
                func_ov006_020d634c(c, any);
            }
        }
    } else {
        i = 0;
        do {
            e = c + (i << 6) + 0x4000;
            if (*(u8 *)(e + 0x698) != 0) {
                if (*(u8 *)(c + (i << 6) + 0x4697) == 5) {
                    if (*(u8 *)(c + 0x62f5) == *(u8 *)(e + 0x696)) {
                        *(u8 *)(c + (i << 6) + 0x4697) = 6;
                        *(u8 *)(e + 0x69b) = 0;
                        *(int *)(e + 0x670) = 0x4000;
                    }
                }
            }
            i++;
        } while (i < 0x70);
        _ZN5Sound12PlayBank2_2DEj(0x1e6);
        func_ov006_020d634c(c, *(u8 *)(c + 0x62f5));
    }
    *(int *)(c + 0x62d4) = 1;
}