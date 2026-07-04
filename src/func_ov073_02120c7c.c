//cpp
// NONMATCHING: register allocation (div=30). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12i;
struct PMF;
extern "C" void _ZN8Particle20RunningSlidingDustAtE5Fix12IiES1_S1_(int a, int b, int c);
extern "C" void func_ov073_0212157c(void* c, PMF* p);
extern "C" void _Z14ApproachLinearRiii(int& v, int a, int b);
extern "C" int _ZN9Animation8FinishedEv(void* anim);
extern PMF data_ov073_021233c0;
extern PMF data_ov073_021233d0;
extern PMF data_ov073_02123360;

struct C {
    char pad0[0x8e];
    short field_8e;
    char pad90[0x94-0x90];
    short field_94;
    char pad96[0x98-0x96];
    int field_98;
    char pad9c[0x35c-0x9c];
    char anim_35c;
    char pad35d[0x4c9-0x35d];
    unsigned char field_4c9;
    char pad4ca[0x4cb-0x4ca];
    unsigned char field_4cb;
    char pad4cc[0x4d4-0x4cc];
    int field_4d4, field_4d8, field_4dc;
};

extern "C" int func_ov073_02120c7c(C* c)
{
    int a = c->field_98; if (a < 0) a = -a;
    if (a > 0xa) {
        C* r5 = c;
        for (int i = 0; i < 2; i++) {
            _ZN8Particle20RunningSlidingDustAtE5Fix12IiES1_S1_(r5->field_4d4, r5->field_4d8, r5->field_4dc);
            r5 = (C*)((char*)r5 + 0xc);
        }
    }
    if (c->field_4c9 == 1) {
        unsigned char* p = (unsigned char*)c + 0x4cb;
        (*p)--;
        if (*p != 0)
            func_ov073_0212157c(c, &data_ov073_021233c0);
        else
            func_ov073_0212157c(c, &data_ov073_021233d0);
        return 1;
    }
    _Z14ApproachLinearRiii(c->field_98, 0, 0x1000);
    if (_ZN9Animation8FinishedEv(&c->anim_35c)) {
        int b = c->field_98; if (b < 0) b = -b;
        if (b < 0xa) {
            c->field_98 = 0;
            c->field_94 = c->field_8e;
            func_ov073_0212157c(c, &data_ov073_02123360);
        }
    }
    return 1;
}
