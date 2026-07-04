// NONMATCHING: base materialization / addressing (div=7). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;

typedef struct {
    u8 pad0[0x8c];
    s16 unk8C;              /* 0x08c */
    u8 pad8E[0x322];
    s32 unk3B0;             /* 0x3b0 */
    s32 unk3B4;             /* 0x3b4 */
    u8 pad3B8[0x48];
    volatile u8 unk400;     /* 0x400 */
    u8 pad401[0xa];
    u8 unk40B;              /* 0x40b */
} Obj;

extern s16 SINE_TABLE[];

void func_ov079_02124638(Obj* obj)
{
    u8 old = obj->unk400;

    obj->unk400--;
    if (old != 0) {
        u32 t = obj->unk400;

        if (t <= 0x50) {
            obj->unk8C = 0;
            return;
        }
        obj->unk8C = ((s64)(s32)((t - 0x50) << 6)
                      * SINE_TABLE[((u16)(s16)(t << 13) >> 4) * 2]
                      + 0x800) >> 12;
        return;
    }
    obj->unk3B0 = obj->unk3B4;
    if (obj->unk3B0 == 7) {
        obj->unk3B4 = 10;
    }
    obj->unk40B = 0;
}
