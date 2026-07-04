//cpp
// NONMATCHING: different op / idiom (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Actor;
extern "C" {
Actor *_ZN5Actor13ClosestPlayerEv(void);
void func_ov065_02117944(void *c, void *p);
extern void *data_ov065_0211d6e0;
int func_ov065_02117780(char *c);
}
int func_ov065_02117780(char *c) {
    int v60, r2;
    Actor *p;
    *(short *)(c + 0x94) = *(short *)(c + 0x94) + 0x1000;
    p = _ZN5Actor13ClosestPlayerEv();
    v60 = *(int *)(c + 0x60);
    r2 = v60 - 0xc8000;
    if (p != 0) r2 = *(int *)((char *)p + 0x644) + 0x50000;
    if (*(unsigned short *)(c + 0x100) == 0 || r2 > v60) {
        func_ov065_02117944(c, &data_ov065_0211d6e0);
    }
    return 1;
}
