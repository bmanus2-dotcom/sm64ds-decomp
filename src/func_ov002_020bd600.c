/* func_ov002_020bd600 at 0x020bd600
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

extern short ReadUnalignedShort(unsigned char *p);

struct Obj {
    char pad5c[0x5c];
    int f5c;      /* +0x5c */
    int f60;      /* +0x60 */
    int f64;      /* +0x64 */
    char pad8e[0x8e - 0x68];
    short f8e;    /* +0x8e */
    char pad94[0x94 - 0x90];
    short f94;    /* +0x94 */
};

int func_ov002_020bd600(struct Obj *self, unsigned char *p) {
    int f60, f64;
    f64 = ReadUnalignedShort(p + 4) << 12;
    f60 = ReadUnalignedShort(p + 2) << 12;
    self->f5c = ReadUnalignedShort(p) << 12;
    self->f60 = f60;
    self->f64 = f64;
    self->f8e = ReadUnalignedShort(p + 6);
    self->f94 = self->f8e;
    return 1;
}
