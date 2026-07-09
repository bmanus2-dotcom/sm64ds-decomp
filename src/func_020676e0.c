// NONMATCHING: case-1 VRAM gate codegen (div=TBD, size -0x5c). Logic draft.
typedef unsigned int u32;

extern void Crash(void);

struct RegionIn0 {
    char pad[0x28];
    u32 base;
    u32 size;
};

struct RegionIn1 {
    char pad[0x38];
    u32 base;
    u32 size;
};

struct RegionOut {
    u32 ptr;
    u32 base;
    u32 size;
    u32 flags;
};

void func_020676e0(void *in, int *tbl, struct RegionOut *dst, u32 *aux)
{
    u32 kind;
    struct RegionIn0 *a0;
    struct RegionIn1 *a1;
    u32 base;
    u32 size;
    u32 end;
    int useAux;

    kind = (u32)*tbl;
    if (kind == 0) {
        a0 = (struct RegionIn0 *)in;
        if (a0->base < 0x2000000u)
            goto do_crash;
        if (a0->base >= 0x22c0000u)
            goto do_crash;
        end = a0->base + a0->size;
        if (end > 0x22c0000u)
            goto do_crash;
        dst->size = a0->size;
        dst->base = a0->base;
        dst->ptr = dst->base;
        dst->flags &= ~1u;
        return;
    }
    if (kind == 1) {
        a1 = (struct RegionIn1 *)in;
        base = a1->base;
        size = a1->size;
        end = base + size;
        useAux = 0;
        if (base >= 0x2000000u) {
            if (base < 0x23fe800u) {
                if (end <= 0x2300000u)
                    goto case1_ok;
                if (end >= 0x23fe800u)
                    goto do_crash;
                if (size <= 0x40000u) {
                    useAux = 1;
                    goto case1_ok;
                }
                goto do_crash;
            }
            goto case1_vram;
        }
case1_vram:
        if (base < 0x37f8000u)
            goto do_crash;
        if (base >= 0x380f000u)
            goto do_crash;
        if (end > 0x380f000u)
            goto do_crash;
        useAux = 1;
case1_ok:
        dst->size = size;
        dst->base = base;
        if (useAux == 0)
            dst->ptr = dst->base;
        else {
            dst->ptr = *aux;
            *aux = *aux + dst->size;
        }
        dst->flags = (dst->flags & ~1u) | 1u;
        return;
    }
    if (kind == 2) {
        dst->size = 0x160;
        dst->base = 0x27ffe00;
        dst->ptr = dst->base;
        dst->flags &= ~1u;
        return;
    }
    return;
do_crash:
    Crash();
}