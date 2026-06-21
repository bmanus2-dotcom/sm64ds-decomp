/* func_ov002_020b9f00 at 0x020b9f00
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (overlay ov002).
 */

struct Actor;
extern struct Actor *_ZN5Actor15FindWithActorIDEjPS_(unsigned int id, struct Actor *prev);

struct Obj {
    char pad0[0x344];
    struct Actor *found;     // 0x344
    char pad1[0x351 - 0x348];
    unsigned char tag;       // 0x351
};

struct Actor {
    char pad0[4];
    void *next;              // 0x4
    char pad1[0x49d - 0x8];
    unsigned char tag;       // 0x49d
};

int func_ov002_020b9f00(struct Obj *self) {
    struct Actor *a;
    if (self->found != 0) {
        return 0;
    }
    a = _ZN5Actor15FindWithActorIDEjPS_(0xb2, 0);
    while (a != 0) {
        if (self->tag == a->tag) {
            self->found = (struct Actor *)a->next;
            return 1;
        }
        a = _ZN5Actor15FindWithActorIDEjPS_(0xb2, a);
    }
    return 0;
}
