//cpp
extern "C" int func_ov002_020f63a0(char *r0);
extern "C" int func_ov002_020f23d0(void *c);

struct Sub {
    virtual void v0();
    virtual void v1();   // vtable+4
};

struct Obj {
    char pad0[8];
    int kind;       // 0x8
    char pad1[0xdc - 0xc];
    Sub *a;         // 0xdc
    Sub *b;         // 0xe0
};

extern "C" int func_ov002_020f8028(Obj *self) {
    if (self->kind == 0x2e) {
        return func_ov002_020f63a0((char *)self);
    }
    if (self->kind == 0x2f) {
        return func_ov002_020f23d0(self);
    }
    Sub *pa = self->a;
    if (pa != 0 && pa != 0) {
        pa->v1();
    }
    Sub *pb = self->b;
    if (pb != 0 && pb != 0) {
        pb->v1();
    }
    return 1;
}
