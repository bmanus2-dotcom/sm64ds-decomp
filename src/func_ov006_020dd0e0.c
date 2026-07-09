typedef short s16;
typedef unsigned char u8;

extern u8 data_020a0e40;
extern u8 data_020a0de8[];
extern u8 data_020a0de9[];
extern u8 data_020a0dea[];
extern u8 data_020a0deb[];

extern void func_ov006_020dd4b0(char *c, int i);
extern void func_ov006_020dcb1c(char *c, int i);
extern void func_020127a4(int a, int b, int c, int d);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int id);

extern int data_ov000_020beb68;

void func_ov006_020dd0e0(char *self, int idx)
{
    u8 i;
    int ok;
    int n;
    int v;
    int w;
    char *fld;
    int ang;
    int stars;
    int need;

    if (*(int *)(self + 0x5000 + 0x1c8) != 2)
        return;

    i = data_020a0e40;
    ok = 0;
    if (data_020a0de8[i * 4] != 0) {
        int t;
        t = data_020a0de9[i * 4] != 0;
        if (t)
            ok = 1;
    }
    if (ok == 0)
        return;

    n = idx * 0x18;
    v = data_020a0dea[i * 4] - (*(int *)(self + 0x4ac0 + n) >> 12);
    w = data_020a0deb[i * 4] - (*(int *)(self + 0x4ac4 + n) >> 12);

    if (v <= -0x10)
        return;
    if (v >= 0x10)
        return;
    if (w <= -0x10)
        return;
    if (w >= 0x10)
        return;

    fld = self + n + 0x4000;
    *(u8 *)(fld + 0xad5) = 1;
    if (*(u8 *)(fld + 0xad3) != 0) {
        *(u8 *)(fld + 0xad0) = 1;
        *(int *)(fld + 0xac8) = *(int *)(self + 0x4ac4 + n);
        *(int *)(fld + 0xacc) = -0x3000;
        *(u8 *)(fld + 0xad6) = 0;
        func_ov006_020dd4b0(self, idx);
        return;
    }

    func_ov006_020dcb1c(self, idx);
    *(u8 *)(fld + 0xad2) = 0;
    *(int *)(self + 0x5000 + 0x1c8) = 3;
    *(int *)(self + 0x5000 + 0x1cc) = 0x40;

    ang = (*(int *)(self + 0x4ac0 + n) >> 12) - 0x80;
    ang >>= 1;
    if (ang >= 0x3c)
        ang = 0x3c;
    if (ang <= -0x3c)
        ang = -0x3c;
    func_020127a4(2, 0xee, 0xffff, ang);
    _ZN5Sound12PlayBank2_2DEj(0xf2);

    *(u8 *)(fld + 0xad0) = 2;
    stars = 0;
    if (*(int *)data_ov000_020beb68 != 0)
        stars = *(int *)(*(int *)data_ov000_020beb68 + 0xa8);
    need = *(int *)(self + 0x5000 + 0x1d4);
    if (stars > need)
        *(u8 *)(self + 0x5000 + 0x1db) = 1;
    else
        *(u8 *)(self + 0x5000 + 0x1db) = 0;
}