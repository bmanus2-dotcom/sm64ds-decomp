//cpp
// NONMATCHING: different op / idiom (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct BCA_File;
typedef int Fix12;
extern "C" void func_ov006_020c8658(void *c);
namespace Sound { void PlayBank2_2D(unsigned int); }
struct ModelAnim { void SetAnim(BCA_File*, int, Fix12, unsigned int); };

extern int data_ov006_0213b088[2];
extern void *data_ov006_0214042c;
extern int data_ov006_0213b090[2];

extern "C" void func_ov006_020c8084(char *c)
{
    int *p = (int*)(c + 0x3c);
    if (p[0] == data_ov006_0213b088[0] &&
        (p[1] == data_ov006_0213b088[1] || *(int*)(c + 0x3c) == 0)) {
        *(int*)(c + 0x24) = 0;
        func_ov006_020c8658(c);
    } else {
        *(int*)(c + 0x20) = 0;
        *(int*)(c + 0x24) = 0x2000;
        Sound::PlayBank2_2D(0x1c9);
        ((ModelAnim*)(c + 0x4c))->SetAnim((BCA_File*)data_ov006_0214042c, 0, 0x800, 0);
        *(int*)(c + 0xa4) = 0;
        *(int*)(c + 0x3c) = data_ov006_0213b090[0];
        *(int*)(c + 0x40) = data_ov006_0213b090[1];
    }
}
