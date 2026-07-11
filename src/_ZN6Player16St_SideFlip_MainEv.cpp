//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef s32 Fix12;

extern "C" {
extern void func_ov002_020eeca8(void* a, void* b);
extern int _ZN6Player7IsStateERNS_5StateE(void* c, void* s);
extern void func_ov002_020e28d4(void* c, u32 a, u32 b);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern int func_ov002_020e2664(void* c);
extern int _ZN6Player12FinishedAnimEv(void* c);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(void* c, u32 anim, int a, Fix12 b, u32 d);
extern int _ZNK6Player14GetBodyModelIDEjb(void* c, u32 a, int b);
extern void _ZN5Sound9PlayBank0EjRK7Vector3(u32 a, void* v);
extern void func_ov002_020bedd4(void* c);

extern int data_ov002_02110694[];
extern int data_ov002_02110424[];
extern int data_ov002_021101fc[];
extern u8 data_020a0e40;
extern u16 data_0209f49e[];
extern int data_ov002_0211052c[];
extern u16 data_0209f49c[];
extern int data_ov002_021101e4[];
extern int data_ov002_02110454[];
}

extern "C" int _ZN6Player16St_SideFlip_MainEv(char* c)
{
    func_ov002_020eeca8(c + 0x380, c);

    if (_ZN6Player7IsStateERNS_5StateE(c, data_ov002_02110694)) {
        if (*(int*)(c + 0xa8) < 0) {
            *(int*)(c + 0x98) = 0x12000;
        }
        func_ov002_020e28d4(c, 0, 0x800);
    } else {
        func_ov002_020e28d4(c, 0x1800, 0x800);
    }

    if (*(u8*)(c + 0x6de) == 0) {
        _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_02110424);
    } else {
        if (!_ZN6Player7IsStateERNS_5StateE(c, data_ov002_021101fc)) {
            u16 r0v = *(u16*)((char*)data_0209f49e + data_020a0e40 * 0x18);
            if (r0v & 0x400) {
                if (_ZN6Player7IsStateERNS_5StateE(c, data_ov002_0211052c)) {
                    *(s16*)(c + 0x94) = *(s16*)(c + 0x8e);
                }
            }
            if (func_ov002_020e2664(c)) {
                return 1;
            }
        } else {
            if (_ZN6Player12FinishedAnimEv(c)) {
                _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x54, 0x40000000, 0x1000, 0);
            }
        }

        *(int*)(c + 0x9c) = -0x4000;

        if (*(int*)(c + 0xa8) >= 0) {
            u16 r1v = *(u16*)((char*)data_0209f49c + data_020a0e40 * 0x18);
            if ((r1v & 2) != 0
                || _ZN6Player7IsStateERNS_5StateE(c, data_ov002_021101e4)
                || _ZN6Player7IsStateERNS_5StateE(c, data_ov002_021101fc)
                || _ZN6Player7IsStateERNS_5StateE(c, data_ov002_0211052c)) {
                *(int*)(c + 0x9c) = -0x3400;
            }
        } else {
            if (*(int*)(c + 8) == 1
                && _ZN6Player7IsStateERNS_5StateE(c, data_ov002_0211052c)) {
                *(u8*)(c + 0x6e6) = 0;
                _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_02110454);
                return 1;
            }
        }

        if (_ZN6Player7IsStateERNS_5StateE(c, data_ov002_021101e4)) {
            int id = _ZNK6Player14GetBodyModelIDEjb(c, *(u32*)(c + 8) & 0xff, 0);
            void* anim = *(void**)(c + (id << 2) + 0xdc);
            u32 w = *(u32*)((char*)(((long long)(int)((char*)anim + 0x50)) & 0xFFFFFFFFFFFFFFFFLL) + 8);
            if ((u16)(w >> 12) == 0x10) {
                _ZN5Sound9PlayBank0EjRK7Vector3(0xf, c + 0x74);
            }
        }
    }

    func_ov002_020bedd4(c);
    return 1;
}
