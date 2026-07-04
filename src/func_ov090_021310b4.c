// NONMATCHING: different op / idiom (div=83). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(void* thiz, void* v);
extern void* _ZN5Actor10FindWithIDEj(unsigned int id);
extern void func_020aea30(char* c, void* p, int a, int b);
extern int _ZN5Actor16JumpedOnByPlayerER12CylinderClsnR6Player(char* c, void* cyl, void* p);
extern void _ZN6Player6BounceE5Fix12IiE(void* p, int f);
extern void func_020ada40(char* c, void* v, void* p, int a);
extern void func_02012694(int a, void* b);
extern int _ZN6Player9IsOnShellEv(void* p);
extern void _ZN5Actor10SpawnCoinsERK7Vector3j5Fix12IiEs(char* c, void* v, unsigned int a, int b, short d);
extern void _ZN5Actor8PoofDustEv(char* c);
extern void _ZN5Actor24KillAndTrackInDeathTableEv(char* c);
extern void _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(void* p, void* v, int a, int b, int d, int e, int f);

struct V3 { int x, y, z; };
extern struct V3 data_ov090_0213412c;

void func_ov090_021310b4(char* c)
{
    struct V3 sv;
    short hv[3];
    char* p;
    int flags;

    sv = data_ov090_0213412c;
    _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(c + 0x110, &sv);

    if (*(int*)(c + 0x134) == 0) return;
    p = (char*)_ZN5Actor10FindWithIDEj(*(unsigned int*)(c + 0x134));
    if (p == 0) return;
    flags = *(int*)(c + 0x130);

    if (flags & 0x2400) {
        *(int*)(c + 0x10c) = 2;
        func_020aea30(c, p, 0, 2);
        return;
    }
    if (flags & 0x40000) {
        *(int*)(c + 0x10c) = 4;
        func_020aea30(c, p, 0, 4);
        return;
    }
    if (flags & 0x40) {
        *(int*)(c + 0x10c) = 2;
        func_020aea30(c, p, 0, 2);
        return;
    }
    if (_ZN5Actor16JumpedOnByPlayerER12CylinderClsnR6Player(c, c + 0x110, p)) {
        _ZN6Player6BounceE5Fix12IiE(p, 0x28000);
        *(int*)(c + 0x10c) = 1;
        func_020aea30(c, p, 0, 1);
        return;
    }
    if (flags & 0x20) {
        *(int*)(c + 0x9c) = 0;
        *(int*)(c + 0xa4) = 0;
        *(int*)(c + 0xa8) = 0;
        *(int*)(c + 0xac) = 0;
        *(int*)(c + 0x10c) = 1;
        func_020aea30(c, p, 0, 1);
        return;
    }
    if (flags & 0x10) {
        hv[0] = 0x1000;
        hv[1] = 0;
        hv[2] = 0;
        func_020ada40(c, hv, p, 0);
        func_02012694(0x1d, c + 0x74);
        return;
    }
    if (flags & 0x4380) {
        *(unsigned char*)(c + 0x3a1) = 3;
        *(int*)(c + 0x10c) = 3;
        func_020aea30(c, p, 0, 3);
        return;
    }
    {
        int b = (*(unsigned short*)(p + 0xc) == 0xbf);
        if (b == 0) return;
    }
    if (*(unsigned char*)(p + 0x6f9) == 1 || _ZN6Player9IsOnShellEv(p) == 1) {
        struct V3 cv;
        cv.x = *(int*)(c + 0x5c);
        cv.y = *(int*)(c + 0x60);
        cv.z = *(int*)(c + 0x64);
        _ZN5Actor10SpawnCoinsERK7Vector3j5Fix12IiEs(c, &cv, *(unsigned char*)(c + 0x10a) + 1, 0xa000, 0);
        _ZN5Actor8PoofDustEv(c);
        _ZN5Actor24KillAndTrackInDeathTableEv(c);
        return;
    }
    {
        struct V3 hurt;
        hurt.x = *(int*)(c + 0x5c);
        hurt.y = *(int*)(c + 0x60);
        hurt.z = *(int*)(c + 0x64);
        _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(p, &hurt, 2, 0xc000, 1, 0, 1);
    }
}
