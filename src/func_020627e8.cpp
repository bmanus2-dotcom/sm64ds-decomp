//cpp
// NONMATCHING: IRQ-guarded ring-buffer advance + switch tail (div~999, size 0x19c
// vs 0x1a8). Needs ROM's predicated early-exit and func_020623ec arg setup order.
typedef unsigned short u16;
typedef unsigned char u8;

struct IRQ {
    static unsigned int Disable();
    static void Restore(unsigned int);
};

struct CP15 {
    static void InvalidateDataCache(unsigned int, unsigned int);
};

extern "C" void *func_02061548(void);
extern "C" void MultiStore16(short val, char *dst, int nbytes);
extern "C" int func_020623ec(void *fn, char *dst, u16 a, u16 b, int c, int d);
extern "C" void func_02062d10(void);

extern "C" void func_020627e8(char *base, int arg1)
{
    void *ctx;
    unsigned int saved;
    u16 slot;
    u16 next;
    u16 mask;
    u16 prev;
    u16 newslot;
    int ret;

    ctx = func_02061548();
    saved = IRQ::Disable();
    slot = *(u16 *)(base + 0x408);
    if (*(u16 *)(base + (slot << 8)) != 0) {
        IRQ::Restore(saved);
        return;
    }
    CP15::InvalidateDataCache((unsigned int)(*(int *)((char *)ctx + 4) + 0x86), 2);
    prev = slot;
    next = (slot + 1) % 4;
    mask = *(u16 *)(*(int *)((char *)ctx + 4) + 0x86);
    if (*(u16 *)(base + 0x418) == 1)
        newslot = (next + 1) % 4;
    else
        newslot = next;
    MultiStore16(0, base + (newslot << 8), 0x100);
    *(u16 *)(base + (newslot << 8)) = (*(u16 *)(base + 0x40e) & (mask | 1));
    *(u16 *)(base + 0x408) = next;
    *(u16 *)(base + (prev << 8)) = *(u16 *)(base + 0x40e);
    if (arg1 == 1)
        *(u16 *)(base + (prev << 8)) &= ~1;
    IRQ::Restore(saved);
    ret = func_020623ec((void *)func_02062d10, base + (prev << 8), *(u16 *)(base + 0x414),
                        (u16)(*(u16 *)(base + 0x40e) & mask), *(u16 *)(base + 0x416), 1);
    if (ret == 7) {
        *(u16 *)(base + prev * 2 + 0x400) = 0xffff;
        *(u16 *)(base + 0x40a) = (u16)((*(u16 *)(base + 0x40a) + 1) % 4);
        return;
    }
    if (ret == 0)
        return;
    if (ret == 2)
        return;
    *(u16 *)(base + 0x41c) = 3;
}