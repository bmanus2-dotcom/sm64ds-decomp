typedef void (*Fn)(void *self, int a, int b);

struct Obj {
    char pad0[0x3c];
    Fn fn;
};

struct S {
    char pad0[8];
    struct Obj *obj;    /* 0x08 */
    char pad_c[0x1c];
    int f28;            /* 0x28 */
    int f2c;            /* 0x2c */
    char pad30[4];
    int f34;            /* 0x34 */
};

void func_0205c448(struct S *self)
{
    int old = self->f28;
    struct Obj *o = self->obj;
    *(int *)(((long long)(int)((char *)self + 0x28)) & 0xFFFFFFFFFFFFFFFFLL) += self->f34;
    o->fn(o, self->f2c, old);
}
