//cpp
// NONMATCHING: base materialization / addressing (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
    int _ZN3IRQ7DisableEv(void);
    void _ZN3IRQ7RestoreEj(unsigned int);
    void func_020580f0(void *p);
}

struct Obj;
typedef int (*M44)(Obj *self, int a, int b, int c);
struct Obj {
    int f0, f4, f8, fc, f10;
    int pad[12];
    M44 m44;
};
struct Outer {
    Obj *obj;
    int f4;
};

extern "C" void func_0205c528(Outer *thiz, int r1, int r7)
{
    Obj *o = thiz->obj;
    int res;
    o->f10 |= 0x200;
    res = o->m44(o, r1, thiz->f4, r7);
    if (res == 0) goto clr;
    if (res == 1) goto clr;
    if (res == 6) {
        unsigned int saved = (unsigned int)_ZN3IRQ7DisableEv();
        int loop;
        do {
            func_020580f0(&o->fc);
            loop = (o->f10 & 0x200) ? 1 : 0;
        } while (loop);
        _ZN3IRQ7RestoreEj(saved);
    }
    goto end;
clr:
    o->f10 &= ~0x200;
end:
    thiz->f4 += r7;
}
