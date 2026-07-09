typedef long long s64;

void MulMat3x3Mat3x3(int *dst, const int *a, const int *b)
{
    int sp[9];
    int *out;
    s64 acc;

    if (dst == b) {
        out = sp;
    } else {
        out = dst;
    }

    acc = (s64)a[1] * b[3];
    acc += (s64)a[0] * b[0];
    acc += (s64)a[2] * b[6];
    out[0] = (int)(acc >> 12);

    acc = (s64)a[1] * b[4];
    acc += (s64)a[0] * b[1];
    acc += (s64)a[2] * b[7];
    out[1] = (int)(acc >> 12);

    acc = (s64)a[1] * b[5];
    acc += (s64)a[0] * b[2];
    acc += (s64)a[2] * b[8];
    out[2] = (int)(acc >> 12);

    acc = (s64)a[4] * b[3];
    acc += (s64)a[3] * b[0];
    acc += (s64)a[5] * b[6];
    out[3] = (int)(acc >> 12);

    acc = (s64)a[4] * b[4];
    acc += (s64)a[3] * b[1];
    acc += (s64)a[5] * b[7];
    out[4] = (int)(acc >> 12);

    acc = (s64)a[4] * b[5];
    acc += (s64)a[3] * b[2];
    acc += (s64)a[5] * b[8];
    out[5] = (int)(acc >> 12);

    acc = (s64)a[7] * b[3];
    acc += (s64)a[6] * b[0];
    acc += (s64)a[8] * b[6];
    out[6] = (int)(acc >> 12);

    acc = (s64)a[7] * b[4];
    acc += (s64)a[6] * b[1];
    acc += (s64)a[8] * b[7];
    out[7] = (int)(acc >> 12);

    acc = (s64)a[7] * b[5];
    acc += (s64)a[6] * b[2];
    acc += (s64)a[8] * b[8];
    out[8] = (int)(acc >> 12);

    if (dst == b) {
        dst[0] = sp[0];
        dst[1] = sp[1];
        dst[2] = sp[2];
        dst[3] = sp[3];
        dst[4] = sp[4];
        dst[5] = sp[5];
        dst[6] = sp[6];
        dst[7] = sp[7];
        dst[8] = sp[8];
    }
}