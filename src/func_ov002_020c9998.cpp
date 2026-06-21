//cpp
struct Vector3 { int x, y, z; };
struct Vector3_16 { short x, y, z; };

struct Actor {
    static void Spawn(unsigned int, unsigned int, const Vector3 &, const Vector3_16 *, int, int);
};

struct Player {
    char pad[0x5c];
    Vector3 f5c;             /* +0x5c */
    char pad2[0x8c - 0x68];
    Vector3_16 f8c;          /* +0x8c */
    char pad3[0x98 - 0x92];
    int f98;                 /* +0x98 */
    char pad4[0xa8 - 0x9c];
    int fa8;                 /* +0xa8 */
    char pad5[0xcc - 0xac];
    signed char fcc;         /* +0xcc */
    char pad6[0x6e3 - 0xcd];
    unsigned char f6e3;      /* +0x6e3 */
    void SetAnim(unsigned int, int, int, unsigned int);
};

extern "C" void func_ov002_020c9998(Player *self) {
    self->f6e3 = 0x12;
    self->SetAnim(0x92, 0x40000000, 0x1000, 0);
    Actor::Spawn(0xb2, 0xffff, self->f5c, &self->f8c, self->fcc, -1);
    self->f98 = 0;
    self->fa8 = 0;
}
