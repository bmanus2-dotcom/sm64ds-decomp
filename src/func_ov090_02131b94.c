//cpp
// NONMATCHING: different op / idiom (div=27). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12i;
struct BCA_File;
struct ModelAnim {
    int dummy;
};
extern "C" int RandomIntInternal(int* seed);
extern int data_0209e650;

struct Data134490 { int a; BCA_File* bca; };
extern Data134490 data_ov090_02134490;

extern "C" unsigned int _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(
    ModelAnim* thiz, BCA_File* f, int a, Fix12i b, unsigned int c);

extern "C" int func_ov090_02131b94(char* thiz)
{
    char* c = thiz;
    unsigned int r;
    int off = 0x39a;
    r = (unsigned)RandomIntInternal(&data_0209e650);
    *(short*)(c + off) = (short)(*(short*)(c + off) + ((int)(((r >> 8) & 3) << 0x1e) >> 16));
    r = (unsigned)RandomIntInternal(&data_0209e650);
    *(short*)(c + off) = (short)(*(short*)(c + off) + ((int)(((r >> 8) & 7) << 0x1d) >> 16));
    r = (unsigned)RandomIntInternal(&data_0209e650);
    *(short*)(c + 0x100) = (short)(((r >> 8) & 0x1f) + 0x96);
    *(int*)(c + 0x3a4) = 0x1000;
    _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(
        (ModelAnim*)(c + 0x30c), data_ov090_02134490.bca, 0, 0x1000, 0);
    return 1;
}
