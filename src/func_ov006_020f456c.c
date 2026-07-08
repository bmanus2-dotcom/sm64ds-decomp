extern void func_ov006_020f3f10(void* c);
extern void func_ov006_020f3964(void* c);
extern void func_02012790(int a);
extern void func_ov006_020f39fc(void* p);

extern unsigned char data_020a0e40;
extern unsigned char data_020a0de8[];
extern unsigned char data_020a0de9[];

void func_ov006_020f456c(char* self)
{
    int idx;
    int flag;
    int inner;
    int outer;
    char* entity;

    func_ov006_020f3f10(self);
    func_ov006_020f3964(self);
    if (*(unsigned short*)(self + 0x5322) != 0) {
        (*(unsigned short*)(((long long)(int)(self + 0x5322)) & 0xFFFFFFFFFFFFFFFFLL))--;
        return;
    }
    idx = data_020a0e40;
    flag = 0;
    if (data_020a0de8[idx * 4] != 0) {
        if (data_020a0de9[idx * 4] != 0) flag = 1;
    }
    if (flag == 0) return;
    func_02012790(0x62);
    if (*(int*)(self + 0xa8) == 0) {
        if (*(unsigned char*)(self + 0x533c) == 1) {
            for (outer = 0; outer < 2; outer++) {
                for (inner = 0; inner < 5; inner++) {
                    entity = self + (inner + outer * 5 + 2) * 0x18;
                    if (*(unsigned char*)(entity + 0x51bb) != 0) {
                        *(unsigned char*)(entity + 0x51bc) = 6;
                        break;
                    }
                }
            }
        } else {
            for (outer = 0; outer < 3; outer++) {
                for (inner = 0; inner < 4; inner++) {
                    entity = self + (inner + outer * 4) * 0x18;
                    if (*(unsigned char*)(entity + 0x51bb) != 0) {
                        *(unsigned char*)(entity + 0x51bc) = 6;
                        break;
                    }
                }
            }
        }
        *(unsigned char*)(self + 0x533d) = 0;
        func_ov006_020f39fc(self);
    }
    *(int*)(self + 0x5314) = 4;
}
