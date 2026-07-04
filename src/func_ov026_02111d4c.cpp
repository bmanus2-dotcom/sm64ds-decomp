//cpp
// NONMATCHING: different op / idiom (div=40). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };

struct Player {
    void EnterWhirlpool();
};
struct Actor {
    Player* ClosestPlayer();
    int HorzAngleToCPlayer();
};

extern "C" int Vec3_HorzDist(const Vector3* a, const Vector3* b);
extern "C" int Vec3_Dist(const Vector3* a, const Vector3* b);
extern "C" void func_ov026_02111ee0(void* c, void* p);
extern "C" void Matrix4x3_FromRotationY(void* m, int angle);
extern "C" void Matrix4x3_ApplyInPlaceToRotationX(void* m, short angX);
extern "C" void MulVec3Mat4x3(const Vector3* in, const void* m, Vector3* out);

extern void* data_ov026_02113f3c;
extern char data_020a0e68;

extern "C" int func_ov026_02111d4c(char* c)
{
    Player* pl = ((Actor*)c)->ClosestPlayer();
    if (pl != 0) {
        int* q = (int*)((char*)pl + 0x5c);
        Vector3 v;
        v.x = q[0];
        v.y = q[1];
        v.z = q[2];

        if (Vec3_HorzDist((Vector3*)(c + 0x1a8), &v) <= 0x12c000) {
            int e = *(int*)(c + 0x1ac) - v.y;
            if (e < 0) e = -e;
            if (e <= 0x12c000) {
                pl->EnterWhirlpool();
                func_ov026_02111ee0(c, &data_ov026_02113f3c);
                return 1;
            }
        }

        if (*(unsigned char*)((char*)pl + 0x6f9) == 0) {
            int dd = Vec3_Dist((Vector3*)(c + 0x1a8), &v);
            if (dd < 0x44c000) {
                Vector3 m;
                m.x = 0;
                m.y = 0;
                m.z = (0x44c000 - dd) / 35;

                Vector3 out;
                out.x = 0;
                out.y = 0;
                out.z = 0;

                int ang = ((Actor*)c)->HorzAngleToCPlayer();
                Matrix4x3_FromRotationY(&data_020a0e68, (short)(ang + 0x8000));
                Matrix4x3_ApplyInPlaceToRotationX(&data_020a0e68, 0x2000);
                MulVec3Mat4x3(&m, &data_020a0e68, &out);

                int* r = (int*)((char*)pl + 0x5c);
                m.x = r[0];
                int nx = r[0] + out.x;
                m.y = r[1];
                int ny = r[1] + out.y;
                m.z = r[2];
                int nz = r[2] + out.z;
                m.y = ny;
                m.z = nz;
                m.x = nx;
                r[0] = nx;
                r[1] = ny;
                r[2] = nz;
            }
        }
    }
    return 1;
}
