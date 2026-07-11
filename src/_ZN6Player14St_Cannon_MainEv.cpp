//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef s32 Fix12;

extern "C" {
extern short GetAngleToCamera(int i);
extern void func_0200d6f0(void* thiz, u8 pid);
extern void func_02012694(u32 id, void* v);
extern void _ZN5Sound9PlayBank0EjRK7Vector3(u32 a, void* v);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(u32 a, u32 b, void* v);
extern void func_ov002_020c9e18(void* c);
extern void func_ov002_020c1eb4(void* self, int dmg);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(void* c, u32 anim, int a, Fix12 b, u32 d);
extern void _ZN8Particle20RunningSlidingDustAtE5Fix12IiES1_S1_(int a, int b, int cc);
extern int _ZN4cstd5atan2E5Fix12IiES1_(int a, int b);
extern void func_ov002_020bedd4(void* c);
extern int _ZN6Player12FinishedAnimEv(void* c);

extern u8 data_020a0e40;
extern u16 data_0209f49e[];
extern char* data_0209f318;
extern short data_02082214[];
extern int data_ov002_0211031c[];
extern int data_ov002_02110214[];
}

extern "C" int _ZN6Player14St_Cannon_MainEv(char* c)
{
    switch (*(u8*)(c + 0x6e3)) {
    case 0:
        break;
    case 1: {
        if ((*(u16*)((char*)data_0209f49e + data_020a0e40 * 0x18) & 3) == 0)
            break;

        char* p = data_0209f318;
        *(s16*)(c + 0x94) = GetAngleToCamera(*(u8*)(c + 0x6d8)) + 0x8000;
        *(s16*)(c + 0x8e) = *(s16*)(c + 0x94);

        int ang = *(u16*)(p + 0x17e);
        int j = ang >> 4;
        *(int*)(c + 0x98) = (int)(((long long)data_02082214[j * 2 + 1] * 0x64000 + 0x800) >> 12);
        *(int*)(c + 0xa8) = (int)(((long long)data_02082214[j * 2] * 0x64000 + 0x800) >> 12);
        *(s16*)(c + 0x8c) = 0;
        *(u8*)(c + 0x6e3) = 2;
        *(u8*)(c + 0x6f5) = 0x1f;
        *(u8*)(c + 0x713) = 1;
        *(int*)(((long long)(int)(c + 0x2ec)) & 0xFFFFFFFFFFFFFFFFLL) |= 0x20;
        func_0200d6f0(p, *(u8*)(c + 0x6d8));
        func_02012694(0x14f, c + 0x74);
        _ZN5Sound9PlayBank0EjRK7Vector3(0xb9, c + 0x74);
        _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(u8*)(c + 0x6d9), 0xc, c + 0x74);
        func_ov002_020c9e18(c);
        *(u8*)(c + 0x6f6) = 0;
        break;
    }
    case 2:
        if ((*(u8*)(c + 0x6e9) & 6) != 0) {
            func_ov002_020c1eb4(c, (short)(*(s16*)(c + 0x8e) + 0x8000));
            return 1;
        }
        if (*(u8*)(c + 0x6de) == 0) {
            if (*(u8*)(c + 0x6e5) != 0) {
                _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211031c);
                return 1;
            }
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211031c);
            *(u8*)(c + 0x6de) = 1;
            *(u8*)(c + 0x6df) = 0;
            *(int*)(c + 0xa8) = 0xa000;
            return 1;
        }
        if (*(u8*)(c + 0x6ff) != 0 && *(int*)(c + 0xa8) < 0) {
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x72, 0x40000000, 0x1000, 0);
            *(u8*)(c + 0x6e3) = 3;
            return 1;
        }
        *(int*)(((long long)(int)(c + 0x98)) & 0xFFFFFFFFFFFFFFFFLL) -= 0x80;
        if (*(int*)(c + 0x98) < 0xa000)
            *(int*)(c + 0x98) = 0xa000;
        if (*(int*)(c + 0xa8) >= 0)
            _ZN8Particle20RunningSlidingDustAtE5Fix12IiES1_S1_(*(int*)(c + 0x5c), *(int*)(c + 0x60), *(int*)(c + 0x64));
        if (*(u8*)(c + 0x6e5) == 0)
            *(s16*)(c + 0x8c) = _ZN4cstd5atan2E5Fix12IiES1_(*(int*)(c + 0x98) >> 8, *(int*)(c + 0xa8) >> 8) - 0x4000;
        func_ov002_020bedd4(c);
        // fall through
    case 3:
        if (_ZN6Player12FinishedAnimEv(c)) {
            *(u8*)(c + 0x6e3) = 1;
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_02110214);
        }
        func_ov002_020bedd4(c);
        break;
    }
    return 1;
}
