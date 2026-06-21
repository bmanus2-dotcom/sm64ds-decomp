/* func_ov002_020f57c0 at 0x020f57c0
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern int data_ov002_02100170[];

struct Elem {
    char pad8[8];
    int f8;            /* +0x08 */
    int fc;            /* +0x0c */
    char pad30[0x30 - 0x10];
    unsigned short f30; /* +0x30 */
    unsigned short f32; /* +0x32 */
    char pad3a[0x3a - 0x34];
    unsigned short f3a; /* +0x3a */
    char pad45[0x45 - 0x3c];
    unsigned char f45;  /* +0x45 */
    char pad47[0x47 - 0x46];
    unsigned char f47;  /* +0x47 */
    char pad49[0x49 - 0x48];
    unsigned char f49;  /* +0x49 */
};

void func_ov002_020f57c0(struct Elem *base, int idx) {
    int off = idx * 0x4c;
    struct Elem *e = (struct Elem *)((char *)base + off);
    unsigned char *b47;
    if (e->f3a != 0) return;
    if (e->f32 != 0) return;
    e->f49 = 1;
    e->f45 = 1;
    b47 = (unsigned char *)base + 0x47;
    b47[off] = b47[off] + 1;
    e->f8 = data_ov002_02100170[idx * 2];
    e->fc = data_ov002_02100170[idx * 2 + 1];
    if (idx == 0) e->f30 = 0x78;
    else e->f30 = 0x20;
}
