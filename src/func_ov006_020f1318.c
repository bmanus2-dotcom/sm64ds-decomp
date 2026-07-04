// NONMATCHING: base materialization / addressing (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020f1318(char *c, int idx)
{
    unsigned short h = *(unsigned short*)(c + 0x506c + idx * 2);
    char *m = c + idx * 2 + 0x5000;
    unsigned char *q;
    *(short*)(c + 0x506c + idx * 2) = h - 1;
    if (*(short*)(m + 0x6c) < 0) *(short*)(m + 0x6c) = 0;
    if ((((unsigned short)*(unsigned short*)(m + 0x6c) >> 2) & 1) == 0) {
        char *p = c + 0x53dd;
        p[idx] = 1;
        q = (unsigned char*)(p + idx);
    } else {
        char *p = c + 0x53dd;
        p[idx] = 0;
        q = (unsigned char*)(p + idx);
    }
    if (*(unsigned short*)(m + 0x6c) != 0) return;
    *(unsigned char*)(c + idx + 0x5000 + 0x1fd) = 0;
    *q = 1;
}
