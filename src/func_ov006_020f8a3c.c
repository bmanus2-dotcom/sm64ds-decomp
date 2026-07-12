typedef short s16;
typedef unsigned char u8;

extern void func_ov004_020b0aa0(int arg);
extern int func_ov006_020c1718(void* p);
extern void func_ov004_020b5e40(int x);
extern void func_ov004_020b56c8(char* p);
extern int _Z15ApproachLinear2Rsss(s16* r, s16 t, s16 s);
extern void func_ov006_020f7994(void);

extern int data_ov006_0213d570;
extern char* data_ov006_0213d568;
extern void* data_ov006_02142500;
extern char* data_ov006_02142504;
extern unsigned short data_ov004_020bf9e4;
extern void* func_020beb68;

int func_ov006_020f8a3c(char* c)
{
    switch (*(s16*)(c + 0x60a8)) {
    case 4:
        func_ov004_020b0aa0(0x1d);
        *(s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF) += 1;
        break;
    case 5:
        if (func_ov006_020c1718(c + 0x4f38) != 0) {
            int v = data_ov006_0213d570;
            if (v != 0) {
                func_ov004_020b5e40(v);
                *(s16*)(c + 0x60aa) = -1;
            } else {
                func_ov004_020b56c8(data_ov006_0213d568);
            }
            *(s16*)(c + 0x60ae) = 0;
            *(s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF) += 1;
        }
        break;
    case 6: {
        void* q = data_ov006_02142500;
        if (q != 0 && *(u8*)((char*)q + 0x2e) != 0) {
            if (_Z15ApproachLinear2Rsss((s16*)(c + 0x60aa), 0, 1) != 0) {
                char* r3;
                int i;
                int n;
                *(s16*)(c + 0x60aa) = 0x10;
                n = *(s16*)(c + 0x60ae);
                r3 = data_ov006_02142504;
                for (i = 0; i < n; i++) {
                    if (r3 == 0) break;
                    r3 = *(char**)(r3 + 4);
                }
                if (r3 != 0) *(u8*)(r3 + 0x2e) = 0;
                *(s16*)(((int)c + 0x60ae) & 0xFFFFFFFFFFFFFFFF) += 1;
            }
        } else {
            if (data_ov004_020bf9e4 <= 1)
                *(s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF) += 1;
        }
        break;
    }
    case 7: {
        void* p = func_020beb68;
        if ((p != 0 ? *(int*)((char*)p + 0xa8) : 0) != 0)
            return 1;
        func_ov006_020f7994();
        *(s16*)(c + 0x60aa) = 0x1e;
        *(s16*)(((int)c + 0x60a8) & 0xFFFFFFFFFFFFFFFF) += 1;
        break;
    }
    case 8:
        if (_Z15ApproachLinear2Rsss((s16*)(c + 0x60aa), 0, 1) != 0)
            return 1;
        break;
    }
    return 0;
}
