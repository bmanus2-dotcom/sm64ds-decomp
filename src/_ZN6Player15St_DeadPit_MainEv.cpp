//cpp
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;

extern "C" {
extern int _ZN6Player12FinishedAnimEv(void* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern void KillPlayer(void);
extern void func_ov002_020c0108(void* c, int a);
extern u32 _ZN5Sound8PlayLongEjjjRK7Vector3j(u32 a, u32 b, u32 c, int* pos, u32 d);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(u32 a, u32 b, int* pos);
extern void Vec3_RotateYAndTranslate(int* out, int* in, s16 angle, int* src);
extern void func_ov002_020c9718(u8* c);
extern void func_ov002_020bedd4(char* c);

extern u8 data_0209f2d8;
extern int data_ov002_021104fc[];
}

extern "C" int _ZN6Player15St_DeadPit_MainEv(char* self)
{
    switch (*(u8*)(self + 0x6e3)) {
    case 0:
        break;
    case 1: {
        int b = (data_0209f2d8 == 1);
        if (b) {
            if (*(u16*)(self + 0x6a6) == 0) {
                _ZN6Player11ChangeStateERNS_5StateE(self, data_ov002_021104fc);
                return 1;
            }
        }
        return 1;
    }
    case 2:
    case 5:
        if (*(u8*)(self + 0x6de) == 0) {
            *(u32*)(self + 0x98) = 0;
            *(u32*)(self + 0xa8) = 0;
        }
        if (*(u8*)(self + 0x6e5) == 0) {
            if (_ZN6Player12FinishedAnimEv(self) != 0) {
                *(u8*)(self + 0x6e5) = 1;
                KillPlayer();
            }
        }
        break;
    case 3: {
        func_ov002_020c0108(self, 0);
        u32 snd = _ZN5Sound8PlayLongEjjjRK7Vector3j(*(u32*)(self + 0x620), 0, 0x10a, (int*)(self + 0x74), 0);
        int* p = (int*)(((long long)(int)(self + 0x68c)) & 0xFFFFFFFFFFFFFFFFLL);
        *(u32*)(self + 0x620) = snd;
        *p += 0x5000;
        if (*(u8*)(self + 0x6e5) == 0) {
            if (*(s32*)(self + 0x68c) >= 0xb4000) {
                *(u8*)(self + 0x6e5) = 1;
                KillPlayer();
            } else {
                *p += 0x2000;
                if (*(u8*)(self + 0x70c) == 0) {
                    if (*(s32*)(self + 0x68c) >= 0x64) {
                        _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(u8*)(self + 0x6d9), 0x25, (int*)(self + 0x74));
                        *(u8*)(self + 0x70c) = 1;
                    }
                }
            }
        }
        break;
    }
    case 6: {
        int src[3];
        src[0] = 0;
        src[1] = -0x1e000;
        src[2] = 0x64000;
        int* q = *(int**)(self + 0x364);
        s16 angle = *(s16*)((char*)q + 0x8e);
        Vec3_RotateYAndTranslate((int*)(self + 0x5c), (int*)((char*)q + 0x5c), angle, src);
        if (*(u16*)(self + 0x6a4) < 30) {
            *(u8*)(self + 0x6f5) = 0;
        }
    }
    /* fallthrough */
    case 4:
        if (*(u16*)(self + 0x6a4) == 1) {
            KillPlayer();
            *(u8*)(self + 0x6f5) = 0;
        }
        break;
    case 7:
    case 8:
        func_ov002_020c9718((u8*)self);
        if (*(u8*)(self + 0x6e5) == 0) {
            if (_ZN6Player12FinishedAnimEv(self) != 0) {
                *(u8*)(self + 0x6e5) = 1;
                KillPlayer();
                *(u8*)(self + 0x706) = 1;
            }
        }
        break;
    case 9:
        break;
    }

    func_ov002_020bedd4(self);
    return 1;
}
