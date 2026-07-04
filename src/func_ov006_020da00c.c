// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_0203d6d0(int* o, int* a, int* b);
void func_0203d680(int* out, int* in, int scale);
int func_ov006_020da8e4(void* c);

void func_ov006_020da00c(char* c){
    int buf[4];
    *(int*)(c+4) = *(int*)(c+0xc);
    *(int*)(c+8) = *(int*)(c+0x10);
    {
        int (**vt)(void*) = *(int(***)(void*))c;
        *(int*)(c+8) = vt[2](c);
    }
    *(int*)(c+4) = 0x80000;
    func_0203d6d0(&buf[0], (int*)(c+0xc), (int*)(c+4));
    func_0203d680(&buf[2], &buf[0], 0x100);
    *(int*)(c+0x14) = buf[2];
    *(int*)(c+0x18) = buf[3];
    {
        int v = *(int*)(c+0x14);
        if (v < 0) { v = -v; *(int*)(c+0x14) = v; }
    }
    *(unsigned char*)(c+0x2b) = 0;
    *(int*)(c+0x24) = 0;
    *(unsigned char*)(c+0x2c) = 0;
    *(short*)(c+0x28) = 0;
    *(unsigned char*)(c+0x2d) = 0;
    *(unsigned char*)(c+0x2a) = (unsigned char)func_ov006_020da8e4(c);
}
