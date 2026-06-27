// NONMATCHING: base materialization / addressing (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Actor;

extern struct Actor *func_0200e55c(unsigned int ownerID);

int func_02008080(void *param_1)
{
    struct Actor *a = func_0200e55c(0x13);
    unsigned int *dst = (unsigned int *)((unsigned char *)param_1 + 0x90);
    unsigned int val = *(unsigned int *)((unsigned char *)a + 0x60);
    *dst = *dst + val;
    return 1;
}
