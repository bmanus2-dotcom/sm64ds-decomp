// NONMATCHING: base materialization / addressing (div=19). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020ddf9c(char *c);
extern void func_ov004_020b0aa0(int n);
extern void func_ov006_020dd334(char *c);
extern void func_ov006_020dc7b4(char *c);
extern void func_ov006_020dc2f8(char *c);
extern int func_ov004_020adc1c(void);
void func_ov006_020de5b0(char *c);
void func_ov006_020de5b0(char *c){
    if (*(unsigned char*)(c + 0x51db) == 0) {
        *(unsigned char*)(c + 0x51da) = 0;
    } else {
        unsigned char *p = (unsigned char*)(c + 0x51da);
        *p = (unsigned char)(*p + 1);
    }
    *(int*)(c + 0xa8) = 0;
    *(int*)(c + 0xac) = *(int*)(c + 0xa8);
    func_ov006_020ddf9c(c);
    func_ov004_020b0aa0(0x1d);
    func_ov006_020dd334(c);
    func_ov006_020dc7b4(c);
    func_ov006_020dc2f8(c);
    *(int*)(c + 0x51d4) = func_ov004_020adc1c();
    *(int*)(c + 0x51c8) = 0;
}
