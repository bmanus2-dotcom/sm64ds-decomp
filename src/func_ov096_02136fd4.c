// NONMATCHING: base materialization / addressing (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef struct Actor Actor;
typedef int Fix12i;
extern void func_ov096_02136e54(Actor* t, int x);
extern Actor* _ZN5Actor13ClosestPlayerEv(void);
extern Fix12i Vec3_HorzDist(const void* a, const void* b);

void func_ov096_02136fd4(Actor* thiz)
{
    char* c = (char*)thiz;
    int v = (int)(0x3c - *(unsigned short*)(c + 0x350)) << 0xc;
    if (v < 0) goto rest;
    func_ov096_02136e54(thiz, v / 0x3c);
    return;
rest:;
    {
        int* q = (int*)(c + 0xec);
        *q |= 1;
    }
    *(int*)(c + 0x33c) = 0;
    {
        Actor* p = _ZN5Actor13ClosestPlayerEv();
        if (p) {
            if (Vec3_HorzDist(c + 0x340, (char*)p + 0x5c) > 0x9c4000)
                *(int*)(c + 0x35c) = 0;
            if (*(unsigned short*)(c + 0x350) > 0x168)
                *(int*)(c + 0x35c) = 0;
            return;
        }
    }
    *(int*)(c + 0x35c) = 0;
}
