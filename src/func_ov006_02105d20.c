// NONMATCHING: register allocation (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);

void func_ov006_02105d20(char *c) {
    int n;
    int i;
    int found;
    if (*(unsigned char *)(c + 0x4fe9) == 0) return;
    if (*(unsigned char *)(c + 0x4feb) == 0) return;
    --*(unsigned char *)(c + 0x4feb);
    if (*(unsigned char *)(c + 0x4feb) != 0) return;
    n = *(int *)(c + 0x4cb8);
    found = 0;
    for (i = 0; i < n; i++) {
        if (*(unsigned char *)(c + i + 0x4f1e) != *(unsigned char *)(c + i + 0x4f42)) {
            found++;
            break;
        }
    }
    if (found != 0) return;
    _ZN5Sound12PlayBank2_2DEj(0x1cd);
}
