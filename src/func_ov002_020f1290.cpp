//cpp
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void m(int);
};

extern "C" int func_ov002_020f1290(char *o) {
    if (*(int *)(o + 0x60) > *(int *)(o + 0x320)) {
        Base *bp = (Base *)(o + 0xd4);
        bp->m(0);
    }
    return 1;
}
