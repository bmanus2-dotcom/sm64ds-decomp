// NONMATCHING: register allocation (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern double func_01ff8708(double x, double y);

double func_020707f4(double x, int *eptr)
{
    int hi = ((int *)&x)[1];
    int lo = ((int *)&x)[0];
    int ix;
    *eptr = 0;
    ix = hi & 0x7fffffff;
    if (ix >= 0x7ff00000 || (ix | lo) == 0) {
        return x;
    }
    if (ix < 0x100000) {
        x = func_01ff8708(x, 0x1.0p54);
        *eptr = -54;
        hi = ((int *)&x)[1];
        ix = hi & 0x7fffffff;
    }
    *eptr += (ix >> 20) - 0x3fe;
    hi = (hi & 0x800fffff) | 0x3fe00000;
    ((int *)&x)[1] = hi;
    return x;
}
