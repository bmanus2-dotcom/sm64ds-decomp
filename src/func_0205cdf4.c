typedef unsigned int u32;

struct Node {
    char pad0[8];
    void* pool;
    u32 flags;
    int field10;
    int field14;
    char pad18[8];
};

struct PoolEntry {
    char pad0[0x10];
    u32 field10;
    char pad14[4];
    struct Node* field18;
    char pad1c[0x48 - 0x1c];
    void (*fn48)(struct Node*, int);
    u32 field4c;
};

extern u32 func_02059d1c(void);
extern void func_02059d30(u32);
extern void func_0205c788(struct Node* self, int arg);
extern void func_0205d8d8(struct Node* node, int list);
extern void func_0205cfa4(struct Node* self);
extern int func_0205cf5c(struct Node* self);
extern void func_020580f0(int* p);

int func_0205cdf4(struct Node* self, int arg)
{
    struct PoolEntry* r6;
    u32 r4;
    u32 r5;
    u32* r2;
    u32 r0;
    u32 r1;

    r6 = (struct PoolEntry*)self->pool;
    self->field10 = arg;
    self->field14 = 2;
    r5 = 1u << arg;
    r2 = &self->flags;
    r0 = *r2;
    r0 |= 1u;
    *r2 = r0;
    r4 = func_02059d1c();

    r1 = r6->field10;
    if ((r1 & 0x80u) != 0) {
        func_0205c788(self, 3);
        func_02059d30(r4);
        return 0;
    }

    if ((r5 & 0x1fcu) != 0) {
        r0 = *r2;
        r0 |= 4u;
        *r2 = r0;
    }

    func_0205d8d8(self, (int)r6 + 0x14);

    r0 = r6->field10;
    r0 &= 0x10u;
    if (r0 != 0)
        goto L_cefc;

    r1 = r6->field10;
    r1 |= 0x10u;
    r6->field10 = r1;
    func_02059d30(r4);

    r0 = r6->field4c;
    if ((r0 & 0x200u) != 0)
        r6->fn48(self, 9);

    r0 = self->flags;
    r0 &= 4u;
    if (r0 != 0) {
        func_0205cfa4(self);
        return 1;
    }

L_cefc:
    r0 = self->flags;
    r0 &= 4u;
    if (r0 != 0) {
        func_02059d30(r4);
        return 1;
    }

    func_020580f0((int*)self + 6);
    r0 = (u32)r6->field18;
    if ((u32)self != r0) {
        func_02059d30(r4);
        return 1;
    }

    func_02059d30(r4);
    return func_0205cf5c(self);
}