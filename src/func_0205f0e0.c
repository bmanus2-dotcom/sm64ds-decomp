// NONMATCHING: different op / idiom (div=30). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

extern u32  _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(u32 state);

typedef struct {
    char pad18[0x18];
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    s16 field_30;
} Glob;

extern Glob data_020a80cc;

void func_0205f0e0(s16 *arg)
{
    u32 state;
    int v;

    if (arg == 0) {
        data_020a80cc.field_30 = 0;
        return;
    }

    state = _ZN3IRQ7DisableEv();

    v = arg[2];
    *(volatile u16 *)0x4000280 = 0;
    *(volatile u32 *)0x4000290 = 0x10000000;
    *(volatile u32 *)0x4000298 = v;
    *(volatile u32 *)(0x4000298 + 4) = 0;
    data_020a80cc.field_18 = arg[0];
    data_020a80cc.field_1c = arg[2];
    while (*(volatile u16 *)0x4000280 & 0x8000) {
    }

    data_020a80cc.field_20 = *(volatile u32 *)0x40002a0;
    v = arg[3];
    *(volatile u16 *)0x4000280 = 0;
    *(volatile u32 *)0x4000290 = 0x10000000;
    *(volatile u32 *)0x4000298 = v;
    *(volatile u32 *)(0x4000298 + 4) = 0;
    data_020a80cc.field_24 = arg[1];
    data_020a80cc.field_28 = arg[3];
    while (*(volatile u16 *)0x4000280 & 0x8000) {
    }
    data_020a80cc.field_2c = *(volatile u32 *)0x40002a0;

    _ZN3IRQ7RestoreEj(state);
    data_020a80cc.field_30 = 1;
}
