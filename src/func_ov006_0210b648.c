typedef unsigned char u8;
typedef unsigned short u16;

extern void func_ov006_020c1eb4(char *a);
extern void func_ov006_020c201c(char *a);
extern void _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(int b, void *attr, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
extern void func_ov004_020af68c(void *a0, int a1, int a2, int a3, int a4);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int s);
extern void func_ov004_020b1bc8(char *a0, int a1, int a2, int a3);
extern void func_ov004_020b1e34(char *a0, int a1, int a2, int a3);
extern int func_ov004_020ad674(void);
extern void func_ov004_020af948(void *a, int b, int c2, void *m);
extern void func_ov004_020b2444(int a1, int a2, int num, int a4, int a5, int sel, int idx);
extern void func_ov004_020afb20(void *a0, int a1, int a2, int a3, int a4, int a5, u16 a6);

typedef struct T4fe4 {
    char pad[0x4fe4];
    int vals[3];
} T4fe4;

extern void *data_ov006_0213e9a4[];
extern int data_ov006_0213e5dc;
extern char *data_ov006_0213e5ec[];
extern void *data_ov006_0213ac30;
extern void *data_ov006_0213ac3c;

#pragma opt_strength_reduction off

int func_ov006_0210b648(char *c)
{
    int i, j;

    func_ov006_020c1eb4(c + 0x4660);
    func_ov006_020c201c(c + 0x4f38);

    if (*(int *)(c + 0x500c) > 0) {
        for (i = 0; i < 3; i++) {
            _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(0, data_ov006_0213e9a4[*(u8 *)(c + 0x503b) * 3 + i], 0x80, *(int *)(c + 0x500c) + 0x10, -1, 2, 0x1000, 0x1000, 0, 1);
        }
        for (i = 0; i < 3; i++) {
            _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(0, data_ov006_0213e9a4[*(u8 *)(c + 0x503c) * 3 + i], 0x80, *(int *)(c + 0x500c) + 0x60, -1, 2, 0x1000, 0x1000, 0, 1);
        }
    } else {
        for (i = 0; i < 3; i++) {
            _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(0, data_ov006_0213e9a4[*(u8 *)(c + 0x503b) * 3 + i], 0x80, 0x60, -1, 2, 0x1000, 0x1000, 0, 1);
        }
    }

    if (*(int *)(c + 0x5000) != 7) {
        if (*(int *)(c + 0x5000) == 6) {
            int i2, j2;
            char *p = c;
            for (i2 = 0; i2 < 3; i2++) {
                int y;
                for (j2 = 0, y = 0x30; j2 < 3; j2++) {
                    func_ov004_020af68c(data_ov006_0213e9a4[*(u8 *)(p + j2 + 0x5031) * 3 + i2],
                                        y - (*(int *)((int)c + i2 * 4 + 0x4ff4) >> 12), 0x60, -1, -1);
                    y += 0x50;
                }
                p += 3;
            }
        } else {
            char *p = c;
            int row, rem;
            int i2, j2;
            for (i2 = 0; i2 < 3; i2++) {
                int a = *(int *)(((int)c + i2 * 4 + 0x4fe4) & 0xFFFFFFFFFFFFFFFF) >> 12;
                int y;
                row = a / 0x50;
                rem = a % 0x50;
                for (j2 = 0, y = 0x30; j2 < 4; j2++) {
                    func_ov004_020af68c(data_ov006_0213e9a4[*(u8 *)(p + row + 0x501c) * 3 + i2],
                                        y - rem, 0x60, -1, -1);
                    row = (row + 1) % *(u8 *)(c + 0x503a);
                    y += 0x50;
                }
                p += 5;
            }
        }
    }

    if (*(u8 *)(c + 0x503d) < 3 && (*(u8 *)(c + 0x503f) & 0x20)) {
        int slot = 3;
        int ok = 1;
        int i3, j3;
        char *p = c;
        for (i3 = 0; i3 < 3; i3++) {
            if (*(u8 *)(c + i3 + 0x502e) != 0) {
                if (slot < 3) {
                    if (*(u8 *)(c + 0x503b) != *(u8 *)(p + slot + 0x5031))
                        ok = 0;
                } else {
                    u8 t = *(u8 *)(c + 0x503b);
                    for (j3 = 0; j3 < 3; j3++) {
                        if (t == *(u8 *)(p + j3 + 0x5031)) {
                            slot = j3;
                            break;
                        }
                        if (j3 == 2)
                            ok = 0;
                    }
                }
            }
            if (ok == 0)
                break;
            p += 3;
        }
        if (ok != 0 && slot < 3) {
            int count = 0;
            int i4;
            int y = 0x4c;
            for (i4 = 0; i4 < 3; i4++) {
                if (*(u8 *)(c + i4 + 0x502e) != 0) {
                    func_ov004_020af68c(&data_ov006_0213e5dc, slot * 0x50 + 0x30, y, -1, -1);
                    count++;
                }
                y += 0x18;
            }
            if ((*(u8 *)(c + 0x503f) & 0x3f) == 0x20) {
                _ZN5Sound12PlayBank2_2DEj(count > 1 ? 0x1ac : 0x1ab);
            }
        }
    }

    func_ov004_020b1bc8(c, 0xc, 0xc, 0);
    func_ov004_020b1e34(c, 0xe0, 0x14, 1);

    if (*(int *)(c + 0x5000) == 3 && *(int *)(c + 0x5010) >= 0) {
        func_ov004_020af948(*(void **)(data_ov006_0213e5ec[func_ov004_020ad674()] + 8), *(int *)(c + 0x5010) * 0x50 + 0x20, 0x28, 0);
        func_ov004_020af948(*(void **)(data_ov006_0213e5ec[func_ov004_020ad674()] + 0x34), *(int *)(c + 0x5010) * 0x50 + 0x30, 0x28, 0);
        if (*(int *)(c + 0x5010) == 1) {
            func_ov004_020b2444(*(int *)(c + 0x5010) * 0x50 + 0x40, 0x28, 6, 0, 0, 0, 0x14);
        } else {
            func_ov004_020b2444(*(int *)(c + 0x5010) * 0x50 + 0x40, 0x28, 3, 0, 0, 0, 0x14);
        }
    } else if (*(int *)(c + 0x5000) == 4 && *(int *)(c + 0x5010) < 0) {
        func_ov004_020af948(*(void **)(data_ov006_0213e5ec[func_ov004_020ad674()] + 8), 0x70, 0x28, 0);
        func_ov004_020af948(*(void **)(data_ov006_0213e5ec[func_ov004_020ad674()] + 0x38), 0x80, 0x28, 0);
        func_ov004_020b2444(0x90, 0x28, 3, 0, 0, 0, 0x28);
    }

    func_ov004_020afb20(data_ov006_0213ac30, 0x18, 0x30, -1, 0, 0x1000, *(u16 *)(c + 0x5018));
    func_ov004_020afb20(data_ov006_0213ac3c, 0x40, 0x10, -1, 0, 0x1000, *(u16 *)(c + 0x501a));

    return 1;
}
