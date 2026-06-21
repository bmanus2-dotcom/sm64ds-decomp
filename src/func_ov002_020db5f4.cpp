//cpp
struct State {};

struct Arg {
    char pad[0xc];
    unsigned short f0c; // 0xc
};

struct Player {
    char pad[0x35c];
    void *f35c; // 0x35c
    void ChangeState(State &);
};

extern "C" int func_ov002_020d82f0(Player *);
extern State data_ov002_0211016c;

extern "C" int func_ov002_020db5f4(Player *self, Arg *arg) {
    int isbf = (arg->f0c == 0xbf);
    if (!isbf) {
        if (!func_ov002_020d82f0(self))
            return 0;
    }
    if (self->f35c != 0)
        return 0;
    self->f35c = arg;
    self->ChangeState(data_ov002_0211016c);
    return 1;
}
