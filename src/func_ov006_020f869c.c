typedef short s16;

extern int func_ov006_020f7b10(void);
extern int func_ov006_020f7a90(void);
extern int func_ov006_020c1718(void* p);
extern void func_ov006_020c1164(void* t, int a1, void* a2);
extern int func_ov006_020f7b90(void);
extern int func_ov006_020c16b4(void* c);
extern void func_ov006_020c0d68(void* c);
extern void func_ov004_020b0a54(int a);
extern void func_ov004_020ad79c(int a, int b);
extern void func_ov004_020adb1c(int a);
extern void func_ov006_020c0c80(void* c);
extern void func_ov004_020b65e4(void);
extern void func_ov006_020c19d0(void* c);
extern void func_ov006_020f7740(void);

extern char *func_020beb68;
extern int data_ov006_0213d574;
extern int data_ov006_0213d564;
extern int data_ov006_0213d56c;
extern int data_ov006_0213d570;
extern int data_ov006_0213d568;
extern int data_ov006_021424fc;
extern int data_ov006_02142508;

int func_ov006_020f869c(void* arg)
{
    unsigned char* c = (unsigned char*)arg;

    switch (*(s16*)(c + 0x60a8)) {
    case 1:
        {
            s16* p = (s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF);
            (*p)++;
        }
        if (c[0xc4] == 0) {
            c[0xc3] = 1;
            c[0xc4] = 1;
            *(s16*)(c + 0xc0) = 0;
        }
        /* fall through */
    case 2:
        data_ov006_0213d574 = *(s16*)(c + 0x60ae) * 5 << 12;
        if (*(s16*)(c + 0x60ae) == 4) {
            if (func_ov006_020f7b10() == 0) {
                *(s16*)(c + 0x60ae) = 0;
                {
                    s16* p = (s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF);
                    (*p)++;
                }
            }
        }
        break;
    case 3:
        if (func_ov006_020f7a90() == 0) {
            int r5;
            if (data_ov006_0213d564 == 1)
                data_ov006_0213d564 = 0;
            r5 = data_ov006_0213d574 >> 12;
            if (data_ov006_0213d56c != 0 && r5 > 10 && r5 <= 18
                && func_ov006_020c1718(c + 0x4f38) != 0) {
                *(s16*)(c + 0x60ae) = 0;
                *(s16*)(c + 0x511e) = 0;
                func_ov006_020c1164(c + 0x4f38, 2, c + 0x60ae);
                if (data_ov006_0213d56c == 2)
                    *(s16*)(c + 0x4f52) = 0;
            } else {
                int lim = *(s16*)(c + 0x60ae) + 0x12;
                if (r5 >= lim) {
                    int flag = (data_ov006_021424fc != 0 && data_ov006_02142508 != 0);
                    if (flag == 0)
                        data_ov006_0213d574 = lim << 12;
                }
            }
        } else {
            if (data_ov006_0213d564 == 0) {
                if (func_ov006_020f7b90() != 0) {
                    data_ov006_0213d564 = 1;
                } else {
                    if (data_ov006_0213d570 != 0) {
                        if (*(s16*)(c + 0x4f52) == 1) {
                            *(s16*)(c + 0x4f52) = 0;
                        } else if (func_ov006_020c16b4(c + 0x4f38) != 0) {
                            {
                                char *g = func_020beb68;
                                if (g != 0) {
                                    if (*(int *)(g + 0xb4) > 0)
                                        *(int *)(((int)g + 0xb4) & 0xFFFFFFFFFFFFFFFF) -= 1;
                                }
                            }
                            func_ov006_020c0d68(c + 0x4f38);
                            func_ov004_020b0a54(5);
                            {
                                int d = data_ov006_0213d570;
                                char *g = func_020beb68;
                                int t = ((g != 0) ? *(int *)(g + 0xa8) : 0) - d;
                                int u = (g != 0) ? *(int *)(g + 0xb4) : 0;
                                func_ov004_020ad79c(t, u);
                            }
                            c[0xc3] = 0;
                            {
                                s16* p = (s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF);
                                (*p)++;
                            }
                        }
                    } else {
                        {
                            char *g = func_020beb68;
                            if (g != 0) {
                                if (*(int *)(g + 0xb4) < 0x270f)
                                    *(int *)(((int)g + 0xb4) & 0xFFFFFFFFFFFFFFFF) += 1;
                                if (*(int *)(g + 0xb4) > *(int *)(g + 0xb8))
                                    *(int *)(g + 0xb8) = *(int *)(g + 0xb4);
                            }
                        }
                        func_ov004_020adb1c(*(int *)(c + 0xb4));
                        func_ov006_020c0c80(c + 0x4f38);
                        func_ov004_020b0a54(4);
                        {
                            char *g = func_020beb68;
                            int t = (g != 0) ? *(int *)(g + 0xa8) : 0;
                            func_ov004_020ad79c(data_ov006_0213d568 + t,
                                                (g != 0) ? *(int *)(g + 0xb4) : 0);
                        }
                        c[0xc3] = 0;
                        {
                            s16* p = (s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF);
                            (*p)++;
                        }
                    }
                    data_ov006_0213d564 = 0;
                }
            }
        }
        break;
    }

    func_ov004_020b65e4();
    func_ov006_020c19d0(c + 0x4f38);
    func_ov006_020f7740();
    return 1;
}
