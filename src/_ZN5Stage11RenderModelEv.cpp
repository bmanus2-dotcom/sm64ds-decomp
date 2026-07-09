//cpp
// NONMATCHING: size 0x12c vs ROM 0x170 (-0x44); dual flag-toggle loops + vtable tail.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Info {
    char pad[0x14];
    u8 count;
};

struct Inner {
    char pad[0x30];
    u16 f30;
    u8 *f34;
};

struct Slot {
    void *transformer;
    char pad[3];
    u8 flag;
};

struct ModelVTable {
    void *v[5];
    void (*render)(void *);
};

extern Info *data_0209f340;
extern void _ZN18TextureTransformer6UpdateER15ModelComponents(void *, void *);

extern "C" void _ZN5Stage11RenderModelEv(char *self)
{
    char *mc;
    Slot *slot;
    Inner *inner;
    int n;
    int i;

    mc = self + 0x874;
    slot = (Slot *)(self + 0x8bc);
    n = data_0209f340->count;
    i = 0;
    inner = (Inner *)(*(char **)mc + 8);

    while (i < n) {
        if (slot->flag != 0) {
            u16 cnt;
            u8 *idx;
            int j;

            cnt = inner->f30;
            idx = inner->f34;
            j = 0;
            while (j < (int)cnt) {
                char *base;
                u32 *flags;
                u8 id;

                id = idx[j];
                base = *(char **)(mc + 4) + id * 0x30;
                flags = (u32 *)(base + 0x24);
                if ((*flags & 0x1f0000u) == 0x1f0000u)
                    *flags &= ~0x80000000u;
                else
                    *flags |= 0x80000000u;
                j++;
            }
            if (slot->transformer != 0)
                _ZN18TextureTransformer6UpdateER15ModelComponents(slot->transformer, mc);
        } else {
            u16 cnt;
            u8 *idx;
            int j;

            cnt = inner->f30;
            idx = inner->f34;
            j = 0;
            while (j < (int)cnt) {
                char *base;
                u32 *flags;
                u8 id;

                id = idx[j];
                base = *(char **)(mc + 4) + id * 0x30;
                flags = (u32 *)(base + 0x24);
                *flags |= 0x80000000u;
                j++;
            }
        }
        slot = (Slot *)((char *)slot + 0xc);
        inner = (Inner *)((char *)inner + 0x40);
        i++;
    }

    {
        ModelVTable **model;
        model = (ModelVTable **)(self + 0x86c);
        (*model)->render(*model);
    }
}