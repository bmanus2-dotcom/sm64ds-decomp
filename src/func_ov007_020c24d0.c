// NONMATCHING: constant / value (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov007_020c2d44(void *s, int i);

struct E12 { int a, b, c; };

struct S {
    int state;          // +0
    int flag;           // +4
    unsigned short count; // +8
    char pad[0x18 - 0xa];
    int *p18;           // +0x18
    unsigned short *p1c; // +0x1c
    int *p20;           // +0x20
    int *p24;           // +0x24
    int *p28;           // +0x28
    struct E12 *p2c;    // +0x2c
};

void func_ov007_020c24d0(struct S *s, int arg1)
{
    int *p18;
    int *p24;
    int *p28;
    unsigned short *p1c;
    int ip;

    if (s->count == 0)
        return;
    if (arg1 >= s->count)
        return;
    s->count--;
    if (arg1 == s->count)
        return;

    for (ip = arg1; ip < s->count; ip++) {
        switch (s->state) {
        case 0:
            p24 = s->p24;
            p24[ip] = p24[ip + 1];
            p28 = s->p28;
            p28[ip] = p28[ip + 1];
            p1c = s->p1c;
            p1c[ip] = p1c[ip + 1];
            break;
        case 1:
            s->p2c[ip] = s->p2c[ip + 1];
            break;
        }
        p18 = s->p18;
        p18[ip] = p18[ip + 1];
        if (s->flag & 1)
            s->p20[ip] = s->p20[ip + 1];
    }

    switch (s->state) {
    case 0:
        func_ov007_020c2d44(s, arg1);
        break;
    case 1:
        break;
    }
}
