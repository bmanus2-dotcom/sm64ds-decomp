//cpp
// _ZN3HUD15RenderStarCountEv at 0x020fc458 (ov002)
struct OamAttr;
struct Matrix2x2;

typedef struct HUD_s {
    char pad[0x70];
    short unk70;
    short unk72;
    signed char digits[3];
} HUD_s;

extern "C" {

extern unsigned char data_0209f2d8;
extern unsigned char data_0209f250;
extern signed char data_0209f310[];
extern unsigned char data_0209f2fc;
extern unsigned char data_ov002_02111178;
extern unsigned char data_0209f2ac;
extern unsigned char data_0209f2d4;
extern int data_020a0db0;

extern struct OamAttr* func_020aba70[];
extern struct OamAttr func_020ab9c8;
extern struct OamAttr func_020abad0;

extern unsigned char NumStars(void);
extern void _ZN3HUD15CalculateDigitsEt(HUD_s* thisptr, unsigned short n);
extern void _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(int b, struct OamAttr* attr, int x, int y, int a, int c, struct Matrix2x2* m);

void _ZN3HUD15RenderStarCountEv(HUD_s* thisptr)
{
    int x = thisptr->unk70;
    int b = (data_0209f2d8 == 1);
    int i;

    if (b) {
        _ZN3HUD15CalculateDigitsEt(thisptr, (unsigned short)data_0209f310[data_0209f250]);
        for (i = 2; i >= 0; i--) {
            if (thisptr->digits[i] >= 0) {
                _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(0, func_020aba70[thisptr->digits[i]], x, 2, -1, 1, 0);
                x -= 9;
            }
        }
        _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(0, &func_020ab9c8, x, 10, -1, 1, 0);
        _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(0, &func_020abad0, x - 16, 10, -1, 1, 0);
        return;
    }

    _ZN3HUD15CalculateDigitsEt(thisptr, NumStars());

    {
        unsigned char m = data_0209f2fc;
        if ((m != 2 && data_ov002_02111178 == 4) ||
            (m == 1 && data_ov002_02111178 >= 3 && data_ov002_02111178 < 6)) {
            int flag;
            if (data_0209f2ac != 0) {
                if (data_0209f2d4 == 3 && (data_020a0db0 & 0x18) == 0) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            } else {
                flag = 1;
            }
            if (flag == 0) {
                return;
            }
            for (i = 2; i >= 0; i--) {
                if (thisptr->digits[i] >= 0) {
                    _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(0, func_020aba70[thisptr->digits[i]], x, 2, -1, 1, 0);
                    x -= 9;
                }
            }
            _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(0, &func_020ab9c8, x, 10, -1, 1, 0);
            _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(0, &func_020abad0, x - 16, 10, -1, 1, 0);
            return;
        }
    }

    for (i = 2; i >= 0; i--) {
        if (thisptr->digits[i] >= 0) {
            _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(1, func_020aba70[thisptr->digits[i]], x, 2, -1, 1, 0);
            x -= 9;
        }
    }
    _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(1, &func_020ab9c8, x, 10, -1, 1, 0);
    _ZN3OAM6RenderEbP7OamAttriiiiP9Matrix2x2(1, &func_020abad0, x - 16, 10, -1, 1, 0);
}

}
