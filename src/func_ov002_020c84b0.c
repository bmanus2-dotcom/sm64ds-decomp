// NONMATCHING: register allocation (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef struct { int x, y, z; } Vector3;
extern short Vec3_VertAngle(const Vector3* v1, const Vector3* v0);
extern void _Z15ApproachLinear2Rsss(short* v, short t, short s);

void func_ov002_020c84b0(char* c)
{
    Vector3 v;
    short ang;
    v.x = *(int*)(c + 0x5c);
    v.y = *(int*)(c + 0x60);
    v.z = *(int*)(c + 0x64);
    v.y += 0x64000;
    ang = Vec3_VertAngle((Vector3*)(c + 0x744), &v);
    _Z15ApproachLinear2Rsss((short*)(c + 0x69c), -ang, 0x400);
    *(short*)(c + 0x762) = 0;
    *(short*)(c + 0x764) = 0;
    *(short*)(c + 0x762) = *(short*)(c + 0x69c);
    c[0x742] = 3;
}
