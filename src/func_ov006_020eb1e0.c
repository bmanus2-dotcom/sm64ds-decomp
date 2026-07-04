//cpp
// NONMATCHING: different op / idiom (div=33). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
struct V { int x, y, z; };
extern void func_0203d388(int *p, int angle);
extern void func_0203d704(int *o, int *a, int *b);
}
extern int ApproachLinear(int &, int, int);
extern short ApproachLinear2(short &, short, short);
extern short ApproachLinear(short &, short, short);

struct data_ov006_0213c984_t { int a, b; };
extern struct data_ov006_0213c984_t data_ov006_0213c984;

struct Obj {
    char pad0[0x10];
    int f10;
    int f14;
    int f18, f1c;
    int f20;
    char pad24[0x48 - 0x24];
    int f48;
    char pad4c[0x76 - 0x4c];
    short f76;
    short f78;
    short f7a;
    char pad7c[0x93 - 0x7c];
    char f93;
    char f94;
    char f95;
};

extern "C" void func_ov006_020eb1e0(Obj *o)
{
    ApproachLinear(o->f48, 0, 0x200);
    if (ApproachLinear2(o->f78, 0, 1)) {
        int *p = &o->f10;
        if (p[0] != data_ov006_0213c984.a) return;
        if (p[1] != data_ov006_0213c984.b) {
            if (o->f10 != 0) return;
        }
        o->f94 = 1;
        o->f48 = 0x3000;
        o->f93 = 0;
        o->f95 = 0;
        return;
    }
    {
        int tmp[2];
        int out[2];
        tmp[1] = -0x10000;
        tmp[0] = 0;
        ApproachLinear(o->f7a, o->f76 - 0x1000, 0x400);
        func_0203d388(tmp, o->f7a);
        func_0203d704(out, &o->f20, tmp);
        o->f18 = out[0];
        o->f1c = out[1];
        if ((o->f78 & 0x10) && o->f78 >= 0x38) {
            o->f95 = 0;
            return;
        }
        o->f95 = 1;
    }
}
