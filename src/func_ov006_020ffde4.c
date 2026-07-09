// NONMATCHING: dual-path coin/star counter (div~12, 0x164 vs 0x170); sibling func_ov006_020fff54
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 data_ov006_0212ebe0[];
extern u8 data_ov006_0212ebd8[];
extern u16 data_ov006_0212ecac[];
extern u16 *data_ov006_0213daa4[];

extern void func_ov006_020ff534(char *base, int i);

void func_ov006_020ffde4(char *base, int i)
{
    int off;
    char *slot;
    u16 cnt;
    u8 lvl;
    u8 need;

    off = i << 5;
    slot = base + off + 0x5000;
    if (*(u8 *)(slot + 0x63b) != 0) {
        cnt = *(u16 *)(base + 0x5630 + off);
        *(u16 *)(base + 0x5630 + off) = cnt + 1;
        lvl = *(u8 *)(slot + 0x638);
        need = data_ov006_0212ebe0[lvl];
        if (*(u16 *)(base + off + 0x5630) >= need) {
            *(u16 *)(base + off + 0x5630) = 0;
            (*(u8 *)(base + 0x5638 + off))++;
            if (*(u8 *)(slot + 0x638) >= 8) {
                *(u8 *)(slot + 0x638) = 0;
                if (*(u8 *)(slot + 0x63c) == 0) {
                    *(u8 *)(slot + 0x635) = 4;
                    *(u8 *)(slot + 0x637) = 0x10;
                    return;
                }
                (*(u8 *)(base + 0x563c + off))--;
            }
        }
        lvl = *(u8 *)(slot + 0x638);
        *(u8 *)(slot + 0x637) = data_ov006_0212ebd8[lvl];
        return;
    }
    cnt = *(u16 *)(base + 0x5630 + off);
    *(u16 *)(base + 0x5630 + off) = cnt + 1;
    lvl = *(u8 *)(slot + 0x638);
    need = data_ov006_0212ecac[lvl * 2];
    if (*(u16 *)(base + off + 0x5630) >= need) {
        *(u16 *)(base + off + 0x5630) = 0;
        (*(u8 *)(base + 0x5638 + off))++;
        if (*(u8 *)(slot + 0x638) >= 7) {
            *(u8 *)(slot + 0x638) = 0;
        }
        slot = base + off + 0x5000;
        lvl = *(u8 *)(slot + 0x638);
        *(u8 *)(slot + 0x637) = data_ov006_0213daa4[i][lvl * 2];
    }
    func_ov006_020ff534(base, i);
}