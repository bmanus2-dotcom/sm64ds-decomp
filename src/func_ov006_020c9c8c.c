//cpp
// NONMATCHING: register allocation (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" int _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(char *anim, void *file, int a, int b, unsigned int u);
extern "C" void func_ov006_020e6e3c(int a, int b);
extern "C" void func_ov006_020c91ac(char *c);

extern int data_ov006_021405b0;
extern int data_ov006_02140574;
extern int data_ov006_0214059c;
struct G2 { int w[2]; };
extern G2 data_ov006_0213b194;

struct Vtbl { int (*slots[8])(); };
struct Obj { Vtbl *vt; };

extern "C" void func_ov006_020c9c8c(char *c) {
    *(int *)(c + 0x48) = data_ov006_021405b0;
    *(int *)(c + 0x40) = (int)(((long long)data_ov006_02140574 * 0xc00 + 0x800) >> 12);
    *(int *)(c + 0x4c) = *(int *)(c + 0x40);
    (*((Obj *)c)->vt->slots[4])();
    *(int *)(c + 0x64) = 0;
    *(int *)(c + 0x60) = 0;
    _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c + 0x78, (void *)data_ov006_0214059c, 0x40000000, 0x800, 0);
    *(int *)(c + 0xd0) = 0;
    func_ov006_020e6e3c(0x110, *(int *)(c + 0x24));
    func_ov006_020e6e3c(0x1b5, *(int *)(c + 0x24));
    *(int *)(c + 0x68) = 0;
    *(int *)(c + 0x70) = data_ov006_0213b194.w[0];
    *(int *)(c + 0x74) = data_ov006_0213b194.w[1];
    func_ov006_020c91ac(c);
}
