//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Vector3 { int x, y, z; };
struct Camera;

extern "C" {
extern void _ZN5Sound9PlayBank0EjRK7Vector3(u32 a, void* v);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(u32 a, u32 b, void* v);
extern void _Z14ApproachLinearRiii(int* a, int b, int c);
extern int _ZNK6Player14GetBodyModelIDEjb(void* c, u32 a, int b);
extern int _ZNK9Animation12WillHitFrameEi(void* anim, int frame);
extern int _ZN6Player12FinishedAnimEv(void* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern void func_ov002_020bedd4(void* c);
extern void func_0200d8c8(struct Camera* cam, const struct Vector3* v, int strength);

extern struct Camera* data_0209f318;
extern int data_ov002_0211013c[];
}

extern "C" int _ZN6Player12St_Bonk_MainEv(char* c)
{
    int rate;

    if (*(u16*)(c + 0x6a4) != 0) {
        *(int*)(c + 0x98) = 0x40000;
        *(int*)(c + 0xa8) = 0x8000;
        goto ret1;
    }

    rate = 0x1000;
    if (*(u8*)(c + 0x6de) == 0) {
        int v = *(int*)(c + 0x640);
        if (v < 0) {
            *(int*)(c + 0xa8) = (-v) / 3;
            if (*(int*)(c + 0xa8) <= 0x1000) {
                *(int*)(c + 0xa8) = 0;
            }
        }

        if (*(u8*)(c + 0x70c) == 0) {
            _ZN5Sound9PlayBank0EjRK7Vector3(*(u32*)(c + 0x66c) + 0x50, c + 0x74);
            _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(u8*)(c + 0x6d9), 0x11, c + 0x74);
            *(u8*)(c + 0x70c) = 1;
        }

        if (*(int*)(c + 0x684) - *(int*)(c + 0x60) > 0xbb8000) {
            func_0200d8c8(data_0209f318, (struct Vector3*)(c + 0x5c), 0x7d0000);
        }

        rate = 0x1800;
    }

    _Z14ApproachLinearRiii((int*)(c + 0x98), 0, rate);

    if (*(int*)(c + 0x98) != 0) {
        goto willhit;
    }
    if (*(u8*)(c + 0x6de) == 0) {
        goto finishedanim;
    }
willhit:
    {
        u32 arg = (u8)*(int*)(c + 8);
        int modelIdx = _ZNK6Player14GetBodyModelIDEjb(c, arg, 0);
        char* anim = *(char**)(c + modelIdx * 4 + 0xdc) + 0x50;
        if (_ZNK9Animation12WillHitFrameEi(anim, 0x2e) != 0) {
            *(u8*)(c + 0x6e5) = 1;
        }
    }
    goto tail;
finishedanim:
    *(u8*)(c + 0x6e5) = 0;
    if (_ZN6Player12FinishedAnimEv(c) != 0) {
        *(s16*)(c + 0x94) = *(s16*)(c + 0x94) + 0x8000;
        *(s16*)(c + 0x8e) = *(s16*)(c + 0x94);
        _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211013c);
        return 1;
    }
tail:
    if (*(u8*)(c + 0x6e5) == 0) {
        func_ov002_020bedd4(c);
    }
    *(int*)(c + 0x640) = *(int*)(c + 0xa8);
ret1:
    return 1;
}
