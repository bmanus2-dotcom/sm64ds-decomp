// NONMATCHING: size/regalloc (div~4 bytes short, 0x164 vs 0x168); sibling func_02033390 scaffolding
typedef unsigned short u16;
typedef unsigned char u8;

extern u8 data_ov006_0213cec0[];
extern u16 data_ov006_0213cdec[];
extern int data_0209d4b8;

extern int RandomIntInternal(int *seed);
extern char *func_02054fb0(void);
extern void MultiStore16(short val, char *dst, int nbytes);

void func_ov006_020f2cb8(char *o)
{
    u16 stage;
    int cap;
    int pick;
    int row;
    int col;
    int tile;
    u16 val;
    char *scr;
    char *chr;

    stage = *(u16 *)(o + 0x5172);
    cap = 0;
    if (stage >= 0x14) {
        cap = 0x14;
    } else if (stage >= 0xa) {
        cap = 0xa;
    }
    pick = (int)data_ov006_0213cec0[cap + ((((RandomIntInternal(&data_0209d4b8) >> 16) & 0x7fff) * 10) >> 15)];
    *(u8 *)(o + 0x545a) = (u8)pick;
    stage = *(u16 *)(o + 0x5174);
    if (stage == 9) {
        *(u8 *)(o + 0x545a) = 1;
    }
    if (stage == 0xe || stage == 0x10 || stage == 0x11 || stage == 0x13) {
        if (*(u8 *)(o + 0x545a) == 3) {
            pick = (((RandomIntInternal(&data_0209d4b8) >> 16) & 0x7fff) * 3) >> 15;
            *(u8 *)(o + 0x545a) = (u8)pick;
        }
    }
    row = 0;
    do {
        chr = func_02054fb0();
        scr = chr + 0x1d8;
        pick = *(u8 *)(o + 0x545a);
        tile = (int)data_ov006_0213cdec[pick] + row;
        col = 0;
        do {
            chr = func_02054fb0();
            val = *(u16 *)(chr + tile * 2);
            MultiStore16((short)val, scr + (row * 0x20 + col) * 2, 2);
            tile++;
            col++;
        } while (col < 8);
        row++;
    } while (row < 8);
}