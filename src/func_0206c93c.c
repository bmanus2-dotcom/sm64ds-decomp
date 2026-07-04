// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
unsigned int func_0206c93c(unsigned int x, unsigned int base)
{
    switch (base) {
    case 2:  return x >> 1;
    case 8:  return x >> 3;
    case 0x10: return x >> 4;
    case 0xa: return x / 10;
    }
    return 0;
}
