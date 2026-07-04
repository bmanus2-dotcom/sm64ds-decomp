// NONMATCHING: register allocation (div=32). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020fb8fc(char *c, int a2, int a3, int a4, int a5, int a6);
extern void func_ov006_020fc1b4(char *base, int val);
extern void func_02012718(void *a, int b);

void func_ov006_020fca1c(char *r5, int r1)
{
    char *r6 = r5 + r1 * 0x38;
    int ip;
    char *r2;
    char *r0;
    char *r3;
    if (*(unsigned char *)(r6 + 0x4000 + 0x68f) == 5) return;
    r2 = r6 + 0x4660;
    r0 = r6 + 0x4664;
    r3 = r5;
    for (ip = 0; ip < 4; ip++, r3 += 0xc) {
        char *lr = r3 + 0x5000;
        int dx, dy;
        if (*(unsigned char *)(lr + 0xbd4) == 0) continue;
        dx = (*(int *)(lr + 0xbcc) - *(int *)r2) >> 0xc;
        dy = (*(int *)(lr + 0xbd0) - *(int *)r0) >> 0xc;
        if (dx < -0x10) continue;
        if (dx > 0x18) continue;
        if (dy < -0x10) continue;
        if (dy > 0x18) continue;
        *(unsigned char *)(r5 + r1 * 0x38 + 0x4000 + 0x68c) = 0;
        *(unsigned char *)(r5 + r1 * 0x38 + 0x4000 + 0x68d) = 0;
        func_ov006_020fb8fc(r5, *(int *)(r5 + ip * 0xc + 0x5000 + 0xbcc),
                            *(int *)(r5 + ip * 0xc + 0x5000 + 0xbd0), 2, 0, ip + 1);
        func_ov006_020fc1b4(r5, 0);
        func_02012718((void *)0x18c, *(int *)(r5 + r1 * 0x38 + 0x4000 + 0x660));
        return;
    }
}
