// NONMATCHING: different op / idiom (div=44). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj(void*,void*,void*,int,int,int,int);

void func_ov098_02138ce0(char *c)
{
    int v[3];

    *(int *)(c + 0x5f0) = 0;
    *(int *)(c + 0x5f4) = 0;
    *(int *)(c + 0x5fc) = 0;
    *(int *)(c + 0x600) = 0;
    *(unsigned char *)(c + 0x606) = 0;
    *(int *)(c + 0x5c) = *(int *)(c + 0x4e8);
    *(int *)(c + 0x60) = *(int *)(c + 0x4ec);
    *(int *)(c + 0x64) = *(int *)(c + 0x4f0);
    *(short *)(c + 0x8c) = *(short *)(c + 0x500);
    *(short *)(c + 0x8e) = *(short *)(c + 0x502);
    *(short *)(c + 0x90) = *(short *)(c + 0x504);
    *(int *)(c + 0x98) = 0;
    *(int *)(c + 0xa4) = 0;
    *(int *)(c + 0xa8) = 0;
    *(int *)(c + 0xac) = 0;
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj(c + 0x564, c, v, 0x3c000, 0x6e000, 0x200002, 0x4d390);
    _ZN25MovingCylinderClsnWithPos4InitEP5ActorRK7Vector35Fix12IiES6_jj(c + 0x5a4, c, v, 0x3c000, 0x1e000, 0x800004, 0);
}
