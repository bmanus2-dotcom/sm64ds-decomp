//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef s32 Fix12;

extern "C" {
extern int _ZN6Player12FinishedAnimEv(char* c);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(char* c, u32 anim, int a, Fix12 b, u32 d);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(u32 a, u32 b, void* v);
extern void func_ov002_020daa74(char* c);
extern void _Z15ApproachLinear2Rsss(s16* ref, s16 target, s16 step);
extern void func_02012694(u32 id, void* v);
extern void _ZN6Player11ChangeStateERNS_5StateE(char* c, void* s);
extern void func_ov002_020bedd4(char* c);

extern u8 data_020a0e40;
extern u16 data_0209f49e[];
extern s16 data_0209f4a0[];
extern char data_0209ee90[];
extern int data_ov002_02110154[];
}

extern "C" int _ZN6Player22St_GrabBowserTail_MainEv(char* c)
{
    switch (*(u8*)(c + 0x6e3)) {
    case 0:
        if (_ZN6Player12FinishedAnimEv(c)) {
            *(u8*)(c + 0x6e3) = 1;
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x80, 0, 0x1000, 0);
        }
        break;
    case 1:
        if ((*(u16*)((char*)data_0209f49e + data_020a0e40 * 0x18) & 1) != 0) {
            s16 x = *(s16*)(c + 0x69c);
            if (x < 0) x = -x;
            if (x > 0xe00)
                _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(u8*)(c + 0x6d9), 0x32, c + 0x74);
            else
                _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(u8*)(c + 0x6d9), 0x33, c + 0x74);
            *(u8*)(c + 0x6e3) = 2;
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x7f, 0x40000000, 0x1000, 0);
            func_ov002_020daa74(c);
            return 1;
        }
        if (*(int*)(data_0209ee90 + 0x24c) != 0)
            *(u8*)(c + 0x6e5) = 0;
        if (*(s16*)((char*)data_0209f4a0 + data_020a0e40 * 0x18) == 0) {
            u8 v = *(u8*)(c + 0x6e5);
            (*(u8*)(((int)c + 0x6e5) & 0xFFFFFFFFFFFFFFFFLL))++;
            if (v > 0x78) {
                *(u8*)(c + 0x6e3) = 2;
                _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x7f, 0x40000000, 0x1000, 0);
                func_ov002_020daa74(c);
                return 1;
            }
        } else {
            *(u8*)(c + 0x6e5) = 0;
        }
        if (*(s16*)((char*)data_0209f4a0 + data_020a0e40 * 0x18) > 0x200) {
            if (*(u8*)(c + 0x70c) == 0) {
                *(u8*)(c + 0x70c) = 1;
                *(s16*)(c + 0x6d4) = *(s16*)(c + 0x6d2);
            } else {
                s16 xv = *(s16*)(c + 0x69c);
                if (xv < 0) xv = -xv;
                s32 r3;
                if (xv < 0x800)
                    r3 = ((*(s16*)(c + 0x6d2) - *(s16*)(c + 0x6d4)) << 10) >> 16;
                else
                    r3 = ((*(s16*)(c + 0x6d2) - *(s16*)(c + 0x6d4)) << 9) >> 16;
                if (r3 < -0x80) r3 = -0x80;
                if (r3 > 0x80) r3 = 0x80;
                *(s16*)(((int)c + 0x69c) & 0xFFFFFFFFFFFFFFFFLL) += r3;
                if (*(s16*)(c + 0x69c) > 0x1000) *(s16*)(c + 0x69c) = 0x1000;
                if (*(s16*)(c + 0x69c) < -0x1000) *(s16*)(c + 0x69c) = -0x1000;
            }
        } else {
            *(u8*)(c + 0x70c) = 0;
            _Z15ApproachLinear2Rsss((s16*)(((int)c + 0x69c) & 0xFFFFFFFFFFFFFFFFLL), 0, 0x40);
        }
        {
            s16 before = *(s16*)(c + 0x8e);
            *(s16*)(((int)c + 0x8e) & 0xFFFFFFFFFFFFFFFFLL) += *(s16*)(c + 0x69c);
            if ((*(s16*)(c + 0x69c) <= -0x100 && before < *(s16*)(c + 0x8e)) ||
                (*(s16*)(c + 0x69c) >= 0x100 && before > *(s16*)(c + 0x8e)))
                func_02012694(0xb4, c + 0x74);
            s16 sp = *(s16*)(c + 0x69c);
            if (sp >= 0)
                *(s16*)(c + 0x8c) = -sp;
            else
                *(s16*)(c + 0x8c) = sp;
        }
        break;
    case 2:
        if (_ZN6Player12FinishedAnimEv(c))
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_02110154);
        break;
    }

    func_ov002_020bedd4(c);
    return 1;
}
