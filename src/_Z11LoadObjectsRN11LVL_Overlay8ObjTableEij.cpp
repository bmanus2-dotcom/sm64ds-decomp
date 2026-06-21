//cpp
typedef void (*ObjFunc)(void *, int, unsigned int);

extern ObjFunc data_ov002_0210cbb8[];
extern unsigned char data_0209f220;

struct LVL_Overlay {
    struct ObjTable {
        unsigned short count;
        unsigned char pad[2];
        unsigned char *entries;
    };
};

extern "C" void _Z11LoadObjectsRN11LVL_Overlay8ObjTableEij(LVL_Overlay::ObjTable &tbl, int a, unsigned int b) {
    unsigned char *e = tbl.entries;
    int i;
    for (i = 0; i < (int)tbl.count; i++, e += 8) {
        unsigned char v = e[0];
        int group = (v >> 5) & 7;
        if (group == 0 || group == data_0209f220) {
            ObjFunc fp = data_ov002_0210cbb8[v & 0x1f];
            if (fp != 0) fp(e, a, b);
        }
    }
}
