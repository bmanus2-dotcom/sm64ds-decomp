//cpp
struct Player;
extern "C" int func_ov002_020bf30c(Player *self, int a);
extern "C" void _ZN6Player7SetAnimEji5Fix12IiEj(Player *self, unsigned int id, int b, int c, unsigned int d);

struct Player {
    char pad0[0x98];
    int v98;        // 0x98
    char pad1[0x6de - 0x9c];
    unsigned char b6de;  // 0x6de
    unsigned char b6df;
    unsigned char b6e0;  // 0x6e0
};

extern "C" void func_ov002_020d454c(Player *self) {
    if (self->b6de != 0) return;
    if (self->v98 > func_ov002_020bf30c(self, 0x10000)) {
        self->v98 = func_ov002_020bf30c(self, 0x10000);
    }
    self->b6e0 = 1;
    _ZN6Player7SetAnimEji5Fix12IiEj(self, 0x36, 0x40000000, 0x1000, 0);
}
