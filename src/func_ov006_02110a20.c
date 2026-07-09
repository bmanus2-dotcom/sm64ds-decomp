// NONMATCHING: entity-index guard codegen (div~36, 0x170 vs 0x194); siblings 0211470c/02115598 matched
typedef unsigned char u8;

extern void func_ov006_0211470c(int *a, int *b);
extern void func_ov006_02115598(void *c, int *src, int v2, int v3, int v5);
extern void func_ov006_02114fd0(char *p);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int id);

void func_ov006_02110a20(char *ctx)
{
    char *stage;
    int count;
    int i;
    int pos[2];
    int base[2];
    int dx;
    int dy;
    char *ent;

    stage = *(char **)(ctx + 4);
    *(int *)(ctx + 0x10) = *(int *)(ctx + 8);
    *(int *)(ctx + 0x14) = *(int *)(ctx + 0xc);
    count = *(int *)(stage + 0x4668);
    if (count <= 0) {
        return;
    }
    i = 0;
    do {
        if (i < 0xd) {
            ent = *(char **)(stage + 0x4688 + i * 4);
        } else {
            ent = *(char **)(ctx + 8);
        }
        if (*(u8 *)(ent + 0x30) != 0) {
            if (i < 0xd) {
                ent = *(char **)(stage + 0x4688 + i * 4);
            } else {
                ent = *(char **)(ctx + 8);
            }
            if (*(u8 *)(ent + 0x120) != 1) {
                if (i < 0xd) {
                    ent = *(char **)(stage + 0x4688 + i * 4);
                } else {
                    ent = *(char **)(ctx + 8);
                }
                func_ov006_0211470c(pos, (int *)ent);
                dx = pos[0] - *(int *)(ctx + 8);
                dy = pos[1] - *(int *)(ctx + 0xc);
                if (dx >= -0x8000 && dx < 0x8000 && dy >= -0x40000 && dy < -0x38000) {
                    base[0] = *(int *)(ctx + 8);
                    base[1] = -0x40000;
                    func_ov006_02115598(stage, base, 0xbb8, 0, 1);
                    func_ov006_02114fd0(stage);
                    if (i < 0xd) {
                        ent = *(char **)(stage + 0x4688 + i * 4);
                    } else {
                        ent = *(char **)(ctx + 8);
                    }
                    *(u8 *)(ent + 0x120) = 1;
                    _ZN5Sound12PlayBank2_2DEj(0x16);
                }
            }
        }
        i++;
        count = *(int *)(stage + 0x4668);
    } while (i < count);
}