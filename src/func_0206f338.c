// NONMATCHING: base materialization / addressing (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct S {
    unsigned char pad0[2];
    short count;
    unsigned char len;
    unsigned char digits[1];
};

void func_0206f338(struct S *s, int p)
{
    unsigned char *digits;
    unsigned char *q;
    unsigned char *end;
    unsigned int d;
    unsigned int e;
    int carry;
    int len;

    if (p < 0) {
    reset:
        s->count = 0;
        s->len = 1;
        s->digits[0] = 0x30;
        return;
    }
    len = s->len;
    if (p >= len) return;

    digits = &s->digits[0];
    q = digits + p + 1;
    d = (*--q - 0x30) & 0xff;
    if (d == 5) {
        end = digits + len;
        do {
            end--;
        } while (end > q && *end == 0x30);
        if (end == q)
            carry = q[-1] & 1;
        else
            carry = 1;
    } else {
        carry = (d > 5) ? 1 : 0;
    }

    if (p != 0) {
        do {
            e = ((*--q - 0x30) + carry) & 0xff;
            carry = (e > 9) ? 1 : 0;
            if (carry == 0 && e != 0) {
                *q = e + 0x30;
                break;
            }
            p--;
        } while (p != 0);
    }

    if (carry != 0) {
        s->count = s->count + 1;
        s->len = 1;
        s->digits[0] = 0x31;
        return;
    }
    if (p == 0)
        goto reset;
    s->len = p;
}
