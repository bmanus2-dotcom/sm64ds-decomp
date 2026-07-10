//cpp
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern "C" {
extern int func_ov002_020cf20c(char* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(char* c, void* st);
extern int func_ov002_020d674c(char* c);
extern void func_ov002_020cf384(char* c);
extern int _ZN6Player12FinishedAnimEv(char* c);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(char* c, u32 anim, int a, int b, u32 d);
extern int _ZNK6Player14GetBodyModelIDEjb(char* c, u32 a, int b);
extern void func_ov002_020cf2f8(char* c);
extern void _ZN5Sound9PlayBank0EjRK7Vector3(u32 id, void* v);
extern void func_ov002_020bedd4(char* c);

extern u8 data_020a0e40;
extern u16 data_0209f49c[];
extern u16 data_0209f49e[];
extern s16 data_0209f4a0[];
extern u8 data_0209f4ab[];
extern int data_ov002_0211013c;
extern int data_ov002_0211004c;
extern int data_ov002_021105a4;
extern u32 data_ov002_0210a60c[];
}

extern "C" int _ZN6Player20St_CeilingGrate_MainEv(char* c)
{
    int r4;
    int spd;

    r4 = func_ov002_020cf20c(c);
    if (r4 == 0x80000000) {
        *(int*)(c + 0x5c) = *(int*)(c + 0x548);
        *(int*)(c + 0x60) = *(int*)(c + 0x54c);
        *(int*)(c + 0x64) = *(int*)(c + 0x550);
        r4 = *(int*)(c + 0x60) + 0x90000;
    }

    {
        int idx = data_020a0e40 * 0x18;
        if ((*(u16*)((char*)data_0209f49c + idx) & 2) == 0) {
            _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_0211013c);
            return 1;
        }
        if (*(u16*)((char*)data_0209f49e + idx) & 0x400) {
            if (func_ov002_020d674c(c) != 0)
                _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_0211004c);
            else
                _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_021105a4);
            return 1;
        }
        {
            u8* p = data_0209f4ab + idx;
            if (*p != 0)
                *p = 5;
        }
    }

    switch (*(u8*)(c + 0x6e3)) {
    case 0:
        func_ov002_020cf384(c);
        if (_ZN6Player12FinishedAnimEv(c) != 0) {
            *(u8*)(c + 0x6e3) = 1;
            _ZN6Player7SetAnimEji5Fix12IiEj(c, data_ov002_0210a60c[*(u8*)(c + 0x6e5) & 1], 0, 0x1000, 0);
        }
        {
            char* anim = (char*)(((long long)(int)(*(char**)(c + (_ZNK6Player14GetBodyModelIDEjb(c, *(u32*)(c + 8) & 0xff, 0) << 2) + 0xdc) + 0x50)) & 0xffffffffffffffffLL);
            if ((u32)(*(int*)(anim + 8) << 4) >> 0x10 < 0x21)
                break;
        }
    case 1:
        func_ov002_020cf384(c);
        if (*(s16*)((char*)data_0209f4a0 + data_020a0e40 * 0x18) != 0) {
            *(u8*)(((int)c + 0x6e5) & 0xFFFFFFFFFFFFFFFFLL) ^= 1;
            *(u8*)(c + 0x6e3) = 2;
            spd = *(int*)(c + 0x98) >> 3;
            if (spd < 0x800)
                spd = 0x800;
            _ZN6Player7SetAnimEji5Fix12IiEj(c, data_ov002_0210a60c[(*(u8*)(c + 0x6e5) & 1) + 2], 0x40000000, spd, 0);
        }
        break;
    case 2:
        func_ov002_020cf2f8(c);
        spd = *(int*)(c + 0x98) >> 3;
        if (spd < 0x800)
            spd = 0x800;
        {
            char* anim = (char*)(((long long)(int)(*(char**)(c + (_ZNK6Player14GetBodyModelIDEjb(c, *(u32*)(c + 8) & 0xff, 0) << 2) + 0xdc) + 0x50)) & 0xffffffffffffffffLL);
            *(int*)(anim + 0xc) = spd;
        }
        if (_ZN6Player12FinishedAnimEv(c) != 0) {
            _ZN5Sound9PlayBank0EjRK7Vector3(0xb2, c + 0x74);
            if (*(s16*)((char*)data_0209f4a0 + data_020a0e40 * 0x18) != 0) {
                *(u8*)(((int)c + 0x6e5) & 0xFFFFFFFFFFFFFFFFLL) ^= 1;
                _ZN6Player7SetAnimEji5Fix12IiEj(c, data_ov002_0210a60c[(*(u8*)(c + 0x6e5) & 1) + 2], 0x40000000, 0x1000, 0);
            } else {
                *(u8*)(c + 0x6e3) = 1;
                _ZN6Player7SetAnimEji5Fix12IiEj(c, data_ov002_0210a60c[*(u8*)(c + 0x6e5) & 1], 0, 0x1000, 0);
            }
        }
        break;
    }

    *(int*)(c + 0x60) = r4 - 0x90000;
    func_ov002_020bedd4(c);
    return 1;
}
