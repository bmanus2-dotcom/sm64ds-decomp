//cpp
// NONMATCHING: base materialization / addressing (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
struct Player { int GetTalkState(); };

extern "C" short Vec3_HorzAngle(const Vector3 *a, const Vector3 *b);
void ApproachLinear(short &v, short t, short step);
extern "C" void _ZN7Message7EndTalkEv();
extern "C" void func_02011d44();
extern "C" void _ZN5Sound22LoadAndSetMusic_Layer3Ej(unsigned int x);
extern "C" void func_ov078_02125c48(char *c, void *p);
extern void *data_ov078_0212701c;

extern "C" int func_ov078_02125950(char *c)
{
    char *r5 = *(char **)(c + 0x430);
    Vector3 v;
    int *src = (int *)(r5 + 0x5c);
    v.x = src[0];
    v.y = src[1];
    v.z = src[2];
    short ang = Vec3_HorzAngle((Vector3 *)(c + 0x5c), &v);
    ApproachLinear(*(short *)(c + 0x8e), ang, 0x800);
    *(short *)(c + 0x94) = *(short *)(c + 0x8e);
    if (((Player *)r5)->GetTalkState() == -1) {
        _ZN7Message7EndTalkEv();
        func_02011d44();
        _ZN5Sound22LoadAndSetMusic_Layer3Ej(0x2d);
        func_ov078_02125c48(c, &data_ov078_0212701c);
    }
    return 1;
}
