typedef struct { int x, y, z; } Vec3;
extern int _Z14ApproachLinearRiii(int* v, int target, int step);
extern void Vec3_Sub(Vec3* out, Vec3* a, Vec3* b);
extern void func_0203ce80(Vec3* dst, Vec3* src);
extern void Vec3_MulScalarInPlace(int* v, int s);
extern int _Z14ApproachLinearRsss(short* v, short target, short step);
extern void func_ov006_020c49d8(void* c);

void func_ov006_020c5658(char* c)
{
    int buf[13];
    int r2;
    int r1;
    int r5;
    int r0;

    r2 = *(int*)(c + 0xa8);
    r1 = *(int*)(c + 0xb4);
    if (r2 < 0)
        r2 = -r2;
    r5 = _Z14ApproachLinearRiii((int*)(c + 0x9c), r1, r2);

    r2 = *(int*)(c + 0xac);
    r1 = *(int*)(c + 0xb8);
    if (r2 < 0)
        r2 = -r2;
    r0 = _Z14ApproachLinearRiii((int*)(c + 0xa0), r1, r2);

    if (r5 != 0 && r0 != 0 && *(int*)(c + 0xb8) == *(int*)(c + 0x18)) {
        *(int*)(c + 0xb4) = *(int*)(c + 0x14);
        *(int*)(c + 0xb8) = *(int*)(c + 0x1c);
        Vec3_Sub((Vec3*)buf, (Vec3*)(c + 0xb4), (Vec3*)(c + 0x9c));
        *(int*)(c + 0xa8) = buf[0];
        *(int*)(c + 0xac) = buf[1];
        *(int*)(c + 0xb0) = buf[2];
        func_0203ce80((Vec3*)(buf + 3), (Vec3*)(c + 0xa8));
        Vec3_MulScalarInPlace((int*)(c + 0xa8), *(int*)(c + 0xdc));
        *(short*)(c + 0xea) = 0;
    } else if (r5 != 0 && r0 != 0 && *(int*)(c + 0xb8) == *(int*)(c + 0x1c)) {
        *(int*)(c + 0xb4) = *(int*)(c + 0x10);
        *(int*)(c + 0xb8) = *(int*)(c + 0x18);
        Vec3_Sub((Vec3*)(buf + 6), (Vec3*)(c + 0xb4), (Vec3*)(c + 0x9c));
        *(int*)(c + 0xa8) = buf[6];
        *(int*)(c + 0xac) = buf[7];
        *(int*)(c + 0xb0) = buf[8];
        func_0203ce80((Vec3*)(buf + 9), (Vec3*)(c + 0xa8));
        Vec3_MulScalarInPlace((int*)(c + 0xa8), *(int*)(c + 0xdc));
        *(short*)(c + 0xea) = 0;
    }

    if (*(int*)(c + 0xa8) > 0)
        _Z14ApproachLinearRsss((short*)(c + 0xe6), 0x3000, 0x200);
    else
        _Z14ApproachLinearRsss((short*)(c + 0xe6), -0x3000, 0x200);
    func_ov006_020c49d8(c);
}
