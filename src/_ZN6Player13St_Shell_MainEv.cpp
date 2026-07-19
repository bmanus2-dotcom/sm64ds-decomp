//cpp
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;
typedef s32 Fix12;

extern "C" {
extern int func_02035638(u8* p);
extern int func_0203564c(int p);
extern int _ZNK10ClsnResult9GetClsnIDEv(void* c);
extern void* _ZN5Actor10FindWithIDEj(u32 id);
extern void func_ov002_020eeca8(void* c, int arg);
extern int _ZNK12WithMeshClsn8IsOnWallEv(void* c);
extern int _ZN4cstd5atan2E5Fix12IiES1_(int a, int b);
extern int AngleDiff(int a, int b);
extern void* _ZNK12WithMeshClsn13GetWallResultEv(void* c);
extern int func_02037e58(u32* p);
extern void func_ov002_020c1eb4(void* self, int dmg);
extern void ApproachAngle(short* cur, short target, int divisor, int band, int maxStep);
extern void func_ov002_020cc660(char* self, int angle);
extern void _Z14ApproachLinearRiii(int* a, int b, int c);
extern int func_ov002_020c04e0(char* c);
extern void func_ov002_020e25f0(char* c, int a);
extern int func_ov002_020d674c(char* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* s);
extern void func_ov002_020e28d4(char* c, int a, int b);
extern int _ZN6Player12FinishedAnimEv(void* c);
extern int _ZN6Player6IsAnimEj(void* c, u32 anim);
extern void _ZN6Player7SetAnimEji5Fix12IiEj(void* c, u32 anim, int a, Fix12 b, u32 d);
extern void func_ov002_020bedd4(char* c);

extern u8 data_020a0e40;
extern s16 data_0209f4a0[];
extern u16 data_0209f49e[];
extern u16 data_0209f49c[];
extern int data_ov002_0211004c[];
extern int data_ov002_021104e4[];
}

extern "C" int _ZN6Player13St_Shell_MainEv(char* c)
{
    int flag = 0;
    void* res;

    if (func_02035638((u8*)(c + 0x380))) {
        flag = 1;
        res = (void*)func_0203564c((int)(c + 0x380));
        if (_ZNK10ClsnResult9GetClsnIDEv(res) != -1) {
            void* a = _ZN5Actor10FindWithIDEj((u32)_ZNK10ClsnResult9GetClsnIDEv(res));
            if (a) {
                u16 type = *(u16*)((char*)a + 0xc);
                if ((type == 0x14 ? flag : 0) || (type == 0x15 ? 1 : 0)) {
                    func_ov002_020eeca8((void*)(c + 0x380), (int)c);
                    flag = 0;
                }
            }
        }
    }

    if (_ZNK12WithMeshClsn8IsOnWallEv((void*)(c + 0x380))) {
        int ang = _ZN4cstd5atan2E5Fix12IiES1_(*(int*)(c + 0x560), *(int*)(c + 0x568));
        if (AngleDiff(ang, *(s16*)(c + 0x94)) > 0x6000) {
            if (func_02037e58((u32*)((char*)_ZNK12WithMeshClsn13GetWallResultEv((void*)(c + 0x380)) + 4)) != 1) {
                flag = 1;
            }
        }
    }

    if (flag) {
        func_ov002_020c1eb4(c, (s16)(*(s16*)(c + 0x8e) + 0x8000));
        return 1;
    }

    if (*(u8*)(c + 0x6e3) == 0) {
        s16 target;
        int accel;
        if (*(s16*)((char*)data_0209f4a0 + data_020a0e40 * 0x18) != 0) {
            target = *(s16*)(c + 0x6d2);
            accel = 0x40000;
        } else {
            target = *(s16*)(c + 0x8e);
            accel = 0x18000;
        }
        s16 angleSave = *(s16*)(c + 0x94);
        ApproachAngle((short*)(c + 0x94), target, 8, 0x800, 0x100);
        *(s16*)(c + 0x8e) = *(s16*)(c + 0x94);
        func_ov002_020cc660(c, angleSave);
        {
            int spd = *(int*)(c + 0x98);
            int step = 0x1100;
            if (spd > 0) step = 0x600;
            _Z14ApproachLinearRiii((int*)(c + 0x98), accel, step);
        }
        func_ov002_020c04e0(c);
        if (*(u8*)(c + 0x6de) != 0) {
            (*(u8*)(((long long)(int)(c + 0x6e3)) & 0xFFFFFFFFFFFFFFFFLL))++;
            *(u8*)(c + 0x6de) = 1;
            *(u8*)(c + 0x6df) = 0;
        }
        {
            int off = data_020a0e40 * 0x18;
            if (*(u16*)((char*)data_0209f49e + off) & 2) {
                (*(u8*)(((long long)(int)(c + 0x6e3)) & 0xFFFFFFFFFFFFFFFFLL))++;
                *(int*)(c + 0xa8) = (*(int*)(c + 0x98) >> 2) + 0x2a000;
                *(u8*)(c + 0x6de) = 1;
                *(u8*)(c + 0x6df) = 0;
                func_ov002_020e25f0(c, 0);
                return 1;
            } else if (*(u16*)((char*)data_0209f49c + off) & 0x400) {
                if (func_ov002_020d674c(c)) {
                    _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211004c);
                } else {
                    *(u8*)(c + 0x6e3) = 0;
                    _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_021104e4);
                }
                return 1;
            }
        }
    } else {
        if (*(u8*)(c + 0x6de) == 0) {
            *(u8*)(c + 0x6e3) = 0;
            *(s16*)(c + 0x766) = 0x1000;
            *(s16*)(c + 0x760) = *(s16*)(c + 0x766);
        } else {
            *(s16*)(c + 0x766) = 0;
            *(s16*)(c + 0x760) = *(s16*)(c + 0x766);
            func_ov002_020e28d4(c, 0x1800, 0x800);
            *(int*)(c + 0x9c) = -0x4000;
            *(int*)(c + 0xa0) = -0x4b000;
            if (*(int*)(c + 0xa8) >= 0) {
                *(int*)(c + 0x9c) = -0x8000;
                if (*(u16*)((char*)data_0209f49c + data_020a0e40 * 0x18) & 2) {
                    *(int*)(c + 0x9c) = -0x3400;
                }
            } else {
                if ((*(u16*)((char*)data_0209f49c + data_020a0e40 * 0x18) & 2) && *(u8*)(c + 0x6ff) != 0) {
                    *(int*)(c + 0x9c) = -0x2000;
                    *(int*)(c + 0xa0) = -0x25800;
                }
            }
        }
    }

    if (_ZN6Player12FinishedAnimEv(c) && _ZN6Player6IsAnimEj(c, 0x35)) {
        _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x34, 0, 0x1000, 0);
    }
    func_ov002_020bedd4(c);
    return 1;
}
