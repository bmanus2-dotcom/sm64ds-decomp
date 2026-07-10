//cpp
extern "C" {
extern int data_ov055_02111b68;
extern int data_ov055_02111b6c;
extern int data_ov055_02111b60;
extern int data_ov055_02111a90;
extern int data_ov055_02111b64;
extern int data_0209caa0[];
extern unsigned char data_0209f250;
extern char *data_0209f394[];
extern char *data_0209f318;
extern void _Z14ApproachLinearRiii(int *r, int target, int step);
extern void Matrix4x3_FromTranslation(char *m, int x, int y, int z);
extern void func_ov002_020e4374(char *c, int *p1, int *p2);
extern void _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j(char *a, char *sh, char *m, int height, int rad, unsigned int frames);
}

struct C5;
typedef void (C5::*PMF)(char *);
struct Node {
    int pad0, pad1;
    PMF fn;
};

extern "C" int func_ov055_02111508(char *c)
{
    int a, b;
    int f;
    char *val;
    Node *node;

    f = data_ov055_02111b68;
    if (f & 1) {
        data_ov055_02111b6c = 0;
        data_ov055_02111a90 = 0x1ffff;
        data_ov055_02111b60 = 0;
    } else if ((f & 2) && !(data_0209caa0[1] & 0x10)) {
        _Z14ApproachLinearRiii(&data_ov055_02111b6c, 0x1ffff, 0x400);
        data_ov055_02111b64 = (data_ov055_02111b64 & ~0x20000) + (0x1ffff - data_ov055_02111b6c);
    }
    val = data_0209f394[data_0209f250];
    node = *(Node **)(c + 0x1d8);
    if (*(int *)&node->fn != 0)
        (((C5 *)c)->*node->fn)(val);
    Matrix4x3_FromTranslation(c + 0x1dc, *(int *)(c + 0x5c) >> 3, *(int *)(c + 0x60) >> 3, *(int *)(c + 0x64) >> 3);
    func_ov002_020e4374(val, &a, &b);
    _ZN5Actor19DropShadowRadHeightER11ShadowModelR9Matrix4x35Fix12IiES5_j(c, c + 0x188, c + 0x1dc, b, a, 0xf);
    *(char **)(data_0209f318 + 0x114) = c;
    return 1;
}
