// NONMATCHING: epilogue/predicated-return shape (div~20, 0x194 vs 0x1a8); atan2+fix12 sin table sibling pair
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;

extern s16 data_02082214[];
extern int data_ov006_0213d09c[];

extern s16 _ZN4cstd5atan2E5Fix12IiES1_(int y, int x);

void func_ov006_020f43c4(char *sl, int idx)
{
    int n;
    int i2;
    u8 kind;
    u16 *tbl;
    s16 tx;
    s16 tz;
    int cx;
    int cz;
    int dx;
    int dy;
    s16 ang;
    int spd;
    int add;
    char *xa;
    char *za;
    char *spdp;
    char *angp;

    n = idx * 0x18;
    i2 = idx * 2;
    kind = *(u8 *)(sl + 0x533c);
    tbl = (u16 *)data_ov006_0213d09c[kind];
    tx = tbl[i2];
    tz = tbl[i2 + 1];
    xa = sl + 0x51a8;
    za = sl + 0x51ac;
    cx = *(int *)(xa + n);
    cz = *(int *)(za + n);
    dx = tx - (cx >> 12);
    dy = tz - (cz >> 12);
    angp = sl + 0x51b4;
    ang = _ZN4cstd5atan2E5Fix12IiES1_(dx, dy);
    *(s16 *)(angp + n) = ang;
    spdp = sl + 0x51b0;
    spd = *(int *)(spdp + n);
    add = (int)(((s64)data_02082214[((ang >> 4) * 2) + 1] * spd + 0x800) >> 12);
    *(int *)(xa + n) = cx + add;
    add = (int)(((s64)data_02082214[((ang >> 4) * 2)] * *(int *)(spdp + n) + 0x800) >> 12);
    *(int *)(za + n) = cz + add;
    if (dx < -6) {
        return;
    }
    if (dx > 6) {
        return;
    }
    if (dy < -6) {
        return;
    }
    if (dy > 6) {
        return;
    }
    *(int *)(xa + n) = tx << 12;
    *(int *)(za + n) = tz << 12;
    *(u8 *)(sl + 0x51bc + n) = 1;
}