//cpp
// NONMATCHING: register allocation (div=43). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
typedef unsigned char u8;

extern "C" int GetOwnerLanguage(void);

namespace G2S { u16* GetBG1ScrPtr(); }

extern int data_02075610[];
extern u16 data_020755cc[];
extern u8 data_0209f2b4;
extern u8 data_0209f2e0;
extern u8 data_0209f29c;
extern u8 data_0209f244;

struct Stage {
    static void PS_UpdateOkAndBackButtons(bool b);
};

void Stage::PS_UpdateOkAndBackButtons(bool b)
{
    int base;
    int sl;
    int i;
    int j;

    if (GetOwnerLanguage() == 5 || GetOwnerLanguage() == 3)
        base = 2;
    else
        base = 0;

    for (i = 0; i < 2; i++) {
        if (b) {
            sl = 0x1000;
        } else {
            int v;
            if (data_0209f2b4 == data_0209f2e0 && data_0209f29c == i && data_0209f244 == 0)
                v = 0x2000;
            else
                v = 0x1000;
            sl = (u16)v;
        }

        int idx = i + base;
        u16* scr = G2S::GetBG1ScrPtr() + data_020755cc[idx];
        for (j = 0; j < data_02075610[idx]; j++) {
            scr[0] = (scr[0] & 0x3ff) | sl;
            scr[0x20] = (scr[0x20] & 0x3ff) | sl;
            scr[0x40] = (scr[0x40] & 0x3ff) | sl;
            scr[0x60] = (scr[0x60] & 0x3ff) | sl;
            scr++;
        }
    }
}
