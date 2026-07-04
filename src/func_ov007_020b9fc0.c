// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN4cstd3divEii(int, int);
extern int **data_ov007_02104b9c;
extern int *data_ov007_02104ba0;
int func_ov007_020b9fc0(void)
{
    int **d = data_ov007_02104b9c;
    int *p1 = d[1];
    int *p2 = d[2];
    int *p = (int*)((char*)p1 + 0x50);
    int *q = (int*)((char*)p2 + 0x50);
    if (*p < 0x1f000) {
        if (*(short*)( *(int*)((char*)data_ov007_02104ba0 + 8) ) == 5) {
            *p = 0x1f000;
        }
    } else {
        *q -= 0x1000;
        if (*q <= 0) *q = 0;
        data_ov007_02104ba0[0x40/4] = _ZN4cstd3divEii(*q, 0x1f);
    }
    return *q == 0;
}
