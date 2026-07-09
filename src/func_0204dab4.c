// NONMATCHING: size 0x1a0 vs ROM 0x1d0 (-0x30); linked-list search + callback arg setup.
extern int func_02052f4c(int a, int b);
extern void func_0204dcc0(int *src, short *o1, short *o2, int *o3);

typedef struct Node Node;
struct Node {
    Node *next;
    char pad[4];
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    short f2c;
    short f2e;
};

typedef struct Entry Entry;
struct Entry {
    short f4;
    unsigned char f6;
    char pad;
    Node *node;
};

void func_0204dab4(void *sys, Entry *buf, int count, unsigned int mask, void *cb)
{
    Node *walk;
    int i;
    void (*fn)(int *, Entry *, short *, int *);

    if (cb == 0)
        fn = (void (*)(int *, Entry *, short *, int *))func_0204dcc0;
    else
        fn = (void (*)(int *, Entry *, short *, int *))cb;

    walk = *(Node **)((char *)sys + 8);
    if (walk == 0)
        goto tail;

    do {
        int found;
        int empty;
        int i;
        Entry *slot;

        found = -1;
        empty = -1;
        if (count > 0) {
            i = 0;
            do {
                if (buf[i].node != 0) {
                    if (buf[i].node == walk) {
                        found = i;
                        goto have_idx;
                    }
                } else if (empty < 0) {
                    empty = i;
                }
                i++;
            } while (i < count);
        }

    have_idx:
        slot = 0;
        if (found >= 0)
            slot = &buf[found];
        else if (empty >= 0 && mask < 4) {
            slot = &buf[empty];
            slot->node = walk;
            slot->f6 = (unsigned char)((slot->f6 & ~3u) | (mask & 3u));
        }

        if (slot != 0) {
            int sp8;
            int spc;
            int sp10;
            int sp14;
            int scale;
            int prod;
            short out;

            scale = 0x1000 - func_02052f4c((int)walk->f2e << 12, walk->f2c);
            spc = walk->f14 + walk->f8;
            sp10 = walk->f18 + walk->fc;
            sp14 = walk->f1c + walk->f10;
            fn(&spc, slot, (short *)((char *)slot + 6), &sp8);
            prod = sp8 * scale + 0x800;
            out = (short)((unsigned int)(prod >> 12) | ((unsigned int)(prod >> 12) >> 20 << 20));
            slot->f4 = out;
            slot->f6 = (unsigned char)(slot->f6 | 4u);
        }

        walk = walk->next;
    } while (walk != 0);

tail:
    if (count <= 0)
        return;

    i = 0;
    do {
        if ((buf[i].f6 << 29 >> 31) == 0) {
            if (buf[i].node != 0)
                buf[i].node = 0;
        }
        buf[i].f6 = (unsigned char)(buf[i].f6 & ~4u);
        i++;
    } while (i < count);
}