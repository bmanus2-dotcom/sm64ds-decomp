// NONMATCHING: register allocation (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov004_020b0aa0(int);

void func_ov006_0211e5cc(char *c)
{
    char *p;
    int i;
    int found;
    if (*(unsigned char *)(c + 0x4c20) != 0)
        return;
    found = 0;
    i = 0;
    p = c;
    do {
        if (*(unsigned char *)(p + 0x4677) != 0) {
            if (*(unsigned char *)(p + 0x4678) <= 2) {
                found++;
                break;
            }
        }
        i++;
        p += 0x24;
    } while (i < 0x10);
    if (found != 0)
        return;
    func_ov004_020b0aa0(0xc);
    *(unsigned char *)(c + 0x4c20) += 1;
}
