//cpp
struct Player;
extern "C" int _ZN6Player16IsInsideOfCannonEv(Player *self);

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a);   // vtable+0x14
};

struct Player {
    char pad0[0xb0];
    unsigned int flags;     // 0xb0
    char pad1[0x300 - 0xb4];
    Sub sub;                // 0x300 (embedded)
    char pad2[0x38c - 0x304];
    Player *other;          // 0x38c
};

extern "C" int func_ov002_020edf98(Player *self) {
    int inAir = (self->flags & 0x40000) ? 1 : 0;
    if (inAir != 0) return 1;
    if (_ZN6Player16IsInsideOfCannonEv(self->other) != 0) return 1;
    if (*(unsigned char *)((char *)self->other + 0x6f5) < 1) return 1;
    self->sub.v5(0);
    return 1;
}
