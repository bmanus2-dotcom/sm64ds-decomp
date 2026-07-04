// NONMATCHING: missing logic (ROM does more) (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0205d874(int *s);
extern void func_0205d5e8(int *s, void *this, int a, int b, int e);
extern void func_0205d3d4(int *s, int x, int n);
extern void func_0205d4cc(int *s);
extern int func_0205d28c(void);

unsigned int func_0205c9b8(char *thiz, int arg1, unsigned int arg2) {
    int s[18];
    unsigned int r5;
    int r4;
    int sz;
    sz = *(int*)(thiz + 0x24) + *(int*)(thiz + 0x2c) + 0x20;
    r5 = (sz + 0x1f) & ~0x1f;
    if (r5 > arg2) goto done;
    r4 = (arg1 + 0x1f) & ~0x1f;
    func_0205d874(s);
    func_0205d5e8(s, thiz, *(int*)(thiz + 0x20),
                  *(int*)(thiz + 0x20) + *(int*)(thiz + 0x24), -1);
    func_0205d3d4(s, r4, *(int*)(thiz + 0x24));
    func_0205d4cc(s);
    *(int*)(thiz + 0x20) = r4;
    r4 = r4 + *(int*)(thiz + 0x24);
    func_0205d5e8(s, thiz, *(int*)(thiz + 0x28),
                  *(int*)(thiz + 0x28) + *(int*)(thiz + 0x2c), -1);
    func_0205d3d4(s, r4, *(int*)(thiz + 0x2c));
    func_0205d4cc(s);
    *(int*)(thiz + 0x28) = r4;
    *(int(**)(void))(thiz + 0x44) = func_0205d28c;
    *(int*)(thiz + 0x38) = arg1;
    *(int*)(thiz + 0x10) |= 4;
done:
    return r5;
}
