typedef struct Entry {
    int id;
    int ptr;
} Entry;

extern int func_ov004_020ad674(void);
extern int LoadFile(int handle);

extern int data_ov004_020bc42c[];
extern int data_ov004_020bc65c[];
extern int data_ov004_020bc418[];
extern int data_ov004_020bc648[];
extern int data_ov004_020bc3c8[];
extern int data_ov004_020bc5e4[];
extern int data_ov004_020bc4f4[];
extern int data_ov004_020bc300[];
extern int data_ov004_020bc3dc[];
extern int data_ov004_020bc5f8[];
extern int data_ov004_020bc3f0[];
extern int data_ov004_020bc60c[];
extern int data_ov004_020bc404[];
extern int data_ov004_020bc634[];
extern int data_ov004_020bc3b4[];
extern int data_ov004_020bc5bc[];
extern int data_ov004_020bc468[];
extern int data_ov004_020bc6ac[];
extern int data_ov004_020bc454[];
extern int data_ov004_020bc698[];
extern int data_ov004_020bc378[];
extern int data_ov004_020bc594[];
extern int data_ov004_020bc620[];
extern int data_ov004_020bc670[];
extern int data_ov004_020bc440[];
extern int data_ov004_020bc684[];
extern int data_ov004_020bc5d0[];
extern int data_ov004_020bc3a0[];
extern int data_ov004_020bc47c[];
extern int data_ov004_020bc288[];
extern int data_ov004_020bc490[];
extern int data_ov004_020bc29c[];
extern int data_ov004_020bc580[];
extern int data_ov004_020bc350[];
extern int data_ov004_020bc4a4[];
extern int data_ov004_020bc2b0[];
extern int data_ov004_020bc4b8[];
extern int data_ov004_020bc2c4[];
extern int data_ov004_020bc4cc[];
extern int data_ov004_020bc2d8[];
extern int data_ov004_020bc4e0[];
extern int data_ov004_020bc2ec[];
extern int data_ov004_020bc38c[];
extern int data_ov004_020bc508[];
extern int data_ov004_020bc314[];
extern int data_ov004_020bc51c[];
extern int data_ov004_020bc328[];
extern int data_ov004_020bc530[];
extern int data_ov004_020bc6d4[];
extern int data_ov004_020bc544[];
extern int data_ov004_020bc6c0[];
extern int data_ov004_020bc5a8[];
extern int data_ov004_020bc33c[];
extern int data_ov004_020bc558[];
extern int data_ov004_020bc364[];
extern int data_ov004_020bc56c[];

extern int data_ov004_020bf560[];
extern int data_ov004_020bf5d4[];

#pragma opt_strength_reduction off
void func_ov004_020b2cb8(void)
{
    int i;
    Entry entries[29] = {
        { 1, 100 },
        { 2, 101 },
        { 3, 102 },
        { 4, 103 },
        { 5, 104 },
        { 6, 105 },
        { 7, 106 },
        { 8, 107 },
        { 9, 108 },
        { 10, 109 },
        { 11, 110 },
        { 12, 111 },
        { 13, 112 },
        { 14, 113 },
        { 15, 114 },
        { 16, 115 },
        { 17, 116 },
        { 18, 117 },
        { 19, 118 },
        { 20, 119 },
        { 21, 120 },
        { 22, 121 },
        { 23, 122 },
        { 24, 123 },
        { 25, 124 },
        { 26, 125 },
        { 27, 126 },
        { 28, 127 },
        { 29, 128 },
    };

    entries[0].id = data_ov004_020bc42c[func_ov004_020ad674()];
    entries[0].ptr = data_ov004_020bc65c[func_ov004_020ad674()];
    entries[2].id = data_ov004_020bc418[func_ov004_020ad674()];
    entries[2].ptr = data_ov004_020bc648[func_ov004_020ad674()];
    entries[3].id = data_ov004_020bc3c8[func_ov004_020ad674()];
    entries[3].ptr = data_ov004_020bc5e4[func_ov004_020ad674()];
    entries[4].id = data_ov004_020bc4f4[func_ov004_020ad674()];
    entries[4].ptr = data_ov004_020bc300[func_ov004_020ad674()];
    entries[5].id = data_ov004_020bc3dc[func_ov004_020ad674()];
    entries[5].ptr = data_ov004_020bc5f8[func_ov004_020ad674()];
    entries[6].id = data_ov004_020bc3f0[func_ov004_020ad674()];
    entries[6].ptr = data_ov004_020bc60c[func_ov004_020ad674()];
    entries[7].id = data_ov004_020bc404[func_ov004_020ad674()];
    entries[7].ptr = data_ov004_020bc634[func_ov004_020ad674()];
    entries[8].id = data_ov004_020bc3b4[func_ov004_020ad674()];
    entries[8].ptr = data_ov004_020bc5bc[func_ov004_020ad674()];
    entries[9].id = data_ov004_020bc468[func_ov004_020ad674()];
    entries[9].ptr = data_ov004_020bc6ac[func_ov004_020ad674()];
    entries[10].id = data_ov004_020bc454[func_ov004_020ad674()];
    entries[10].ptr = data_ov004_020bc698[func_ov004_020ad674()];
    entries[11].id = data_ov004_020bc378[func_ov004_020ad674()];
    entries[11].ptr = data_ov004_020bc594[func_ov004_020ad674()];
    entries[12].id = data_ov004_020bc620[func_ov004_020ad674()];
    entries[12].ptr = data_ov004_020bc670[func_ov004_020ad674()];
    entries[13].id = data_ov004_020bc440[func_ov004_020ad674()];
    entries[13].ptr = data_ov004_020bc684[func_ov004_020ad674()];
    entries[14].id = data_ov004_020bc5d0[func_ov004_020ad674()];
    entries[14].ptr = data_ov004_020bc3a0[func_ov004_020ad674()];
    entries[15].id = data_ov004_020bc47c[func_ov004_020ad674()];
    entries[15].ptr = data_ov004_020bc288[func_ov004_020ad674()];
    entries[16].id = data_ov004_020bc490[func_ov004_020ad674()];
    entries[16].ptr = data_ov004_020bc29c[func_ov004_020ad674()];
    entries[17].id = data_ov004_020bc580[func_ov004_020ad674()];
    entries[17].ptr = data_ov004_020bc350[func_ov004_020ad674()];
    entries[18].id = data_ov004_020bc4a4[func_ov004_020ad674()];
    entries[18].ptr = data_ov004_020bc2b0[func_ov004_020ad674()];
    entries[19].id = data_ov004_020bc4b8[func_ov004_020ad674()];
    entries[19].ptr = data_ov004_020bc2c4[func_ov004_020ad674()];
    entries[20].id = data_ov004_020bc4cc[func_ov004_020ad674()];
    entries[20].ptr = data_ov004_020bc2d8[func_ov004_020ad674()];
    entries[21].id = data_ov004_020bc4e0[func_ov004_020ad674()];
    entries[21].ptr = data_ov004_020bc2ec[func_ov004_020ad674()];
    entries[22].id = data_ov004_020bc38c[func_ov004_020ad674()];
    entries[22].ptr = data_ov004_020bc508[func_ov004_020ad674()];
    entries[23].id = data_ov004_020bc314[func_ov004_020ad674()];
    entries[23].ptr = data_ov004_020bc51c[func_ov004_020ad674()];
    entries[24].id = data_ov004_020bc328[func_ov004_020ad674()];
    entries[24].ptr = data_ov004_020bc530[func_ov004_020ad674()];
    entries[25].id = data_ov004_020bc6d4[func_ov004_020ad674()];
    entries[25].ptr = data_ov004_020bc544[func_ov004_020ad674()];
    entries[26].id = data_ov004_020bc6c0[func_ov004_020ad674()];
    entries[26].ptr = data_ov004_020bc5a8[func_ov004_020ad674()];
    entries[27].id = data_ov004_020bc33c[func_ov004_020ad674()];
    entries[27].ptr = data_ov004_020bc558[func_ov004_020ad674()];
    entries[28].id = data_ov004_020bc364[func_ov004_020ad674()];
    entries[28].ptr = data_ov004_020bc56c[func_ov004_020ad674()];

    for (i = 0; i < 29; i++) {
        int t;
        t = LoadFile(entries[i].id);
        ((volatile int *)data_ov004_020bf560)[i] = t;
        t = (int)&entries[i];
        t = *(volatile int *)(t + 4);
        t = *(int *)t;
        data_ov004_020bf5d4[i] = t;
    }
}
