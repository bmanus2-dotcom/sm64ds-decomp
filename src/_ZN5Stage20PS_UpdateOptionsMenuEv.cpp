//cpp
// NONMATCHING: loop/register scheduling (div~999, size 0x1d0 vs 0x1e8). BG tile
// highlight loops; needs do-while shape + per-loop GetBG1ScrPtr rematerialization.
typedef unsigned short u16;
typedef unsigned char u8;

namespace G2S { u16 *GetBG1ScrPtr(); }

extern u16 data_020755c0[];
extern u16 data_020755c4[];
extern u8 data_0209f2cc;
extern u8 data_0209f2e0;
extern u8 data_0209f2e4;
extern u8 data_0209f2ec;

struct Stage {
    static void PS_UpdateOptionsMenu();
};

void Stage::PS_UpdateOptionsMenu()
{
    u16 sl;
    u16 *scr;
    int i;
    int j;

    if (data_0209f2e4 != 0)
        sl = 0x5000;
    else
        sl = 0x6000;
    scr = G2S::GetBG1ScrPtr() + 0xae;
    for (j = 0; j < 0xf; j++) {
        scr[0] = (scr[0] & 0x3ff) | sl;
        scr[0x20] = (scr[0x20] & 0x3ff) | sl;
        scr[0x40] = (scr[0x40] & 0x3ff) | sl;
        scr[0x60] = (scr[0x60] & 0x3ff) | sl;
        scr++;
    }
    for (i = 0; i < 2; i++) {
        u16 v;
        if (data_0209f2e0 == i)
            v = 0x4000;
        else
            v = 0x3000;
        scr = G2S::GetBG1ScrPtr() + data_020755c0[i];
        for (j = 0; j < 0xa; j++) {
            scr[0] = (scr[0] & 0x3ff) | v;
            scr[0x20] = (scr[0x20] & 0x3ff) | v;
            scr++;
        }
    }
    for (i = 0; i < 2; i++) {
        u16 v;
        if (data_0209f2ec == i && data_0209f2cc == 0)
            v = 0x6000;
        else
            v = 0x5000;
        scr = G2S::GetBG1ScrPtr() + data_020755c4[i];
        for (j = 0; j < 7; j++) {
            scr[0] = (scr[0] & 0x3ff) | v;
            scr[0x20] = (scr[0x20] & 0x3ff) | v;
            scr[0x40] = (scr[0x40] & 0x3ff) | v;
            scr[0x60] = (scr[0x60] & 0x3ff) | v;
            scr++;
        }
    }
}