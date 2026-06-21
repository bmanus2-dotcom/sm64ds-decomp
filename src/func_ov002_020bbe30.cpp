//cpp

extern "C" void func_ov002_020bb060(void *self);

struct Sub {
    char pad[0xc8];
    int fc8;     // 0xc8
};

struct Model {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f14(int a);   // vtable slot 5 (0x14)
};

struct Obj {
    char pad0[0xb0];
    int fb0;          // 0xb0
    char pad1[0xd4 - 0xb4];
    Model model_d4;   // 0xd4 (subobject with vtable as first word)
    char pad2[0x590 - 0xd4 - sizeof(Model)];
    unsigned char f590;   // 0x590
    char pad3[0x59c - 0x591];
    Sub *f59c;        // 0x59c
};

extern "C" int func_ov002_020bbe30(Obj *self) {
    if (self->f590) {
        return 1;
    }
    Sub *s = self->f59c;
    if (s != 0) {
        int ok = (self->fb0 & 0x4000) ? 1 : 0;
        if (ok != 0) {
            if (s->fc8 != 0) {
                func_ov002_020bb060(self);
            }
        }
    }
    self->model_d4.f14(0);
    return 1;
}
