typedef unsigned char u8;
struct Arg { void *m[3]; };

extern int func_ov002_020b66a8(u8 *self, struct Arg *arg);
extern struct Arg data_ov047_02112334;

int func_ov047_02111370(u8 *self)
{
    return func_ov002_020b66a8(self, &data_ov047_02112334);
}
