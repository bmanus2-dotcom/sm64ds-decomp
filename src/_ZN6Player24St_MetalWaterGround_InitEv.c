//cpp
// NONMATCHING: base materialization / addressing (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(unsigned, unsigned, void*);
int _ZN6Player24St_MetalWaterGround_InitEv(char* c) {
    int* p = *(int**)(c+0x358);
    int b0 = (p != 0);
    if (b0) {
        int h = *(unsigned short*)((char*)p+0xc);
        int b1 = (h == 0x10c);
        if (!b1) {
            int b2 = (h == 0x10b);
            if (!b2) goto tail;
        }
        p = (int*)((char*)p+0xb0);
        *p &= ~0x4000;
        { int* q = (int*)((char*)*(int**)(c+0x358)+0xb0);
          *q &= ~0x100; }
        *(int**)(c+0x358) = 0;
    }
tail:
    _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(unsigned char*)(c+0x6d9), 0x2e, c+0x74);
    *(int*)(c+0x9c) = -0x1800;
    *(int*)(c+0xa0) = -0x14000;
    if (*(int*)(c+0x98) >= 0x14000) *(int*)(c+0x98) = 0x14000;
    *(unsigned char*)(c+0x706) = 1;
    return 1;
}
}
