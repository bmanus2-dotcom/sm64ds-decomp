// NONMATCHING: base materialization / addressing (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
typedef unsigned char u8;

struct Actor { char pad[0xd4]; u8 flags; };

extern struct Actor* _ZN5Actor10FindWithIDEj(u32 id);

void func_ov064_02118ee4(void *thiz)
{
    unsigned char *c = (unsigned char *)thiz;
    struct Actor *a;

    if (*(u8 *)(c + 0x338) != 0 && *(u32 *)(c + 0x320) != 0) {
        a = _ZN5Actor10FindWithIDEj(*(u32 *)(c + 0x320));
        if (a) a->flags = 1;
    }

    if (*(u8 *)(c + 0x339) != 0) return;

    u8 idx = *(u8 *)(c + 0x328);
    u8 *p = c + 0x328;
    *(signed char *)(c + 0x336) = ((signed char *)(*(u32 *)(c + 0x324)))[idx];
    *p = *p + 1;

    if (((signed char *)(*(u32 *)(c + 0x324)))[*(u8 *)(c + 0x328)] == -1) {
        *(u8 *)(c + 0x328) = 0;
        if (*(u32 *)(c + 0x320) != 0) {
            a = _ZN5Actor10FindWithIDEj(*(u32 *)(c + 0x320));
            if (a) a->flags |= 2;
        }
    }

    *(u8 *)(c + 0x339) = 1;
    *(unsigned short *)((c + 0x300) + 0x34) = 0;
}
