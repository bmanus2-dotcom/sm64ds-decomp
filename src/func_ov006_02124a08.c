// NONMATCHING: register allocation (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern short data_ov004_020bf9e4;
extern int Math_Function_0203b14c(void *p, int a, int b, int c, int d);
extern void func_ov004_020b0a38(void);
void func_ov006_02124a08(void *self);
void func_ov006_02124a08(void *self) {
    char *c = (char *)self;
    char *r4;
    int i, sl;
    if (data_ov004_020bf9e4 != 1) return;
    if (*(int *)(c + 0xa8) <= 0) {
        r4 = c + 0x5100;
        sl = 0;
        i = sl;
        if (*(short *)(r4 + 0xc8) > 0) {
            char *e = c + 0x51a8;
            do {
                if (Math_Function_0203b14c(e, -0x40000, 0x800, 0xc000, 0x200) == 0)
                    sl++;
                i++;
                e += 8;
            } while (i < *(short *)(r4 + 0xc8));
        }
        if (sl < 2) return;
    }
    func_ov004_020b0a38();
    *(int *)(c + 0x51b8) = 0xc;
}
