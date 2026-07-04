// NONMATCHING: register allocation (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN4cstd3divEii(int,int);
int func_ov007_020c3598(int sl, int sb, char* r8, int fp){
  int res = 0;
  int fnd = 0;
  int r7 = 1;
  int r2;
  for (r2 = 0; r2 < sb-1; r2++) r7 = r7 * fp;
  int r4;
  for (r4 = 0; r4 < sb; r4++) {
    int neg1 = -1;
    int one = 1;
    int r6 = (sb-1) - r4;
    char* r5 = r8 + r6;
    r8[r6] = (char)_ZN4cstd3divEii(sl, r7);
    sl -= r7 * (signed char)r8[r6];
    r7 = _ZN4cstd3divEii(r7, fp);
    if (fnd == 0) {
      if ((signed char)*r5 != 0) { fnd = one; res = r6+1; }
      else if (r6 > 0) *r5 = neg1;
    }
  }
  return res;
}
