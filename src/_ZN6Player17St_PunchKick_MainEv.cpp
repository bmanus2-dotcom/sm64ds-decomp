//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef s32 Fix12;

extern "C" {
extern void func_ov002_020dd5ec(void* c);
extern void _ZN6Player17St_PunchKick_InitEv(void* c);
extern void func_ov002_020d8a50(void* c, u32 a);
extern int func_ov002_020e2c84(char* self);
extern void _Z14ApproachLinearRiii(int* a, int b, int c);
extern void func_ov002_020c2f64(void* c);
extern int func_ov002_020c0434(char* c);
extern void func_ov002_020c0364(char* c, u32 arg);
extern int _ZN6Player12FinishedAnimEv(void* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(void* c, u32 anim, int a, Fix12 b, u32 d);
extern int func_ov002_020bf9d4(char* c);
extern void func_ov002_020bedd4(char* self);

extern u8 data_020a0e40;
extern u16 data_0209f49e[];
extern s16 data_0209f4a0[];
extern int data_ov002_0211013c[];
}

extern "C" int _ZN6Player17St_PunchKick_MainEv(char* c)
{
    u16 st = *(u16*)(c + 0x6a4);

    if (st != 0) {
        if (st == 1) {
            func_ov002_020dd5ec(c);
        }
    } else {
        if (*(u16*)(c + 0x6aa) == 0) {
            u8 idx = data_020a0e40;
            u16 flags = *(u16*)((char*)data_0209f49e + idx * 0x18);
            if ((flags & 1) != 0 && *(u8*)(c + 0x6e2) < 2) {
                u8* p = (u8*)(((long long)(int)(c + 0x6e2)) & 0xFFFFFFFFFFFFFFFFLL);
                (*p)++;
                _ZN6Player17St_PunchKick_InitEv(c);
                return 1;
            }
        }

        func_ov002_020d8a50(c, *(u8*)(c + 0x6e2));

        if (*(u8*)(c + 0x6de) != 0)
            goto end;

        if (*(u8*)(c + 0x6e2) == 2 && *(u8*)(c + 0x6e6) == 0) {
            *(u8*)(c + 0x6e6) = 1;
            if (func_ov002_020e2c84(c) != 0)
                return 1;
        }

        _Z14ApproachLinearRiii((int*)(c + 0x98), 0, 0x800);
        func_ov002_020c2f64(c);

        if (func_ov002_020c0434(c) != 0) {
            func_ov002_020c0364(c, 3);
            return 1;
        }

        if (_ZN6Player12FinishedAnimEv(c) || *(u8*)(c + 0x6e2) == 2) {
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211013c);
            *(u16*)(c + 0x6aa) = 0x10;

            if (*(u8*)(c + 0x6e2) != 2)
                *(int*)(c + 0x98) = 0;

            if (*(s16*)(c + 0x94) != *(s16*)(c + 0x8e)) {
                *(int*)(c + 0x98) = 0;
                *(s16*)(c + 0x94) = *(s16*)(c + 0x8e);
            }

            {
                u8 idx2 = data_020a0e40;
                s16 val = *(s16*)((char*)data_0209f4a0 + idx2 * 0x18);
                if (val == 0 && *(u8*)(c + 0x6e2) == 2) {
                    _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x52, 0x40000000, 0x1000, 0);
                    *(s16*)(c + 0x94) = *(s16*)(c + 0x8e);
                    *(int*)(c + 0x98) = 0;
                }
            }

            if (*(u8*)(c + 0x6e2) != 2)
                goto end;
            if (*(u8*)(c + 0x707) != 0)
                goto end;

            func_ov002_020bf9d4(c);
        }
    }

end:
    func_ov002_020bedd4(c);
    return 1;
}
