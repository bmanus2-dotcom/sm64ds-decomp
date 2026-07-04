// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
int Color_Interp(int a, int c1, int c2, int t) {
  int m0, m1, m2, p0, p1, p2, s;
  if (t >= 0x1000) return c2;
  if (t <= 0) return c1;
  m0 = c2 & 0x1f;
  m1 = c2 & 0x3e0;
  m2 = c2 & 0x7c00;
  p0 = m0 * t;
  p1 = m1 * t;
  p2 = m2 * t;
  s = 0x1000 - t;
  p0 = (c1 & 0x1f) * s + p0;
  p1 = (c1 & 0x3e0) * s + p1;
  p2 = (c1 & 0x7c00) * s + p2;
  return ((p2 | (p0 | p1)) << 4) >> 0x10;
}
