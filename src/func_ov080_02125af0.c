// NONMATCHING: register allocation (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

void func_ov080_02125af0(void *thiz)
{
    unsigned char *c = (unsigned char *)thiz;
    int i;
    int idx;
    int cnt = *(u16 *)((c + 0x100) + 0xb8);

    i = 0;
    if (cnt <= 0) return;

    idx = i;
    do {
        char *base = (char *)*(int **)(c + 0x1a0);
        int v = *(int *)(base + idx);
        if (v != 0) {
            u32 t = *(u32 *)(c + 8);
            int a = ((u8)(t & 0xf) + 1) * 0x64000;
            if (v != a) {
                int v2 = *(int *)(base + idx + 4);
                if (v2 != 0) {
                    int b = ((u8)((t >> 4) & 0xf) + 1) * 0x64000;
                    if (v2 != b) goto next;
                }
            }
        }
        *(int *)(base + idx + 8) = 0;
        {
            char *base2 = (char *)*(int **)(c + 0x1a0);
            *(int *)(base2 + idx + 0x10) = 0x1ff00000;
        }
    next:
        i++;
        idx += 0x18;
    } while (i < *(u16 *)((c + 0x100) + 0xb8));
}
