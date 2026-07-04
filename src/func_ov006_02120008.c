// NONMATCHING: different op / idiom (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov004_020b0aa0(int arg);
void func_ov006_0211e318(char* c);
void func_ov006_0211f9fc(char* c);
void func_ov006_0211f6fc(char* c);
void func_ov006_0211e5cc(char* c);
void func_ov006_0211e3e0(char* c);
void func_ov006_0211d5a8(char* c);
void func_ov006_0211e658(char* c);

void func_ov006_02120008(char* c){
    unsigned short* g = (unsigned short*)(c+0x4c00);
    if (g[0xb] != 0) {
        unsigned short* d = (unsigned short*)(c+0x4c16);
        *d = *d - 1;
        if (g[0xb] == 0) {
            func_ov004_020b0aa0(0xd);
            if (*(unsigned char*)(c+0xc4) == 0) {
                *(unsigned char*)(c+0xc3) = 1;
                *(unsigned char*)(c+0xc4) = 1;
                *(short*)(c+0xc0) = 0;
            }
            func_ov006_0211e318(c);
            func_ov006_0211f9fc(c);
            func_ov006_0211f6fc(c);
            func_ov006_0211e5cc(c);
            func_ov006_0211e3e0(c);
            func_ov006_0211d5a8(c);
            func_ov006_0211e658(c);
        }
    }
}
