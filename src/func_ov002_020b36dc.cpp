//cpp
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31(); // offset 0x7c
    char pad[8];
    unsigned short kind; // 0xc relative... need check
};

extern "C" void func_ov002_020b36dc(Obj* self, struct Msg* msg);
struct Msg { char pad[8]; int code; };

extern "C" void func_ov002_020b36dc(Obj* self, Msg* msg)
{
    int t = (self->kind == 0x2e) ? 1 : 0;
    if (t) {
        self->v31();
    }
    int code = msg->code;
    if (code == 3) return;
    int u = (self->kind == 0x11) ? 1 : 0;
    if (u) {
        if (code != 2) return;
        self->v31();
        return;
    }
    self->v31();
}
