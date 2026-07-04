// NONMATCHING: base materialization / addressing (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Anim {
    char pad[0x20];
    int mode;     /* 0x20 */
    int rev;      /* 0x24 */
    int f28;      /* 0x28 */
    short frame;  /* 0x2c */
    short tick;   /* 0x2e */
    int changed;  /* 0x30 */
};

struct AnimData {
    int w0;
    unsigned short *durations; /* 0x4 */
    int w8;
    int count;    /* 0xc */
};

void func_ov007_020c0d70(struct Anim *a, struct AnimData *d)
{
    int loop;
    int step;

    if (a->mode == 0) return;
    if (a->f28 != 0) return;

    loop = (a->mode == 1);
    a->f28 = 0;
    a->changed = 0;
    step = 1;
    if (a->rev == 1) step = step * -1;

    a->tick = (short)(a->tick + step);

    if (a->tick >= (int)d->durations[a->frame]) {
        a->tick = 0;
        a->frame++;
        if (a->frame >= d->count) {
            a->frame = (short)(loop ? 0 : d->count - 1);
            a->changed = 1;
        }
    } else if (a->tick < 0) {
        a->tick = (short)(d->durations[a->frame] - 1);
        a->frame--;
        if (a->frame < 0) {
            a->frame = (short)(loop ? d->count - 1 : 0);
            a->changed = 1;
        }
    }
}
