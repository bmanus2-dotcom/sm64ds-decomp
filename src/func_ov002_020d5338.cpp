//cpp
struct State;
struct Player {
    bool IsState(State &);
    void ChangeState(State &);
};
extern "C" {
extern State data_ov002_02110304;
extern State data_ov002_02110484;
extern State data_ov002_021100f4;

int func_ov002_020d5338(Player *self)
{
    if (self->IsState(data_ov002_02110304) ||
        self->IsState(data_ov002_02110484) ||
        *(unsigned char *)((char *)self + 0x6f9) ||
        *(unsigned char *)((char *)self + 0x709))
        return 0;
    self->ChangeState(data_ov002_021100f4);
    return 1;
}
}
