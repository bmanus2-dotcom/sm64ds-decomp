//cpp
typedef int Fix12i;
struct Vector3 { Fix12i x, y, z; };
struct Matrix4x3 { Fix12i m[12]; };

extern "C" void NormalizeVec3(const Vector3 *src, Vector3 *dst);
extern "C" void CrossVec3(const Vector3 *a, const Vector3 *b, Vector3 *out);
extern "C" Fix12i DotVec3(const Vector3 *a, const Vector3 *b);

namespace G3i {
void LookAt_(const Vector3 *at, const Vector3 *up, const Vector3 *eye, bool draw, Matrix4x3 *mat)
{
    Vector3 forward;
    Vector3 right;
    Vector3 up2;
    Fix12i tx;
    Fix12i ty;
    Fix12i tz;

    forward.x = at->x - eye->x;
    forward.y = at->y - eye->y;
    forward.z = at->z - eye->z;
    NormalizeVec3(&forward, &forward);

    CrossVec3(up, &forward, &right);
    NormalizeVec3(&right, &right);

    CrossVec3(&forward, &right, &up2);

    if (draw) {
        volatile int *regMode = (volatile int *)0x4000440;
        volatile int *mtx = (volatile int *)0x400045c;
        *regMode = 2;
        *mtx = right.x;
        *mtx = up2.x;
        *mtx = forward.x;
        *mtx = right.y;
        *mtx = up2.y;
        *mtx = forward.y;
        *mtx = right.z;
        *mtx = up2.z;
        *mtx = forward.z;
        tx = -DotVec3(eye, &right);
        ty = -DotVec3(eye, &up2);
        tz = -DotVec3(eye, &forward);
        *mtx = tx;
        *mtx = ty;
        *mtx = tz;
    }

    if (mat == 0) {
        return;
    }

    mat->m[0] = right.x;
    mat->m[1] = up2.x;
    mat->m[2] = forward.x;
    mat->m[3] = right.y;
    mat->m[4] = up2.y;
    mat->m[5] = forward.y;
    mat->m[6] = right.z;
    mat->m[7] = up2.z;
    mat->m[8] = forward.z;
    mat->m[9] = -DotVec3(eye, &right);
    mat->m[10] = -DotVec3(eye, &up2);
    mat->m[11] = -DotVec3(eye, &forward);
}
}