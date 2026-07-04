//cpp
// NONMATCHING: push-set / frame (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Actor;
extern "C" {
Actor *_ZN5Actor15FindWithActorIDEjPS_(unsigned int, Actor *);
void func_ov063_02119c58(char *c);
}
void func_ov063_02119c58(char *c) {
    unsigned int id;
    Actor *a;
    if (*(int *)(c + 0x490) != 0) return;
    id = 0xd2;
    a = 0;
    while ((a = _ZN5Actor15FindWithActorIDEjPS_(id, a)) != 0) {
        unsigned char t = *((unsigned char *)a + 0x5cf);
        if (t == 0xe) goto hit;
        if (t == 0xd) {
        hit:
            *(int *)(c + 0x490) = *(int *)((char *)a + 4);
            return;
        }
    }
}
