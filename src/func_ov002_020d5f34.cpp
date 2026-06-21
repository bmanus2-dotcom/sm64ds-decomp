//cpp
struct State;
extern State data_ov002_02110064;

struct Player {
    char pad[0xd0];
    int fd0;                 /* +0xd0 */
    char pad2[0x6e3 - 0xd4];
    unsigned char f6e3;      /* +0x6e3 */
    void SetAnim(unsigned int, int, int, unsigned int);
    void ChangeState(State &);
};

extern "C" int func_ov002_020d5f34(Player *self, int anim) {
    if (self->fd0 != 0) return 0;
    self->fd0 = anim;
    self->SetAnim(0x3f, 0, 0x3000, 0);
    self->f6e3 = 0;
    self->ChangeState(data_ov002_02110064);
    return 1;
}
