//cpp
// NONMATCHING: base materialization / addressing (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int (*dummy)();
class C;
typedef int (C::*PMF)();
class C { public: int d; };

extern "C" {
extern unsigned short DecIfAbove0_Short(unsigned short* p);
extern void _ZN5Actor9UpdatePosEP12CylinderClsn(void* thiz, void* cc);
extern void* _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(unsigned int a, unsigned int b, int fx, int t1, int t2, int s4, int s5, int s6);
extern void func_ov026_02111f30(char* c);
extern void _ZN9Animation7AdvanceEv(void* thiz);
}

extern "C" int func_ov026_0211200c(char* c)
{
    DecIfAbove0_Short((unsigned short*)(c + 0x100));
    {
        char* obj = *(char**)(c + 0x110);
        if (*(int*)(obj + 8) != 0) {
            PMF* pp = (PMF*)(obj + 8);
            ((C*)c->**pp)();
        }
    }
    _ZN5Actor9UpdatePosEP12CylinderClsn(c, 0);
    int vel0 = *(int*)(c + 0x5c);
    int vel1 = *(int*)(c + 0x60) + 0x384000;
    int vel2 = *(int*)(c + 0x64);
    *(void**)(c + 0x1b8) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
        *(unsigned int*)(c + 0x1b8), 0x139, vel0, vel1, vel2, 0, 0, 0);
    *(short*)(c + 0x8c) = *(short*)(c + 0x92);
    *(short*)(c + 0x8e) = *(short*)(c + 0x94);
    *(short*)(c + 0x90) = *(short*)(c + 0x96);
    func_ov026_02111f30(c);
    _ZN9Animation7AdvanceEv(c + 0x178);
    _ZN9Animation7AdvanceEv(c + 0x164);
    return 1;
}
