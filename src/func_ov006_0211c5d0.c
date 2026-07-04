// NONMATCHING: extra logic (you do more) (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov004_020adb1c(int arg);
extern void func_ov006_0211c478(int self);
extern void func_ov006_0211c080(int self);
extern void func_ov004_020b0cac(int c, int a1, int a2, int a3, int arg5, short arg6);
extern void _ZN5Sound22LoadAndSetMusic_Layer1Ei(int n);

extern int *g_020beb68;

void func_ov006_0211c5d0(int self, int r1)
{
    int *p;
    int v;

    *(int*)(self + 0x5608) = 0;

    if (r1 == 0) {
        (*(int*)(self + 0xbc))++;
        if ((unsigned int)*(int*)(self + 0xbc) > 0x270e)
            *(int*)(self + 0xbc) = 0x270e;
    } else {
        *(int*)(self + 0xbc) = 0;
        if ((unsigned int)*(int*)(self + 0xbc) > 0x270e)
            *(int*)(self + 0xbc) = 0x270e;
    }

    p = g_020beb68;
    if (p)
        *(int*)((int)p + 0xb4) = 0;

    p = g_020beb68;
    if (p)
        v = *(int*)((int)p + 0xb4);
    else
        v = 0;
    func_ov004_020adb1c(v);

    *(int*)(self + 0x50e0) = 1;
    func_ov006_0211c478(self);

    *(signed char*)(self + 0x5626) = 3;
    func_ov006_0211c080(self);

    *(short*)(self + 0x5618) = 0x20;
    func_ov004_020b0cac(0xd, 0x80, 0xa8, 1, -1, 0xd);

    _ZN5Sound22LoadAndSetMusic_Layer1Ei(6);
}
