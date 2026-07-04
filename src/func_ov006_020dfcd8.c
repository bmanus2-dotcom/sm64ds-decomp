// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020df024(char *o);

void func_ov006_020dfcd8(char *o)
{
    int *p = (int *)(o + 0x541c);
    *p = *p - 1;
    if (*(int *)(o + 0x5000 + 0x41c) > 0) return;
    func_ov006_020df024(o);
    if (*(unsigned char *)(o + 0x5000 + 0x46b) != 0) {
        unsigned char *q = (unsigned char *)(o + 0x546b);
        *q = *q - 1;
    }
    *(int *)(o + 0x5000 + 0x418) = 2;
}
