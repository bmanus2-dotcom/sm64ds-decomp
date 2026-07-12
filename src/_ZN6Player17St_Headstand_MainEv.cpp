//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual Obj* v2();
};

extern "C" {
extern int _ZN6Player12FinishedAnimEv(void* c);
extern int _ZN6Player7SetAnimEji5Fix12IiEj(void* c, unsigned int a, int b, int d, unsigned int e);
extern void func_ov002_020cc05c(void* c, unsigned short v);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* state);
extern void func_ov002_020bedd4(void* c);

extern u8 data_020a0e40;
extern s16 data_0209f4a4[];
extern u16 data_0209f49c[];
extern u16 data_0209f49e[];
extern int data_ov002_02110724[];
extern int data_ov002_021106dc[];
}

extern "C" int _ZN6Player17St_Headstand_MainEv(char* c)
{
    Obj* obj = *(Obj**)(c+0x37c);
    Obj* r = obj->v2();
    *(int*)(c+0x5c) = *(int*)r;
    *(int*)(c+0x64) = *(int*)((char*)r+8);
    *(int*)(c+0x60) = *(int*)((char*)r+4) + *(int*)((char*)(*(Obj**)(c+0x37c))+8);

    u8 st = *(u8*)(c+0x6e3);
    switch (st) {
    case 2:
        if (_ZN6Player12FinishedAnimEv(c)) {
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x1d, 0, 0x1000, 0);
            *(u8*)(c+0x6e3) = 3;
        }
        break;
    case 3: {
        int idx = data_020a0e40 * 0x18;
        s16 val = *(s16*)((char*)data_0209f4a4 + idx);
        u16 mag = *(u16*)((char*)data_0209f49c + idx);
        if (val > 0x200) {
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x1f, 0x40000000, 0x1000, 0);
            *(u8*)(c+0x6e3) = 4;
        }
        func_ov002_020cc05c(c, mag);
        {
            s16* p = (s16*)((((long long)(int)(c+0x8e)) & 0xFFFFFFFFFFFFFFFFLL));
            *p = *p + *(s16*)(c+0x69c);
        }
        if (*(u16*)((char*)data_0209f49e + data_020a0e40 * 0x18) & 2) {
            *(s16*)(c+0x94) = *(s16*)(c+0x8e);
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_02110724);
            return 1;
        }
        break;
    }
    case 4:
        if (_ZN6Player12FinishedAnimEv(c)) {
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_021106dc);
        }
        break;
    }

    func_ov002_020bedd4(c);
    return 1;
}
