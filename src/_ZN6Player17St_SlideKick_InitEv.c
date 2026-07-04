//cpp
// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
extern "C" void _ZN5Sound9PlayBank0EjRK7Vector3(unsigned int, const Vector3&);
extern "C" int RandomIntInternal(int* seed);
extern "C" void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(unsigned int, unsigned int, const Vector3&);
extern "C" void _ZN6Player7SetAnimEji5Fix12IiEj(void*, unsigned int, int, int, unsigned int);
extern int data_ov002_0210e160;
extern int data_ov002_020ff130[];

extern "C" int _ZN6Player17St_SlideKick_InitEv(void* thisptr)
{
    unsigned char* p = (unsigned char*)thisptr;
    _ZN5Sound9PlayBank0EjRK7Vector3(0x11, *(Vector3*)(p + 0x74));
    unsigned int r = (unsigned int)RandomIntInternal(&data_ov002_0210e160);
    _ZN5Sound13PlayCharVoiceEjjRK7Vector3(p[0x6d9], data_ov002_020ff130[(r >> 4) & 1], *(Vector3*)(p + 0x74));
    _ZN6Player7SetAnimEji5Fix12IiEj(thisptr, 0x67, 0x40000000, 0x1000, 0);
    int* yv = (int*)(p + 0x98);
    *(int*)(p + 0xa8) = 0x14000;
    yv[0] += 0xf000;
    if (yv[0] > 0x28000) yv[0] = 0x28000;
    *(unsigned char*)(p + 0x6e5) = 0;
    *(unsigned char*)(p + 0x6e4) = 0;
    *(unsigned char*)(p + 0x6de) = 1;
    *(unsigned char*)(p + 0x6df) = 0;
    return 1;
}
