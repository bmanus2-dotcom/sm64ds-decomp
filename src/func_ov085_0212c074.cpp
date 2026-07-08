//cpp
extern "C" {

struct Node { char pad[0x24]; unsigned int count; };
struct Pair { struct Node *node; char *item; };
typedef void (*Fn)(void *a, void *b);

extern signed char data_0209f2f8;
extern signed char data_02092120;
extern void func_ov085_0212c150(void *self);

int func_ov085_0212c074(char *self)
{
    unsigned int i;
    struct Node *node;
    char *item;
    struct Pair *p;
    int b;

    if (*(unsigned char *)(self + 0x428) == 1) return 1;

    b = (*(int *)(self + 0xb0) & 0x40000) != 0;
    if (b) return 1;

    *(int *)(self + 0x80) = 0x1500;
    *(int *)(self + 0x88) = *(int *)(self + 0x80);
    *(int *)(self + 0x84) = *(int *)(self + 0x88);

    p = (struct Pair *)(((long long)(int)(self + 0x308)) & 0xFFFFFFFFFFFFFFFFLL);
    i = 0;
    node = p->node;
    item = p->item;
    for (; i < node->count; i++) {
        *(int *)(item + 0x20) = *(int *)(self + 0x468);
        item += 0x30;
    }

    if (data_0209f2f8 == 5 && data_02092120 == 3) {
        func_ov085_0212c150(self);
    }

    {
        char *o = (char *)(((long long)(int)(self + 0x300)) & 0xFFFFFFFFFFFFFFFFLL);
        Fn fn = *(Fn *)(*(char **)o + 0x14);
        fn(o, self + 0x80);
    }
    return 1;
}

}
