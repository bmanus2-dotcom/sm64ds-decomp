typedef unsigned char u8;
struct Arg { void *m[3]; };

extern int func_ov002_020b6c54(u8 *self, struct Arg *arg, unsigned int actorID);
extern struct Arg data_ov047_02112258;

int func_ov047_02111268(u8 *self)
{
    return func_ov002_020b6c54(self, &data_ov047_02112258, 0x97);
}
