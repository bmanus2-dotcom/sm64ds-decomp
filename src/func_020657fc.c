// NONMATCHING: register allocation (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int x);
extern int *func_02065ae0(void);
extern void func_02065ad0(int v);

struct Node {
    int *key;          /* [0] */
    char pad[0x24];    /* [4] */
    struct Node *next; /* [0x28] */
};

struct Node *func_020657fc(int *key)
{
    int saved = _ZN3IRQ7DisableEv();
    struct Node *head = (struct Node *)func_02065ae0();
    struct Node *prev;
    struct Node *cur;
    if (head == 0) {
        _ZN3IRQ7RestoreEj(saved);
        return 0;
    }
    if (head->key == key) {
        func_02065ad0((int)head->next);
        _ZN3IRQ7RestoreEj(saved);
        return head;
    }
    prev = head;
    cur = prev->next;
    while (cur != 0) {
        if (cur->key == key) {
            prev->next = cur->next;
            _ZN3IRQ7RestoreEj(saved);
            return cur;
        }
        prev = cur;
        cur = cur->next;
    }
    _ZN3IRQ7RestoreEj(saved);
    return 0;
}
