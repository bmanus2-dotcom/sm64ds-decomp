//cpp
// NONMATCHING: register allocation (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int s16;
struct Vector3 { int x, y, z; };

struct C;
typedef void (C::*PMF)();

struct C {
    char pad0[0xb4];
    PMF pmf;        // 0xb4 (2 words)
    char pad1[0xc8 - 0xb4 - 8];
    Vector3 v0c8;   // 0xc8
    char pad2[0xea - 0xc8 - 12];
    short a0ea;     // 0xea
    char pad3[0xf0 - 0xea - 2];
    short a0f0;     // 0xf0
    char pad4[0xf4 - 0xf0 - 2];
    int a0f4;       // 0xf4
};

extern "C" void _ZN14BlendModelAnim7AdvanceEv(void*);
extern "C" s16 Vec3_HorzAngle(const Vector3*, const Vector3*);
extern "C" void _Z11UpdateAngleRssis(short*, short, int, short);

extern Vector3 data_ov006_0212b890;
extern int data_ov006_0213ac78[2];

extern "C" void func_ov006_020c07e8(C* c)
{
    (c->*(c->pmf))();

    _ZN14BlendModelAnim7AdvanceEv((char*)c + 0x18);

    if (c->a0f4 != 0) {
        Vector3 t;
        t.x = data_ov006_0212b890.x;
        t.y = data_ov006_0212b890.y;
        t.z = data_ov006_0212b890.z;
        int ang = Vec3_HorzAngle(&c->v0c8, &t);
        short d = (short)(ang - c->a0ea);
        if (d < -0x3000) d = -0x3000;
        else if (d > 0x3000) d = 0x3000;
        _Z11UpdateAngleRssis(&c->a0f0, d, 8, 0x200);

        if (((int*)&c->pmf)[0] == data_ov006_0213ac78[0]) {
            if (((int*)&c->pmf)[1] == data_ov006_0213ac78[1])
                return;
            if (((int*)&c->pmf)[0] == 0)
                return;
        }
        _Z11UpdateAngleRssis(&c->a0ea, (short)(ang - d), 8, 0x200);
    } else {
        _Z11UpdateAngleRssis(&c->a0f0, 0, 8, 0x200);
    }
}
