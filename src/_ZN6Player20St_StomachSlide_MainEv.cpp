//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef s32 Fix12;

extern "C" {
extern void func_ov002_020bf90c(void* c);
extern int _ZN6Player7IsStateERNS_5StateE(void* c, void* s);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern void func_ov002_020c06fc(void* c, u32 arg);
extern int func_ov002_020dd2f4(void* c);
extern void func_ov002_020c0364(void* c, u32 arg);
extern int func_ov002_020c0688(void* c);
extern int func_ov002_020e2ea0(void* c);
extern int _ZN6Player6IsAnimEj(void* c, u32 anim);
extern int _ZN6Player12FinishedAnimEv(void* c);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(void* c, u32 anim, int a, Fix12 b, u32 d);
extern void func_ov002_020c18b0(void* c, u32 a);
extern void func_ov002_020e25f0(void* c, int a);
extern void func_ov002_020dba0c(void* c);
extern void _ZN12CylinderClsn5ClearEv(void* c);
extern void _ZN12CylinderClsn6UpdateEv(void* c);
extern void func_ov002_020dc560(void* c);
extern int func_ov002_020e0ccc(void* c, short* st);
extern Fix12 _ZN4cstd5atan2E5Fix12IiES1_(Fix12 a, Fix12 b);
extern void _Z15ApproachLinear2Rsss(short* cur, short target, short step);
extern void func_ov002_020bedd4(void* c);

extern u8 data_020a0e40;
extern u16 data_0209f49e[];
extern u8 data_0209ee90;
extern int data_ov002_021105bc[];
extern int data_ov002_021101fc[];
extern int data_ov002_0211031c[];
extern int data_ov002_0211013c[];
extern int data_ov002_021101b4[];
}

extern "C" int _ZN6Player20St_StomachSlide_MainEv(char* c)
{
    void* light0 = *(void**)(c + 0x358);
    if (light0 != 0) {
        int* p = (int*)(((long long)(int)((char*)light0 + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL);
        *p |= 0x4000;
    }

    switch (*(u8*)(c + 0x6e6)) {
    case 0:
        func_ov002_020bf90c(c);
        if (*(u8*)(c + 0x6de) == 0) {
            *(u8*)(c + 0x6e4) = 1;
            if (_ZN6Player7IsStateERNS_5StateE(c, data_ov002_021105bc)) {
                if (*(int*)(c + 0x358) != 0) {
                    *(int*)(c + 0x98) = 0;
                    goto case0_e0;
                }
            }
            {
                u32 arg = 0x4000;
                if (*(u8*)(c + 0x70e) == 0) arg = 0x8000;
                func_ov002_020c06fc(c, arg);
            }
            func_ov002_020dd2f4(c);
            if (_ZN6Player7IsStateERNS_5StateE(c, data_ov002_021105bc) &&
                (u16)(*(u16*)(c + 0x6ce) & 1)) {
                func_ov002_020c0364(c, 2);
            }
        }
    case0_e0:
        if (*(int*)(c + 0x98) == 0) {
            if (*(u8*)(c + 0x70e) == 0) {
                *(u8*)(c + 0x6e3) = 0;
                *(u8*)(c + 0x6e6) = 2;
                goto end;
            }
            {
                u8* p = (u8*)(((long long)(int)(c + 0x6e7)) & 0xFFFFFFFFFFFFFFFFLL);
                *p = (u8)(*p + 1);
            }
            if (*(u8*)(c + 0x6e7) >= 0x1e) {
                *(u8*)(c + 0x6e3) = 0;
                *(u8*)(c + 0x6e6) = 2;
                goto end;
            }
        } else {
            *(u8*)(c + 0x6e7) = 0;
        }

        if (func_ov002_020c0688(c)) {
            if (func_ov002_020e2ea0(c)) {
                return 1;
            }
            if (_ZN6Player6IsAnimEj(c, 0x40) && _ZN6Player12FinishedAnimEv(c)) {
                _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x43, 0x40000000, 0x1000, 0);
            }
            {
                u16 flags = *(u16*)((char*)data_0209f49e + data_020a0e40 * 0x18);
                if ((flags & 1) || (flags & 2)) {
                    if (!(u16)(*(u16*)(c + 0x6ce) & 1)) {
                        _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_021101fc);
                    }
                }
            }
            func_ov002_020c18b0(c, 0);
        } else {
            if (_ZN6Player7IsStateERNS_5StateE(c, data_ov002_0211031c)) {
                *(u8*)(c + 0x6e6) = 1;
                *(u8*)(c + 0x6e3) = 0;
                if (*(int*)((char*)&data_0209ee90 + 0x244) != 0) {
                    if ((*(u8*)(c + 0x70c) | *(u8*)(c + 0x70e)) != 0) {
                        *(int*)(c + 0xa8) = 0x15000;
                    }
                }
                func_ov002_020e25f0(c, 0);
                _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x54, 0x40000000, 0x1000, 0);
            }
        }
        func_ov002_020dba0c(c);
        _ZN12CylinderClsn5ClearEv(c + 0x314);
        _ZN12CylinderClsn6UpdateEv(c + 0x314);
        goto end;

    case 1:
        func_ov002_020dba0c(c);
        _ZN12CylinderClsn5ClearEv(c + 0x314);
        _ZN12CylinderClsn6UpdateEv(c + 0x314);
        if (*(u8*)(c + 0x6de) == 0) {
            *(u8*)(c + 0x6e6) = 0;
            *(int*)(c + 0xa8) = 0;
            *(u8*)(c + 0x6e3) = 0;
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x43, 0x40000000, 0x1000, 0);
            goto end;
        }
        func_ov002_020dc560(c);
        {
            u8* p = (u8*)(((long long)(int)(c + 0x6e3)) & 0xFFFFFFFFFFFFFFFFLL);
            *p = (u8)(*p + 1);
        }
        if (*(u8*)(c + 0x6e3) <= 0x1e) goto end;
        if (*(int*)(c + 0x60) - *(int*)(c + 0x644) <= 0x1f4000) goto end;
        _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_021101b4);
        return 1;

    case 2:
        *(s16*)(c + 0x90) = 0;
        *(s16*)(c + 0x8c) = *(s16*)(c + 0x90);
        if (*(u8*)(c + 0x6e3) == 0) {
            void* light = *(void**)(c + 0x358);
            int haveLight = (light != 0);
            if (haveLight) {
                u32 animId = 0x18;
                int b1 = (*(int*)((char*)light + 0xb0) & 0x8000) != 0;
                if (b1) {
                    animId = 0x8b;
                    if (*(int*)(c + 8) == 2) {
                        int b2 = (*(u16*)((char*)light + 0xc) == 0xce);
                        if (b2) {
                            animId = 0x18;
                        }
                    }
                }
                _ZN6Player7SetAnimEji5Fix12IiEj(c, animId, 0x40000000, 0x1000, 0);
            } else {
                _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x3e, 0x40000000, 0x1000, 0);
            }
            *(s16*)(c + 0x94) = *(s16*)(c + 0x8e);
            {
                u8* p = (u8*)(((long long)(int)(c + 0x6e3)) & 0xFFFFFFFFFFFFFFFFLL);
                *p = (u8)(*p + 1);
            }
            goto end;
        }
        if (_ZN6Player12FinishedAnimEv(c)) {
            if (func_ov002_020e0ccc(c, *(short**)(c + 0x358))) {
                return 1;
            }
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211013c);
        }
        goto end;
    }

end:
    if (*(u8*)(c + 0x6de) != 0) {
        s16 v = _ZN4cstd5atan2E5Fix12IiES1_(*(int*)(c + 0x98) >> 8, *(int*)(c + 0xa8) >> 8) - 0x4000;
        if (v < 0) v = 0;
        if (v >= 0x2aaa) v = 0x2aaa;
        _Z15ApproachLinear2Rsss((short*)(c + 0x8c), v, 0x200);
    }
    func_ov002_020bedd4(c);
    *(u8*)(c + 0x70c) = *(u8*)(c + 0x70e);
    return 1;
}
