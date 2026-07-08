typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int data_0209f32c;
extern int data_ov002_0211013c;

extern void _ZN6Player11ChangeStateERNS_5StateE(void* self, void* state);
extern int func_ov002_020ceb54(char* p);
extern void _ZN5Sound9PlayBank0EjRK7Vector3(u32 snd, void* pos);
extern void func_ov002_020ce8bc(char* p, int a);
extern void func_ov002_020ceb7c(char* p);
extern int _ZNK6Player14GetBodyModelIDEjb(void* self, u32 a, int b);
extern void MulVec3Mat4x3(void* a, void* b, void* out);
extern void Vec3_LslInPlace(int* v, int sh);
extern u32 func_020229f0(int x, int y, int z);
extern void _ZN5Sound9PlayBank3EjRK7Vector3(u32 snd, void* pos);

int func_ov002_020ce5f8(char* p)
{
    volatile int vec[3];
    char* m;
    int base5;
    int t;

    t = data_0209f32c - 0x50000;
    if (*(int*)(p + 0x60) >= t) {
        if ((*(u8*)(p + 0x6e9) & 1) == 0) {
            if (*(int*)(p + 0xa8) >= 0) {
                *(int*)(p + 0x60) = t;
                *(int*)(p + 0xa8) = 0;
            }
        } else {
            if (t < *(int*)(p + 0x60) - 0xa000) {
                *(u8*)(p + 0x706) = 0;
                _ZN6Player11ChangeStateERNS_5StateE(p, &data_ov002_0211013c);
                return 1;
            }
        }
    }

    if (func_ov002_020ceb54(p) == 0) {
        if (*(u8*)(p + 0x70c) == 0) {
            *(u8*)(((long long)(int)(p + 0x70c)) & 0xFFFFFFFFFFFFFFFFLL) |= 1;
            _ZN5Sound9PlayBank0EjRK7Vector3(0x17, p + 0x74);
            *(int*)(p + 0x628) = 0;
            func_ov002_020ce8bc(p, *(int*)(p + 0x640));
        } else {
            *(u8*)(p + 0x70c) = 0;
            func_ov002_020ceb7c(p);
        }

        m = *(char**)(p + _ZNK6Player14GetBodyModelIDEjb(p, *(u32*)(p + 8) & 0xff, 0) * 4 + 0xdc);
        base5 = *(int*)(m + 0x14) + 0x2d0;
        m = *(char**)(p + _ZNK6Player14GetBodyModelIDEjb(p, *(u32*)(p + 8) & 0xff, 0) * 4 + 0xdc);
        MulVec3Mat4x3((char*)base5 + 0x24, m + 0x1c, (void*)vec);
        Vec3_LslInPlace((int*)vec, 3);
        if (vec[1] < data_0209f32c - 0x1e000) {
            func_020229f0(vec[0], vec[1], vec[2]);
            if (*(u16*)(p + 0x6a6) == 0) {
                _ZN5Sound9PlayBank3EjRK7Vector3(0xb, p + 0x74);
                *(u16*)(p + 0x6a6) = 0xa;
            }
        }
    }
    return 0;
}
