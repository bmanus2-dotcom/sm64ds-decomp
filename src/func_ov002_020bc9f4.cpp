//cpp
extern signed char data_0209f2f8;
extern unsigned char data_0209f220;

struct Sub {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);   /* vtable+0x14 */
};

struct Obj {
    char pad8[8];
    unsigned int state;       /* +8 */
    char pad[0xd4 - 0xc];
    Sub sub;                  /* +0xd4 */
    char pad2[0x32e - 0xd8];
    unsigned char f32e;       /* +0x32e */
};

extern "C" int func_ov002_020bc9f4(Obj *self) {
    if (data_0209f2f8 == 6 && data_0209f220 == 1 && (self->state & 0xff) == 1)
        return 1;
    if (self->f32e != 0)
        return 1;
    self->sub.m5(0);
    return 1;
}
