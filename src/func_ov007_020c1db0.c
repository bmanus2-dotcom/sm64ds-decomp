/* func_ov007_020c1db0 @ 0x020c1db0 (ov007, size 0x268)
 * Touch-pen state tracker: shifts the 8-byte sample history, reads the new
 * sample (from the TP unit or the supplied buffer), debounces a release
 * request, patches x/y from the previous sample on the invalid-axis flags,
 * then updates hold/idle counters, drag origin and per-frame deltas.
 */
typedef unsigned short u16;
typedef short s16;

typedef struct TPPos {
    u16 x, y;
} TPPos;

extern void func_0205f040(void);
extern void func_0205efc0(u16 *);

void func_ov007_020c1db0(char *c, u16 *in)
{
    u16 tmp[4];

    *(TPPos *)(c + 0x10) = *(TPPos *)(c + 8);
    *(TPPos *)(c + 0x14) = *(TPPos *)(c + 0xc);
    *(TPPos *)(c + 8) = *(TPPos *)c;
    *(TPPos *)(c + 0xc) = *(TPPos *)(c + 4);

    if (in == 0) {
        func_0205f040();
        func_0205efc0(tmp);
        *(u16 *)c = tmp[0];
        *(u16 *)(c + 2) = tmp[1];
        *(u16 *)(c + 4) = tmp[2];
        *(u16 *)(c + 6) = tmp[3];
    } else {
        *(TPPos *)c = *(TPPos *)in;
        *(TPPos *)(c + 4) = *(TPPos *)(in + 2);
    }

    *(TPPos *)(c + 8) = *(TPPos *)c;
    *(TPPos *)(c + 0xc) = *(TPPos *)(c + 4);

    if (((int *)c)[0xb] & 1) {
        if (*(u16 *)(c + 0xc) == 0)
            *(volatile int *)(c + 0x2c) &= ~1;
        else
            *(u16 *)(c + 0xc) = 0;
    }

    if (*(u16 *)(c + 0xc) != 0) {
        if (*(u16 *)(c + 0xe) & 1) {
            if (*(u16 *)(c + 0x14) != 0)
                *(u16 *)(c + 8) = *(u16 *)(c + 0x10);
            else
                *(u16 *)(c + 0xc) = 0;
        }
        if (*(u16 *)(c + 0xe) & 2) {
            if (*(u16 *)(c + 0x14) != 0)
                *(u16 *)(c + 0xa) = *(u16 *)(c + 0x12);
            else
                *(u16 *)(c + 0xc) = 0;
        }
    }

    if (*(u16 *)(c + 0xc) != 0) {
        *(TPPos *)(c + 0x18) = *(TPPos *)(c + 8);
        *(TPPos *)(c + 0x1c) = *(TPPos *)(c + 0xc);
        if (*(u16 *)(c + 0x14) == 0) {
            *(u16 *)(c + 0x30) = *(u16 *)(c + 8);
            *(u16 *)(c + 0x32) = *(u16 *)(c + 0xa);
            *(int *)(c + 0x20) = 0;
            *(s16 *)(c + 0x38) = *(s16 *)(c + 0x3a) = 0;
            *(int *)(c + 0x40) = -1;
            *(s16 *)(c + 0x3c) = *(s16 *)(c + 0x3e) = 0;
        } else {
            (*(int *)(int)(((long long)(int)(c + 0x20)) & 0xFFFFFFFFFFFFFFFFLL))++;
            *(u16 *)(c + 0x38) = *(u16 *)(c + 8) - *(u16 *)(c + 0x30);
            *(u16 *)(c + 0x3a) = *(u16 *)(c + 0xa) - *(u16 *)(c + 0x32);
            *(u16 *)(c + 0x3c) = *(u16 *)(c + 8) - *(u16 *)(c + 0x10);
            *(u16 *)(c + 0x3e) = *(u16 *)(c + 0xa) - *(u16 *)(c + 0x12);
        }
    } else {
        if (*(u16 *)(c + 0x14) == 0) {
            (*(int *)(int)(((long long)(int)(c + 0x24)) & 0xFFFFFFFFFFFFFFFFLL))++;
        } else {
            *(int *)(c + 0x24) = 0;
            *(u16 *)(c + 0x34) = *(u16 *)(c + 8);
            *(u16 *)(c + 0x36) = *(u16 *)(c + 0xa);
        }
    }

    (*(int *)(int)(((long long)(int)(c + 0x28)) & 0xFFFFFFFFFFFFFFFFLL))--;
    if (*(int *)(c + 0x28) < 0)
        *(int *)(c + 0x28) = 0;
}






