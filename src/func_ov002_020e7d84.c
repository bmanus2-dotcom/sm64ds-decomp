// NONMATCHING: different op / idiom (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_02012694(int a, void* p);
extern void _ZN12CylinderClsn5ClearEv(char* t);
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int id, int a, int b, int d);

void func_ov002_020e7d84(char* c)
{
    unsigned char* f = (unsigned char*)(c + 0x1db);
    func_02012694(0x53, c + 0x74);
    *f = (*f & ~1) | 1;
    *f &= ~2;
    _ZN12CylinderClsn5ClearEv(c + 0xd4);
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x12c, *(int*)(c + 0x5c), *(int*)(c + 0x60), *(int*)(c + 0x64));
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x12d, *(int*)(c + 0x5c), *(int*)(c + 0x60), *(int*)(c + 0x64));
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x12e, *(int*)(c + 0x5c), *(int*)(c + 0x60), *(int*)(c + 0x64));
}
