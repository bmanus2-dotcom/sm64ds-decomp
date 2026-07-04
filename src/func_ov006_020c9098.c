//cpp
// NONMATCHING: different op / idiom (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12;
struct BCA_File;
struct ModelAnim { int pad; void SetAnim(BCA_File *f, int a, Fix12 b, unsigned int c); };
struct Pair { int a, b; };
extern "C" {
extern Pair data_ov006_0213b214;
extern Pair data_ov006_0213b0fc;
extern int data_ov006_02140540[];
extern double data_ov006_0213b114;
extern void func_ov006_020ca3a8(char *c);
extern void func_ov006_020e6e3c(int a, int b);
}

extern "C" void func_ov006_020c9098(char *c)
{
    Pair *p = (Pair *)(c + 0x70);

    if (p->a == data_ov006_0213b214.a) {
        if (p->b == data_ov006_0213b214.b) return;
        if (*(int *)(c + 0x70) == 0) return;
    }

    if (p->a == data_ov006_0213b0fc.a) {
        if (p->b == data_ov006_0213b0fc.b || *(int *)(c + 0x70) == 0) {
            func_ov006_020ca3a8(c);
            return;
        }
    }

    *(int *)(c + 0x48) = 0x100;
    *(int *)(c + 0x3c) = 0;
    *(int *)(c + 0x40) = 0x2000;
    func_ov006_020e6e3c(0x1c9, *(int *)(c + 0x24));
    ((ModelAnim *)(c + 0x78))->SetAnim((BCA_File *)data_ov006_02140540[0], 0, 0x800, 0);
    *(int *)(c + 0xd0) = 0;
    *(double *)(c + 0x70) = data_ov006_0213b114;
}
