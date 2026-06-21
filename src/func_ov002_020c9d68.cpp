//cpp
struct Player {
    char pad0[0x8e];
    short f8e;       // 0x8e
    char pad1[0x94 - 0x90];
    short f94;       // 0x94
    char pad2[0x98 - 0x96];
    int f98;         // 0x98
    char pad3[0x354 - 0x9c];
    int f354;        // 0x354
    char pad4[0x6d8 - 0x358];
    unsigned char f6d8;  // 0x6d8
    char pad5[0x6de - 0x6d9];
    unsigned char f6de;  // 0x6de
    char pad6[0x6e3 - 0x6df];
    unsigned char f6e3;  // 0x6e3
    char pad7[0x70c - 0x6e4];
    unsigned char f70c;  // 0x70c
    void SetAnim(unsigned int, int, int, unsigned int);
};

extern "C" int GetAngleToCamera(unsigned char);

extern "C" void func_ov002_020c9d68(Player *self) {
    if (self->f6de == 0) {
        int ok = (self->f354 != 0);
        if (!ok)
            goto skip;
    }
    self->SetAnim(0x54, 0x40000000, 0x1000, 0);
skip:;
    self->f8e = (short)GetAngleToCamera(self->f6d8);
    self->f94 = self->f8e;
    self->f6e3 = 0;
    self->f70c = 0;
    self->f98 = 0;
}
