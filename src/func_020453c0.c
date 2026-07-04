// NONMATCHING: base materialization / addressing (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0204547c(int *a, int b, int c, void *elem);

void func_020453c0(int *a, short *node, int *p2, int p3)
{
    int idx = node[0];
    char *elem = (char*)a[2] + idx * 0x34;
    int f2c = *(int*)(elem + 0x2c);
    int *r6 = (f2c != 0) ? (int*)f2c : p2;
    int r5 = (f2c != 0) ? *(unsigned short*)(elem + 0x30) : p3;
    int mla = idx * 0x24 + r6[5];
    unsigned short *dst;
    func_0204547c(r6, mla, r5, elem);
    dst = (unsigned short*)(elem + 0x18);
    *dst = (unsigned short)(*dst | *(unsigned short*)(elem + node[4] * 0x34 + 0x18));
    if (node[5] != 0)
        func_020453c0(a, (short*)((char*)node + (node[5] << 6)), r6, r5);
    if (node[6] != 0)
        func_020453c0(a, (short*)((char*)node + (node[6] << 6)), r6, r5);
}
