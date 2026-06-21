//cpp
struct Vector3 { int x, y, z; };
struct Vector3_16 { short x, y, z; };

struct Event { static int GetBit(unsigned int); };
struct Actor { static void *Spawn(unsigned int, unsigned int, Vector3 const &, Vector3_16 const *, int, int); };

struct Obj {
    char pad0[0x5c];
    Vector3 v5c;      // 0x5c
    char pad1[0x92 - 0x68];
    Vector3_16 v92;   // 0x92
    char pad2[0xcc - 0x98];
    signed char cc;   // 0xcc
    char pad3[0xd4 - 0xcd];
    unsigned short d4; // 0xd4
    char pad4[0xd8 - 0xd6];
    int d8;           // 0xd8
    unsigned char dc; // 0xdc
};

extern "C" void func_ov102_0214ad14(void *);

extern "C" int func_ov002_020f16ec(Obj *self) {
    if (Event::GetBit(self->dc) && self->d8 == 0) {
        void *a = Actor::Spawn(self->d4, 4, self->v5c, &self->v92, self->cc, -1);
        if (a != 0) {
            func_ov102_0214ad14(a);
        }
    }
    self->d8 = Event::GetBit(self->dc);
    return 1;
}
