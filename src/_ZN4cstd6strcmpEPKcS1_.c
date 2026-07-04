//cpp
// NONMATCHING: different op / idiom (div=35). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
namespace cstd {
int strcmp(char const *a, char const *b) {
    int diff;
    unsigned int la, lb;
    unsigned int n;
    unsigned int wa, wb;

    diff = (int)(unsigned char)*a - (int)(unsigned char)*b;
    if (diff != 0)
        return diff;

    la = (unsigned int)a & 3;
    lb = (unsigned int)b & 3;
    if (lb == la) {
        if (la != 0) {
            if ((unsigned char)*a == 0)
                return 0;
            n = 3 - la;
            if (n != 0) {
                do {
                    diff = (int)(unsigned char)*++a - (int)(unsigned char)*++b;
                    if (diff != 0)
                        return diff;
                    if ((unsigned char)*a == 0)
                        return 0;
                } while (--n != 0);
            }
            ++a;
            ++b;
        }
        wa = *(unsigned int *)a;
        wb = *(unsigned int *)b;
        while (((wa + 0xfefefeff) & 0x80808080) == 0 && wa == wb) {
            a += 4;
            b += 4;
            wa = *(unsigned int *)a;
            wb = *(unsigned int *)b;
        }
        if (wa == wb)
            return 0;
        return wa > wb ? 1 : -1;
    }

    for (;;) {
        diff = (int)(unsigned char)*a - (int)(unsigned char)*b;
        if (diff != 0)
            return diff;
        if ((unsigned char)*a == 0)
            return 0;
        diff = (int)(unsigned char)*++a - (int)(unsigned char)*++b;
        if (diff != 0)
            return diff;
        if ((unsigned char)*a == 0)
            return 0;
    }
}
}
