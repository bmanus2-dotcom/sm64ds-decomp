//cpp
// NONMATCHING: register allocation (div=26). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int ApproachLinear(int&, int, int);
extern int func_ov004_020b04c0(void);
extern void func_ov004_020b4b84(char* c, int* in);
extern int data_ov004_020bfa04;
extern int data_ov004_020bf9f8;
struct E { char pad[0x20]; short f; char pad2[2]; };
extern E data_ov004_020bfa34[];
extern void (*data_ov004_020bfa20)();
extern void func_ov004_020b53f0();
extern "C" void func_ov004_020b556c(void)
{
    int i, n, step, acc;
    E* e;
    if (ApproachLinear(data_ov004_020bfa04, 0, 1) == 0)
        return;
    step = 8;
    if (data_ov004_020bf9f8 > 0x14)
        n = 0x14;
    else
        n = data_ov004_020bf9f8;
    if (data_ov004_020bf9f8 > 0x14)
        step >>= 1;
    i = 0;
    if (n > 0) {
        e = &data_ov004_020bfa34[0];
        acc = i;
        do {
            int vec[2];
            int r = (i % 5) << 0x10;
            int q = -((i / 5) << 0x10);
            vec[1] = (-func_ov004_020b04c0() - 0x10) << 0xc;
            vec[0] = 0x60000;
            if (data_ov004_020bf9f8 < 5)
                vec[0] = (0x80 - (data_ov004_020bf9f8 - 1) * 8) << 0xc;
            vec[0] += r;
            vec[1] += q;
            func_ov004_020b4b84((char*)e, vec);
            e->f += acc;
            e += 1;
            acc += step;
            i++;
        } while (i < n);
    }
    data_ov004_020bfa04 = 0;
    data_ov004_020bfa20 = func_ov004_020b53f0;
}
