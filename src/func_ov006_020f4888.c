// NONMATCHING: different op / idiom (div=27). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov004_020b67f8(void);
extern void func_ov004_020b0a54(int c);
extern void func_ov004_020adb1c(int self);
extern void func_ov006_020c0c80(void *c);
extern void func_ov006_020c0d68(char *c);
extern char *func_020beb68;

void func_ov006_020f4888(char *self)
{
    char *p = self + 0x5300;
    if (*(unsigned short *)(p + 0x24) != 0) {
        unsigned short *ctr = (unsigned short *)(self + 0x5324);
        *ctr = *ctr - 1;
        if (*(short *)(p + 0x24) <= 0) {
            *(unsigned short *)(p + 0x24) = 0;
            if (*(unsigned char *)(self + 0x5337) >= *(unsigned short *)(p + 0x2a)) {
                int *cnt;
                if (*(unsigned char *)(self + 0x533a) == 0)
                    func_ov004_020b67f8();
                func_ov004_020b0a54(4);
                cnt = (int *)(self + 0xb4);
                if (*cnt < 0x270f)
                    *cnt = *cnt + 1;
                if (*(int *)(self + 0xb4) > *(int *)(self + 0xb8))
                    *(int *)(self + 0xb8) = *(int *)(self + 0xb4);
                func_ov004_020adb1c(func_020beb68 ? *(int *)(func_020beb68 + 0xb4) : 0);
                func_ov006_020c0c80(self + 0x4f38);
            } else {
                int *cnt;
                func_ov004_020b0a54(5);
                cnt = (int *)(self + 0xb4);
                if (*cnt > 0)
                    *cnt = *cnt - 1;
                func_ov006_020c0d68(self + 0x4f38);
            }
        }
    } else {
        *(unsigned char *)(self + 0xc3) = 0;
        *(unsigned short *)(p + 0x22) = 0x10;
    }
}
