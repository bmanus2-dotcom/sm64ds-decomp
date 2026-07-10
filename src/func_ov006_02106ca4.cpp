//cpp
struct Obj { int dummy; };
typedef void (Obj::*PMF)(int);

extern "C" {
    void func_ov006_021050bc(void *c);
    void func_ov006_02104870(char *c);
    void func_ov004_020b0a54(int x);
    void func_ov006_02104ea8(char *c);
    void func_ov004_020adb1c(int self);
    void func_ov006_021068d8(char *c);
    void func_ov006_02104580(void *c);
}

extern PMF data_ov006_02142840[];
extern unsigned char data_020a0e40;
extern unsigned char data_020a0de8[];
extern unsigned char data_020a0de9[];

struct B { unsigned char pad[0xb4]; int b4; int b8; };
extern struct B *func_020beb68;

extern "C" void func_ov006_02106ca4(char *c)
{
    int nonZero;
    int count;
    int i;
    unsigned char g;

    func_ov006_021050bc(c);

    count = *(int *)(c + 0x4cb8);
    nonZero = 0;
    for (i = 0; i < count; i++) {
        char *base = c + i;
        unsigned char *p = (unsigned char *)(((int)base + 0x4efa) & 0xFFFFFFFFFFFFFFFF);
        unsigned char idx = *p;
        (((Obj *)c)->*data_ov006_02142840[idx])(i);
        if (*p != 0) nonZero++;
        count = *(int *)(c + 0x4cb8);
    }

    if (nonZero != 0) return;

    if (*(unsigned short *)(c + 0x4ec0) != 0) {
        *(unsigned short *)(((int)c + 0x4ec0) & 0xFFFFFFFFFFFFFFFF) -= 1;

        if (*(unsigned char *)(c + 0x4fe6) == 0) {
            int flag = 0;
            g = data_020a0e40;
            if (data_020a0de8[g * 4] != 0) {
                if (data_020a0de9[g * 4] != 0) flag = 1;
            }
            if (flag != 0) *(unsigned short *)(c + 0x4ec0) = 0;
        }

        if (*(short *)(c + 0x4ec0) <= 0) {
            *(unsigned short *)(c + 0x4ec0) = 0;

            if (*(unsigned char *)(c + 0x4fe6) != 0) {
                struct B *p2;

                func_ov006_02104870(c);
                func_ov004_020b0a54(0);
                func_ov006_02104ea8(c);
                *(unsigned char *)(c + 0x4fe3) = 0;
                c[0xc3] = 0;

                p2 = func_020beb68;
                if (p2 != 0) {
                    if (p2->b4 < 0x270f) {
                        *(int *)(((int)p2 + 0xb4) & 0xFFFFFFFFFFFFFFFF) += 1;
                    }
                    if (p2->b4 > p2->b8) {
                        p2->b8 = p2->b4;
                    }
                }
                func_ov004_020adb1c(func_020beb68 ? func_020beb68->b4 : 0);
            } else {
                *(unsigned short *)(c + 0x4ec0) = 0x10;
                *(int *)(c + 0x4ca8) = 7;
                func_ov006_021068d8(c);
            }
        }
    } else {
        func_ov006_02104580(c);
        *(unsigned short *)(((int)c + 0x4ec6) & 0xFFFFFFFFFFFFFFFF) += 1;
    }
}
