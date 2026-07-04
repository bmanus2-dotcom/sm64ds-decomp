//cpp
// NONMATCHING: different op / idiom (div=27). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" void _ZN3G2x13SetBlendAlphaEPVttttt(volatile void *p, u16 a, u16 b, u16 c, u16 d);
extern "C" void func_ov006_020cad3c(int a);
extern "C" void func_ov006_020cac9c(void);
extern "C" void func_ov006_020d0b04(void);
extern "C" void func_ov006_020cee5c(void);
extern "C" void func_ov006_020eeff0(void);
extern "C" void func_ov006_02122b24(void);
extern "C" void func_ov006_02120ca0(void);
extern "C" s32 func_ov004_020ad674(void);
extern "C" void func_ov006_020c8a9c(int a0, int a1);
extern "C" int func_02054d88(void);
extern "C" void MultiStore16(s16 val, char *dst, int nbytes);
extern "C" void func_ov006_02124228(int self);

extern volatile s16 data_020a0dbc[];
extern int data_ov006_021405bc;
extern int data_ov006_0213fc20[];

extern "C" void func_ov006_021242cc(int self)
{

    _ZN3G2x13SetBlendAlphaEPVttttt((volatile void *)0x4000050, 1, 0x2e, 0x10, 0x10);

    *(s16 *)(self + 0x7b00 + 0xa0) = data_020a0dbc[0];
    *(s16 *)(self + 0x7b00 + 0xa2) = data_020a0dbc[1];
    *(s16 *)(self + 0x7b00 + 0x9c) = data_020a0dbc[0];
    *(s16 *)(self + 0x7b00 + 0x9e) = data_020a0dbc[1];

    *(u32 *)(self + 0xbc) = 0;
    if (*(u32 *)(self + 0xbc) > 0x270e)
        *(u32 *)(self + 0xbc) = 0x270e;

    func_ov006_020cad3c(0x1000);
    func_ov006_020cac9c();
    data_ov006_021405bc = 1;
    func_ov006_020d0b04();
    func_ov006_020cee5c();
    func_ov006_020eeff0();
    func_ov006_02122b24();
    func_ov006_02120ca0();
    func_ov006_020c8a9c(0, data_ov006_0213fc20[func_ov004_020ad674()]);

    *(s16 *)(self + 0x7b00 + 0xa4) = 0;
    *(s16 *)(self + 0x7b00 + 0xa8) = 0;
    *(s32 *)(self + 0x7000 + 0xb88) = 0;
    *(s32 *)(self + 0x7000 + 0xb94) = 0;
    *(s32 *)(self + 0x7000 + 0xb98) = 0;
    *(s32 *)(self + 0x7000 + 0xac8) = 0x14000;

    {
        u16 z = 0;
        MultiStore16(z, (char *)func_02054d88(), 0x6000);
    }

    func_ov006_02124228(self);
}
