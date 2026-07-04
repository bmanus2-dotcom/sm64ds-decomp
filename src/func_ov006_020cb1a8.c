//cpp
// NONMATCHING: different op / idiom (div=28). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12;
struct BCA_File;
struct ModelAnim { int pad; void SetAnim(BCA_File *f, int a, Fix12 b, unsigned int c); };
struct Sound { static void PlayBank2_2D(unsigned int); };

struct Pair { int a, b; };

extern "C" {
extern struct Pair data_ov006_0213b1a4;
extern struct Pair data_ov006_0213b1fc;
extern int data_ov006_02140540[];
extern int data_ov006_0213b20c[];
}

extern "C" void func_ov006_020cb1a8(char *c)
{
    Pair *q = (Pair *)(c + 0x64);

    if (q->a == data_ov006_0213b1a4.a) {
        if (q->b == data_ov006_0213b1a4.b) return;
        if (*(int *)(c + 0x64) == 0) return;
    }
    if (q->a == data_ov006_0213b1fc.a) {
        if (q->b == data_ov006_0213b1fc.b) return;
        if (*(int *)(c + 0x64) == 0) return;
    }

    *(int *)(c + 0x40) = 0x100;
    *(int *)(c + 0x34) = 0;
    *(int *)(c + 0x38) = 0x2000;
    Sound::PlayBank2_2D(0x1c9);
    ((ModelAnim *)(c + 0x6c))->SetAnim((BCA_File *)data_ov006_02140540[0], 0, 0x800, 0);
    *(int *)(c + 0xc4) = 0;
    *(int *)(c + 0x64) = data_ov006_0213b20c[0];
    *(int *)(c + 0x68) = data_ov006_0213b20c[1];
}
