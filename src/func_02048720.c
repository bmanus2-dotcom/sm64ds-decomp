typedef unsigned char u8;
typedef unsigned int u32;

struct Vec3 { int x, y, z; };

typedef struct {
    void *obj;
    int dist;
} SoundSlot;

extern u32 data_02099fac;
extern int data_02099fb0;
extern SoundSlot data_020a4bf8[2];
extern SoundSlot data_020a4c18[];

extern void *func_02050cdc(int kind, int id);
extern int func_02049018(struct Vec3 *v);
extern void func_0204fa2c(void *slot, int v);
extern void func_0204f934(int **slot);

void *func_02048720(struct Vec3 *v, int kind, int id)
{
    u32 lim;
    void *elem;
    u8 pri;
    u8 typ;
    int dist;
    SoundSlot *table;
    int count;
    int i;
    int pick;
    u8 best_pri;
    int best_idx;
    int best_dist;
    SoundSlot *slot;

    lim = data_02099fac;
    elem = func_02050cdc(kind, id);
    if (elem == 0) {
        return 0;
    }

    typ = *(u8 *)((char *)elem + 5);
    pri = *(u8 *)((char *)elem + 4);

    if (typ == 2) {
        count = 2;
        table = data_020a4bf8;
    } else if (typ == 9) {
        count = data_02099fb0;
        table = data_020a4c18;
    } else {
        return 0;
    }

    dist = func_02049018(v);

    if (id >= 0x4b && id <= 0x4c) {
        lim = 0x384;
    }
    if ((u32)dist > lim) {
        return 0;
    }

    pick = -1;
    for (i = 0; i < count; i++) {
        if (table[i].obj == 0) {
            pick = i;
            break;
        }
    }

    if (pick < 0) {
        best_pri = 0xff;
        best_idx = -1;
        best_dist = 0;

        for (i = 0; i < count; i++) {
            void *obj;

            obj = table[i].obj;
            if (obj != 0) {
                u8 p;
                int d;

                p = *(u8 *)((char *)obj + 0x3d);
                d = *(int *)((char *)obj + 4);
                if (best_pri > p) {
                    best_pri = p;
                    best_idx = i;
                    best_dist = d;
                } else if (best_pri == p && best_dist < d) {
                    best_idx = i;
                    best_dist = d;
                }
            }
        }

        if (pri > best_pri) {
            pick = best_idx;
        } else if (pri == best_pri && dist <= best_dist) {
            pick = best_idx;
        }
    }

    if (pick < 0 || pick >= count) {
        return 0;
    }

    slot = &table[pick];
    func_0204fa2c(slot, 1);
    func_0204f934((int **)slot);
    slot->dist = dist;
    return slot;
}