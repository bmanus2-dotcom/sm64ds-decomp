//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef s32 Fix12;

struct Vector3 { int x, y, z; };

extern "C" {
extern void func_ov002_020bf90c(char* c);
extern void func_ov002_020c06fc(char* c, u32 mask);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(u32 a, u32 b, const Vector3& v);
extern int func_ov002_020e2c84(char* c);
extern void func_ov002_020bf9d4(char* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern int _ZN4cstd5atan2E5Fix12IiES1_(Fix12 a, int b);
extern void _Z15ApproachLinear2Rsss(s16* v, s16 target, s16 step);
extern int _ZN6Player9GetHealthEv(void* c);
extern int _ZN6Player12FinishedAnimEv(void* c);
extern void func_ov002_020bedd4(char* c);

extern int data_ov002_0211031c[];
extern int data_ov002_0211010c[];
extern int data_ov002_0211013c[];
}

extern "C" int _ZN6Player14St_Thrown_MainEv(char* c)
{
    if (*(u16*)(c + 0x6a4) == 1) {
        *(int*)(((int)c + 0x2ec) & 0xFFFFFFFFFFFFFFFFULL) |= 0x2000;
    }
    func_ov002_020bf90c(c);

    u8 state = *(u8*)(c + 0x6e3);
    switch (state) {
    case 0:
        if (*(u8*)(c + 0x6de) == 0) {
            *(s16*)(c + 0x8c) = 0;
            *(int*)(((int)c + 0x2ec) & 0xFFFFFFFFFFFFFFFFULL) &= ~0x2000;
            func_ov002_020c06fc(c, 0x8000);
            if (*(u8*)(c + 0x70c) == 0) {
                *(u8*)(c + 0x70c) = 1;
                _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(u8*)(c + 0x6d9), 6, *(Vector3*)(c + 0x74));
            }
            int r5 = func_ov002_020e2c84(c);
            if (r5 != 2 && *(u8*)(c + 0x707) == 0) {
                func_ov002_020bf9d4(c);
            }
            if (r5 != 0) {
                return 1;
            }
            if (*(int*)(c + 0x558) == 0x1000) {
                if (*(int*)(c + 0x98) == 0) {
                    *(u8*)(c + 0x6e3) = 1;
                    goto L1f8;
                }
            } else {
                _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211031c);
                return 1;
            }
        }
        *(s16*)(c + 0x8e) = *(s16*)(c + 0x94);
        *(int*)(c + 0x98) = (int)(((long long)*(int*)(c + 0x98) * 0xfae + 0x800) >> 12);
        if (*(u8*)(c + 0x6de) != 0) {
            int a = _ZN4cstd5atan2E5Fix12IiES1_(*(int*)(c + 0x98), *(int*)(c + 0xa8));
            s16 b = a - 0x4000;
            if (b > 0x3000) b = 0x3000;
            *(s16*)(c + 0x8c) = b;
        } else {
            _Z15ApproachLinear2Rsss((s16*)(c + 0x8c), 0, 0x400);
        }
        break;
    case 1:
        if (_ZN6Player9GetHealthEv(c) == 0) {
            *(u8*)(c + 0x6e3) = 1;
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211010c);
            return 1;
        }
        if (_ZN6Player12FinishedAnimEv(c) != 0) {
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211013c);
            *(s16*)(c + 0x94) = *(s16*)(c + 0x8e);
        }
        func_ov002_020bedd4(c);
        break;
    }

L1f8:
    if (*(u8*)(c + 0x6de) == 0) {
        func_ov002_020e2c84(c);
    }
    return 1;
}
