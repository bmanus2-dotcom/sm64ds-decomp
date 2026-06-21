//cpp

struct Camera;
extern Camera *data_0209f318;
extern "C" void func_0200d148(Camera *thiz, unsigned char playerID);

struct Player {
    char pad[0x6d8];
    unsigned char f6d8;        // 0x6d8
    char pad2[0x6e3 - 0x6d9];
    unsigned char f6e3;        // 0x6e3
    char pad3[0x70c - 0x6e4];
    unsigned char f70c;        // 0x70c
    char pad4[0x71a - 0x70d];
    unsigned char f71a;        // 0x71a
    void SetAnim(unsigned int a, int b, int c, unsigned int d);
};

extern "C" void func_ov002_020c98a4(Player *self) {
    self->f71a = 0;
    self->f6e3 = 0x18;
    self->SetAnim(0x47, 0, 0x1000, 0);
    *(short *)((char *)self + 0x6a4) = 2;
    *(int *)((char *)self + 0x98) = 0;
    *(int *)((char *)self + 0xa8) = 0;
    self->f70c = 0;
    func_0200d148(data_0209f318, self->f6d8);
}
