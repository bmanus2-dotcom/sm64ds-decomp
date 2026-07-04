// NONMATCHING: register allocation (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_02060d98(unsigned int a, unsigned int b);
extern int func_02060ebc(void *self);

struct G {
    char pad[0x18];
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
};
extern struct G data_020a8180;

int func_02060a64(char *self) {
    unsigned int *r8;
    for (;;) {
        unsigned int r1;
        unsigned int g18 = data_020a8180.f18;
        r1 = g18 & (unsigned int)-0x200;
        if (r1 == g18 && (data_020a8180.f1c & 3) == 0 && data_020a8180.f20 >= 0x200) {
            r8 = (unsigned int*)data_020a8180.f1c;
        } else {
            r8 = (unsigned int*)(self + 0x20);
            *(unsigned int*)(self + 8) = r1;
        }
        func_02060d98((r1 >> 8) | 0xb7000000, r1 << 0x18);
        {
            int i = 0;
            unsigned int status;
            *(volatile unsigned int*)0x40001a4 = *(unsigned int*)(self + 4);
            do {
                status = *(volatile unsigned int*)0x40001a4;
                if (status & 0x800000) {
                    if ((unsigned int)i < 0x200) {
                        r8[i] = *(volatile unsigned int*)0x4100010;
                        i++;
                    }
                }
            } while (status & 0x80000000);
        }
        if (r8 == (unsigned int*)data_020a8180.f1c) {
            data_020a8180.f18 += 0x200;
            data_020a8180.f1c += 0x200;
            data_020a8180.f20 -= 0x200;
            if (data_020a8180.f20 == 0) return 0;
        } else {
            if (func_02060ebc(self) == 0) return 0;
        }
    }
}
