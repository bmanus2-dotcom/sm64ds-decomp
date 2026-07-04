// NONMATCHING: base materialization / addressing (div=48). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(unsigned int a, unsigned int b, int fix, int t1, int t2, void *v, void *cb);
extern int _ZN5Sound8PlayLongEjjjRK7Vector3j(unsigned int a, unsigned int b, unsigned int c, void *v, unsigned int d);

int func_ov060_021132a4(char *c)
{
    int r4 = 0;
    *(int *)(c + 0x448) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
        *(int *)(c + 0x448), 0x99, *(int *)(c + 0x5c), *(int *)(c + 0x60) + 0x32000, *(int *)(c + 0x64), 0, 0);
    if (*(int *)(c + 0x80) < 0xccc)
        *(short *)(c + 0x402) = *(short *)(c + 0x402) + 0x80;
    if (*(int *)(c + 0x80) > 0x334) {
        *(int *)(c + 0x80) = *(int *)(c + 0x80) - 0x52;
        *(int *)(c + 0x88) = *(int *)(c + 0x88) - 0x52;
    } else {
        *(int *)(c + 0x84) = *(int *)(c + 0x84) - 0x29;
        *(int *)(c + 0xa8) = 0xa000;
    }
    *(int *)(c + 0x9c) = 0;
    if (*(int *)(c + 0x84) < 0x800)
        r4 = 1;
    *(short *)(c + 0x8e) = *(short *)(c + 0x8e) + *(short *)(c + 0x402);
    if (*(unsigned char *)(c + 0x41c) > 2)
        *(unsigned char *)(c + 0x41c) = *(unsigned char *)(c + 0x41c) - 2;
    if (r4 == 0) {
        if (*(int *)(c + 0x450) != 0xba)
            *(int *)(c + 0x44c) = 0;
        *(int *)(c + 0x450) = 0xba;
        *(int *)(c + 0x44c) = _ZN5Sound8PlayLongEjjjRK7Vector3j(
            *(int *)(c + 0x44c), 3, *(int *)(c + 0x450), c + 0x74, 0);
    }
    return r4;
}
