//cpp
// NONMATCHING: base materialization / addressing (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern int _ZN9Animation7AdvanceEv(void*);
extern void func_ov006_020e7818(void*);
extern void* _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(unsigned int, unsigned int, int, int, int, const void*, void*);
extern int data_ov006_0213c704[2];

typedef void (*VoidFn)();

void func_ov006_020e7be8(char* c)
{
    int* d = data_ov006_0213c704;
    int* p = (int*)(c + 0x210);
    if (p[0] == d[0] && p[1] == d[1]) return;

    if (*(int*)(c + 0x210) == 0) return;

    {
        int idx = *(int*)(c + 0x214);
        char* obj = c + (idx >> 1);
        VoidFn fn;
        if (idx & 1) {
            char* vt = *(char**)obj;
            fn = *(VoidFn*)(vt + *(int*)(c + 0x210));
        } else {
            fn = *(VoidFn*)(c + 0x210);
        }
        fn();
    }

    _ZN9Animation7AdvanceEv(c + 0x5c);
    func_ov006_020e7818(c + 0x84);

    if (*(int*)(c + 0x208) == 0) return;

    *(void**)(c + 0x204) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
        *(unsigned int*)(c + 0x204), 0xec, 0x48c000, 0x140000, 0x200000, 0, 0);
}
}
