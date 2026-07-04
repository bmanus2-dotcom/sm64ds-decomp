// NONMATCHING: different op / idiom (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct N { char pad34[0x34]; struct N* owner; struct N* head; struct N* next; };
void func_ov007_020c10b0(struct N* a, struct N* b) {
    b->owner = a;
    if (a->head == 0) {
        a->head = b;
        return;
    }
    {
        struct N* p = a->head;
        while (p->next != 0) {
            p = p->next;
        }
        p->next = b;
    }
}
