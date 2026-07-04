//cpp
// NONMATCHING: different op / idiom (div=34). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef void (*PMFholder);
struct Platform {
    void UpdateModelPosAndRotY();
    int IsClsnInRange(int a, int b);
    void UpdateClsnPosAndRot();
};
struct PmfEntry;
extern "C" void func_020393d4(void *p, void *v);
extern "C" void ApproachLinearI(int *dst, int target, int rate);
extern "C" void UpdatePosWithVelocitySym();

typedef void (Platform::*PMF)();
struct PmfRow { PMF pmf; };
extern "C" PmfRow data_ov091_021354e0[];

extern "C" int func_ov091_02132108(Platform *self)
{
    char *s = (char*)self;
    int old = *(int*)(s + 0x320);
    (self->*data_ov091_021354e0[old].pmf)();
    unsigned short *cnt = (unsigned short*)(s + 0x354);
    *cnt = *cnt + 1;
    if (old != *(int*)(s + 0x320)) {
        *(short*)(s + 0x354) = 0;
        func_020393d4(s + 0x124, 0);
    } else {
        func_020393d4(s + 0x124, (void*)&UpdatePosWithVelocitySym);
    }
    if (*(unsigned char*)(s + 0x352) == 0) {
        int t = (*(unsigned char*)(s + 0x356) != 0) ? 0x1e000 : 0;
        int saved = *(int*)(s + 0x60);
        ApproachLinearI((int*)(s + 0x34c), t, 0x5000);
        *(int*)(s + 0x60) = *(int*)(s + 0x60) - *(int*)(s + 0x34c);
        *(int*)(s + 0x60) = saved;
        self->UpdateModelPosAndRotY();
        if (self->IsClsnInRange(0, 0) != 0) {
            self->UpdateClsnPosAndRot();
            *(unsigned char*)(s + 0x356) = 0;
        }
    }
    return 1;
}
