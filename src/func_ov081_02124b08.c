//cpp
// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12;
struct BCA_File;
struct Actor { static Actor *FindWithID(unsigned int id); };
struct ModelAnim { void SetAnim(BCA_File *f, int a, Fix12 b, unsigned int c); };

extern void *data_ov081_02128da8[];

extern "C" int func_ov081_02124b08(char *c)
{
    unsigned int id = *(unsigned int *)(c + 0x3fc);
    if (id != 0) {
        char *a = (char *)Actor::FindWithID(id);
        if (a != 0) {
            *(int *)(a + 0x9c) = -0x2000;
            *(int *)(a + 0xa0) = -0x28000;
            *(int *)(c + 0x3fc) = 0;
            *(int *)(c + 0xa8) = 0xa000;
            *(int *)(c + 0x9c) = -0x4000;
            *(short *)(c + 0x414) = 0;
            ((ModelAnim *)(c + 0x30c))->SetAnim((BCA_File *)data_ov081_02128da8[1], 0, 0x1000, 0);
        }
    }
    return 1;
}
