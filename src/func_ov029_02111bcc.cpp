//cpp
// NONMATCHING: different op / idiom (div=45). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
struct Matrix4x3;

extern "C" {
void func_020393a4(int* p, int v);
unsigned int Sound_PlayLong(unsigned int a, unsigned int b, unsigned int c, const Vector3& v, unsigned int e);
}

struct Platform {
    char pad[4];
    void UpdateModelPosAndRotY();
    int IsClsnInRange(int a, int b);
    void UpdateClsnPosAndRot();
};

extern "C" {
void Platform_UpdateModelPosAndRotY(Platform* p);
int Platform_IsClsnInRange(Platform* p, int a, int b);
void Platform_UpdateClsnPosAndRot(Platform* p);
void MovingMeshCollider_Transform(void* self, const Matrix4x3& m, short s);
}

extern "C" int func_ov029_02111bcc(unsigned char* thiz)
{
    func_020393a4((int*)(thiz + 0x124), 0x250000);

    switch (thiz[0x32c]) {
    case 0:
        if (thiz[0x32a] != 0) {
            if (thiz[0x32b] == 0) {
                unsigned char* p = thiz + 0x32c;
                *p = *p + 1;
            }
        }
        thiz[0x32b] = thiz[0x32a];
        break;
    case 1:
        {
            int* p60 = (int*)(thiz + 0x60);
            *p60 = *p60 - 0x14000;
            *(int*)(thiz + 0x324) = Sound_PlayLong(
                *(unsigned int*)(thiz + 0x324), 3, 0x8d,
                *(const Vector3*)(thiz + 0x74), 0);
            int v = *(int*)(thiz + 0x320) + (int)0xff5d8000;
            if (*(int*)(thiz + 0x60) <= v) {
                *(int*)(thiz + 0x60) = v;
                thiz[0x32c] = thiz[0x32c] + 1;
                *(short*)(thiz + 0x328) = 0;
            }
        }
        break;
    case 2:
        if (*(unsigned short*)(thiz + 0x328) >= 0x6e) {
            *(int*)(thiz + 0x324) = Sound_PlayLong(
                *(unsigned int*)(thiz + 0x324), 3, 0x8d,
                *(const Vector3*)(thiz + 0x74), 0);
            *(int*)(thiz + 0x60) = *(int*)(thiz + 0x60) + 0xa000;
            if (*(int*)(thiz + 0x60) >= *(int*)(thiz + 0x320)) {
                *(int*)(thiz + 0x60) = *(int*)(thiz + 0x320);
                thiz[0x32c] = 0;
                *(short*)(thiz + 0x328) = 0;
            }
        } else {
            *(unsigned short*)(thiz + 0x328) = *(unsigned short*)(thiz + 0x328) + 1;
        }
        break;
    case 3:
    default:
        break;
    }

    Platform_UpdateModelPosAndRotY((Platform*)thiz);
    if (Platform_IsClsnInRange((Platform*)thiz, 0, 0)) {
        Platform_UpdateClsnPosAndRot((Platform*)thiz);
    }
    MovingMeshCollider_Transform(thiz + 0x124, *(const Matrix4x3*)(thiz + 0x2ec), *(short*)(thiz + 0x8e));
    thiz[0x32a] = 0;
    return 1;
}
