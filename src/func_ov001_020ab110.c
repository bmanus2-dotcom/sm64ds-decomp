// NONMATCHING: register allocation (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_0209f3e8[];
extern int data_ov001_020ad634[];
extern char data_ov001_020ad630[];
extern void func_ov001_020aa6b0(int* r0, int r1);
extern void func_ov001_020aa6cc(int r0);

void func_ov001_020ab110(char* r4) {
    if ((unsigned)(*(unsigned char*)(r4+0x1b) << 0x1d) >> 0x1f) return;
    int f14 = *(int*)(r4+0x14);
    if (f14 != -1) {
        if (data_0209f3e8[f14] == *(int*)(r4+4)) {
            func_ov001_020aa6b0((int*)r4, 0);
            data_0209f3e8[*(int*)(r4+0x14)] = 0;
        }
    }
    func_ov001_020aa6cc(*(unsigned char*)(r4+0x18));
    int prev = *(int*)(r4+0xc);
    if (prev != 0) {
        *(int*)(prev+0x10) = *(int*)(r4+0x10);
    } else {
        unsigned char idx = *(unsigned char*)(r4+0x18);
        if ((int)r4 == data_ov001_020ad634[idx]) {
            data_ov001_020ad634[idx] = *(int*)(r4+0x10);
        }
    }
    int next = *(int*)(r4+0x10);
    if (next != 0) {
        *(int*)(next+0xc) = *(int*)(r4+0xc);
    }
    func_ov001_020aa6b0((int*)r4, 0);
    *(int*)(r4+4) = 0;
    *(int*)(r4+8) = 0;
    *(int*)(r4+0xc) = 0;
    *(int*)(r4+0x10) = 0;
    *(int*)(r4+0x14) = -1;
    *(unsigned char*)(r4+0x1b) = 0;
    *(unsigned char*)(r4+0x1b) |= 4;
    *(unsigned char*)(r4+0x18) = 3;
    *(unsigned char*)(r4+0x19) = 0;
    unsigned char i = *(unsigned char*)(r4+0x18);
    unsigned char v = data_ov001_020ad630[i];
    if (v != 0) {
        data_ov001_020ad630[i] = v - 1;
    }
}
