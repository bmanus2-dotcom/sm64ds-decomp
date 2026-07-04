// NONMATCHING: push-set / frame (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov004_020b0aa0(int arg);
void func_ov006_020c7490(void);
void func_ov006_020ee598(char* p);
void func_ov004_020b0cac(int c, int a1, int a2, int a3, int arg5, short arg6);
void func_ov006_020c42bc(void);

void func_ov006_020ee5b8(char* c){
    int v;
    short* d = (short*)(c+0x5014);
    char* base = c + 0x5000;
    *d = *d - 1;
    v = *(short*)(base + 0x14);
    if (v == 0) {
        func_ov004_020b0aa0(0x1d);
        if (*(unsigned char*)(c+0xc4) == 0) {
            *(unsigned char*)(c+0xc3) = 1;
            *(unsigned char*)(c+0xc4) = 1;
            *(short*)(c+0xc0) = 0;
        }
        func_ov006_020c7490();
        func_ov006_020ee598(c);
    } else if (v == 0x77) {
        func_ov004_020b0cac(0xd, 0x80, 0x60, 1, -1, 0xa);
        func_ov006_020c42bc();
    }
}
