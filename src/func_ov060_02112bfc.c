// NONMATCHING: different op / idiom (div=30). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void* _ZN5Actor10FindWithIDEj(unsigned int id);
void func_ov060_02112d48(char* c, int arg);
void func_ov060_02117a3c(char* self);

extern short data_ov060_02119294[];
extern short data_ov060_02119296[];
extern short data_ov060_02119298[];

void func_ov060_02112bfc(char* c) {
    char* found;
    int i;
    short* p;
    int r6;
    *(int*)(c + 0xa8) = *(int*)(c + 0xa0);
    found = (char*)_ZN5Actor10FindWithIDEj(*(unsigned int*)(c + 0x3ac));
    if (found == 0) {
        *(int*)(c + 0x40c) = 0;
        return;
    }
    p = data_ov060_02119294;
    i = 0;
    r6 = 1;
    while (p[2] != 0) {
        int r1 = *(unsigned short*)(c + 0x3fc);
        if (r1 < p[2]) {
            int off = i * 6;
            short a = *(short*)((char*)data_ov060_02119294 + off);
            short b = *(short*)((char*)data_ov060_02119296 + off);
            if (a > 0) {
                r6 = (short)(b * (*(short*)((char*)data_ov060_02119298 + off) - 1 - r1));
            } else {
                i -= 1;
                off = i * 6;
                r6 = (short)(b * (r1 - *(short*)((char*)data_ov060_02119298 + off)));
            }
            func_ov060_02112d48(c, r6);
            if (r6 != 0 && (*(unsigned short*)(c + 0x3fc) & 1)) {
                func_ov060_02117a3c(found);
            }
            r6 = 0;
            break;
        }
        p += 3;
        i += 1;
    }
    if (r6 != 0) {
        *(int*)(c + 0x40c) = 0;
        *(short*)(found + 0x31e) = 0;
        *(short*)(found + 0x320) = 0;
        *(short*)(found + 0x322) = 0;
        *(short*)(found + 0x8c) = 0;
        *(short*)(found + 0x8e) = 0;
        *(short*)(found + 0x90) = 0;
        *(int*)(c + 0xa8) = 0;
    }
}
