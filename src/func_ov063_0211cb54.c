// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
typedef unsigned short u16;
struct Obj {
    char pad0[0x64];
    int f64;
    char pad1[0x8c-0x68];
    s16 f8c;
    char pad2[0x124-0x8e];
    struct Obj* f124;
    char pad3[0x138-0x128];
    s16 f138;
    char pad4[0x14c-0x13a];
    u16 f14c;
};
void func_ov063_0211cb54(struct Obj* self)
{
    if (self->f124 != 0) {
        s16* p = &self->f8c;
        self->f138 = (s16)((self->f124->f64 - self->f64) >> 0xc);
        *p = *p + self->f138;
    } else {
        int a = self->f8c;
        if (a < 0) a = -a;
        if (a >= 0xbb8 && self->f14c > 0xf) {
            self->f138 = 0;
            int v = self->f8c;
            if (v > 0) {
                if (v < 0xc8) self->f8c = 0;
                else self->f138 = -0xc8;
            } else {
                if (v > -0xc8) self->f8c = 0;
                else self->f138 = 0xc8;
            }
        }
    }
    self->f8c = self->f8c + self->f138;
}
