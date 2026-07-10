//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef s32 Fix12;

extern "C" {
extern void func_ov002_020bf90c(char* c);
extern void func_ov002_020c06fc(char* c, u32 a);
extern int func_ov002_020dd2f4(char* c);
extern int func_ov002_020c0688(char* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(char* c, void* s);
extern int func_0201226c(int a0, int a1, int a2, char* a3, int a4, int a5);
extern void func_ov002_020e25f0(char* c, int a);
extern void func_ov002_020c18b0(char* c, int a);
extern void func_ov002_020dcafc(char* c);
extern void _ZN5Sound9PlayBank0EjRK7Vector3(u32 a, char* v);
extern void func_ov002_020dc560(char* c);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(char* c, u32 anim, int a, Fix12 b, u32 d);
extern int _ZN6Player12FinishedAnimEv(char* c);
extern void func_ov002_020bedd4(char* c);

extern u8 data_020a0e40;
extern u16 data_0209f49e[];
extern int data_ov002_0211019c[];
extern int data_ov002_021101b4[];
extern int data_ov002_0211013c[];
}

extern "C" int _ZN6Player17St_ButtSlide_MainEv(char* c)
{
    switch (*(u8*)(c + 0x6e6)) {
    case 0:
        func_ov002_020bf90c(c);
        if (*(u8*)(c + 0x6de) == 0) {
            *(u8*)(c + 0x6e4) = 1;
            func_ov002_020c06fc(c, 0x4000);
            func_ov002_020dd2f4(c);
        }
        if (*(int*)(c + 0x98) == 0) {
            if (*(u8*)(c + 0x70e) == 0) {
                *(u8*)(c + 0x6e6) = 2;
                *(u8*)(c + 0x6e5) = 0;
                break;
            }
            (*(u8*)(((int)c + 0x6e7) & 0xFFFFFFFFFFFFFFFF))++;
            if (*(u8*)(c + 0x6e7) >= 0x1e) {
                *(u8*)(c + 0x6e6) = 2;
                *(u8*)(c + 0x6e5) = 0;
                break;
            }
        } else {
            *(u8*)(c + 0x6e7) = 0;
        }
        if (func_ov002_020c0688(c) != 0) {
            if ((*(u16*)((char*)data_0209f49e + data_020a0e40 * 0x18) & 2) != 0
                && *(u16*)(c + 0x6a6) == 0) {
                *(u8*)(c + 0x6e1) = 0;
                _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211019c);
                return 1;
            }
            *(int*)(c + 0x620) = func_0201226c(*(int*)(c + 0x620), 0, *(int*)(c + 0x66c) + 0xe2, c + 0x74, *(int*)(c + 0x98), 0);
        } else {
            *(u8*)(c + 0x6e3) = 0;
            *(u8*)(c + 0x6e6) = 1;
            *(u8*)(c + 0x6e5) = 0;
            if ((*(u8*)(c + 0x70c) | *(u8*)(c + 0x70e)) != 0)
                *(int*)(c + 0xa8) = 0x15000;
            func_ov002_020e25f0(c, 0);
            *(u8*)(c + 0x6de) = 1;
            *(u8*)(c + 0x6df) = 0;
            break;
        }
        func_ov002_020c18b0(c, 0);
        func_ov002_020dcafc(c);
        break;
    case 1:
        *(s16*)(c + 0x90) = 0;
        *(s16*)(c + 0x8c) = *(s16*)(c + 0x90);
        if (*(u8*)(c + 0x6de) == 0) {
            if (*(u8*)(c + 0x6df) == 0) {
                *(u8*)(c + 0x6df) = 1;
                _ZN5Sound9PlayBank0EjRK7Vector3(*(int*)(c + 0x66c) + 0x50, c + 0x74);
            }
            if (*(u8*)(c + 0x6e5) == 0 && *(int*)(c + 0x558) >= 0xfc1) {
                *(int*)(c + 0xa8) = -*(int*)(c + 0x640) / 2;
                (*(u8*)(((int)c + 0x6e5) & 0xFFFFFFFFFFFFFFFF))++;
            } else {
                *(u8*)(c + 0x6e6) = 0;
                *(int*)(c + 0xa8) = 0;
                break;
            }
        } else {
            func_ov002_020dc560(c);
        }
        (*(u8*)(((int)c + 0x6e3) & 0xFFFFFFFFFFFFFFFF))++;
        if (*(u8*)(c + 0x6e3) > 0x1e
            && *(int*)(c + 0x60) - *(int*)(c + 0x644) > 0x1f4000) {
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_021101b4);
            return 1;
        }
        break;
    case 2:
        *(s16*)(c + 0x90) = 0;
        *(s16*)(c + 0x8c) = *(s16*)(c + 0x90);
        if (*(u8*)(c + 0x6e5) == 0) {
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x42, 0x40000000, 0x1000, 0);
            *(s16*)(c + 0x94) = *(s16*)(c + 0x8e);
            *(u8*)(c + 0x6e5) = 1;
        } else if (_ZN6Player12FinishedAnimEv(c) != 0) {
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211013c);
        }
        break;
    }

    *(int*)(c + 0x640) = *(int*)(c + 0xa8);
    func_ov002_020bedd4(c);
    *(u8*)(c + 0x70c) = *(u8*)(c + 0x70e);
    return 1;
}
