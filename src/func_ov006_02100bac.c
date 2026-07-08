typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern int* data_0213db9c[];
extern s16 data_02082214[];
extern int cstd_atan2(int, int);
extern void func_ov006_020ff4ec(void* self);

typedef struct { int v; int _pad[15]; } C4;    /* stride 0x40 */
typedef struct { u16 v; u16 _pad[31]; } C2;     /* stride 0x40 */

/* pointer form: p = self + idx*0x40 */
#define PF5290 (*(u16*)(p + 0x5290))
#define PF5292 (*(u16*)(p + 0x5292))
#define SF5292 (*(s16*)(p + 0x5292))
#define PF5260 (*(int*)(p + 0x5260))
#define PF5264 (*(int*)(p + 0x5264))
#define PF5270 (*(int*)(p + 0x5270))
#define PF5296 (*(u8*)(p + 0x5296))
#define V5668  (*(int*)((char*)self + 0x5668))

/* array form (read-modify-write): base + idx*0x40 scaled */
#define AF5292 (((C2*)((char*)self + 0x5292))[idx].v)
#define AF5260 (((C4*)((char*)self + 0x5260))[idx].v)
#define AF5264 (((C4*)((char*)self + 0x5264))[idx].v)
#define AF5270 (((C4*)((char*)self + 0x5270))[idx].v)

void func_ov006_02100bac(void* self, int idx) {
    char* p = (char*)self + idx * 0x40;
    int base;
    int dx, dy;

    if (PF5292 != 0) {
        AF5292--;
        if (SF5292 < 0) SF5292 = 0;
        return;
    }

    base = data_0213db9c[V5668][idx];
    PF5290 = (u16)cstd_atan2(base - (PF5264 >> 12), 0x80 - (PF5260 >> 12));

    AF5260 += (int)(((long long)data_02082214[(PF5290 >> 4) * 2 + 1] * PF5270 + 0x800) >> 12);
    AF5264 += (int)(((long long)data_02082214[(PF5290 >> 4) * 2] * PF5270 + 0x800) >> 12);
    AF5270 += 0x100;

    dx = (PF5260 >> 12) - 0x80;
    dy = (PF5264 >> 12) - base;
    if (dx < -3) return;
    if (dx > 3) return;
    if (dy < -3) return;
    if (dy > 3) return;

    PF5260 = 0x80000;
    PF5264 = base << 12;
    PF5296 = 0xd;
    func_ov006_020ff4ec(self);
    PF5292 = 0x40;
    if (idx & 1) {
        AF5292 += 0x20;
    }
}
