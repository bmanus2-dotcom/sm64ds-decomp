// NONMATCHING: missing logic (ROM does more) (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov002_020f335c(char *o, int i) {
    int idx = i * 0x30;
    int *fld = (int *)(o + 0x144 + idx);
    int v;
    int a, b, c;
    *fld += 0x1800;
    v = *fld;
    if (v < 0x66000) goto noclamp;
    *fld = 0x66000;
noclamp:
    *(unsigned char *)(o + idx + 0x15c) = 0;
    *(unsigned char *)(o + idx + 0x15e) = 0;
    a = *(int *)(o + idx + 0x140) >> 0xc;
    v = *fld >> 0xc;
    b = *(int *)(o + idx + 0x148) >> 0xc;
    c = *(int *)(o + idx + 0x14c) >> 0xc;
    *(volatile unsigned short *)0x4001042 = (unsigned short)(((a << 8) & 0xff00) | (v & 0xff));
    *(volatile unsigned short *)0x4001046 = (unsigned short)(((b << 8) & 0xff00) | (c & 0xff));
}
