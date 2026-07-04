// NONMATCHING: push-set / frame (div=44). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

struct OamAttri { unsigned short attr0, attr1, attr2, attr3; };

extern int func_0203da9c(void);
extern void _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(
    int sub, struct OamAttri *attr, int x, int y, int a, int cc, int fx, int fy, int rot, int mode);
extern void _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiEi(
    int sub, struct OamAttri *attr, int x, int y, int a, int cc, int fx, int mode);
extern void func_ov075_0211621c(char *sl);
extern s32 func_0200f0bc(void);
extern void func_0202048c(void *dst, int a, int b);

extern u8 data_0209b2f0[];
extern struct OamAttri data_ov075_0211cb84;
extern struct OamAttri *data_ov075_0211c9f4[];
extern struct OamAttri *data_ov075_0211c9e0[];

void func_ov075_021184b0(char *sl)
{
    int id;
    u8 *p;
    struct OamAttri *sb;
    int i;

    id = func_0203da9c();

    _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(
        0, &data_ov075_0211cb84, 0x80, 0x20, -1, -1, 0x1000, 0x1000, 0, -1);

    func_ov075_0211621c(sl);

    p = data_0209b2f0 + id;

    if (*p != 0) {
        sb = data_ov075_0211c9f4[func_0200f0bc()];
    } else {
        sb = data_ov075_0211c9e0[func_0200f0bc()];
    }

    i = 0;
    do {
        int fix = (i == *(int *)(sl + 0x26c)) ? 0xe00 : 0x1000;
        _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiEi(1, sb, 0x80, 0x60, -1, -1, fix, 0);
        if (sb->attr3 == 0xffff) break;
        sb++;
        i++;
    } while (1);

    (*(int *)(sl + 0x268))++;
    if (*(int *)(sl + 0x268) >= 3) {
        *(int *)(sl + 0x268) = 0;
        (*(int *)(sl + 0x26c))++;
        if (*(int *)(sl + 0x26c) > i) {
            *(int *)(sl + 0x26c) = 0;
        }
    }

    if (*p != 0) {
        func_0202048c(sl + 0x20c, 0x80, 0x88);
        func_0202048c(sl + 0x1b4, 0x80, 0x88);
    } else {
        func_0202048c(sl + 0x1b4, 0x80, 0x88);
        func_0202048c(sl + 0x238, 0x6c, 0x6e);
        func_0202048c(sl + 0x20c, 0xa6, 0x6e);
    }
    func_0202048c(sl + 0x1e0, 0x80, 0x88);
}
