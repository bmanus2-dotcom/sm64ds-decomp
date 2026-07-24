//cpp
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern "C" int func_ov002_020beb38(char* c);
extern "C" void func_ov002_020db54c(char* self, int a, int b, int c);
extern "C" void func_ov002_020bedd4(char* self);
extern "C" void _ZN6Player9DropActorEv(char* a);
extern "C" unsigned int _ZNK6Player14GetBodyModelIDEjb(char* self, unsigned int a, int b);

extern "C" int _ZN6Player15St_Grabbed_MainEv(char* self)
{
    char* grab;
    u8* p;
    unsigned int id;
    int ret;
    volatile int* pRate;
    char* model;

    *(int*)(self + 0x684) = *(int*)(self + 0x60);
    grab = *(char**)(self + 0x35c);
    if (grab != 0) {
        int isBob = (*(u16*)(grab + 0xc) == 0xbf);
        if (isBob != 0) {
            ret = func_ov002_020beb38(self);
            if (ret != 0) {
                p = (u8*)(int)(((long long)(int)(self + 0x6e3)) & 0xFFFFFFFFFFFFFFFFLL);
                *p = (u8)(*p + ret);
                *(u16*)(self + 0x6a4) = 6;
                if ((s16)(*(u8*)(self + 0x6e3) - ret) < 0) {
                    _ZN6Player9DropActorEv(*(char**)(self + 0x35c));
                    func_ov002_020db54c(self, 0x10000, 0x10000, *(s16*)(self + 0x8e));
                    return 1;
                }
            }
        }
    }

    if (*(u16*)(self + 0x6a4) != 0) {
        id = _ZNK6Player14GetBodyModelIDEjb(self, *(unsigned int*)(self + 8) & 0xff, 0);
        model = *(char**)(self + (id << 2) + 0xdc);
        pRate = (int*)(model + 0x50);
        pRate = (int*)((char*)pRate + 0xc);
        *pRate = 0x4000;
    } else {
        id = _ZNK6Player14GetBodyModelIDEjb(self, *(unsigned int*)(self + 8) & 0xff, 0);
        model = *(char**)(self + (id << 2) + 0xdc);
        pRate = (int*)(model + 0x50);
        pRate = (int*)((char*)pRate + 0xc);
        *pRate = 0x1000;
    }
    func_ov002_020bedd4(self);
    return 1;
}
