// NONMATCHING: different op / idiom (div=52). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef struct { int x, y, z; } Vec3;
extern void func_020effb8(void* a, void* m, Vec3* v0, Vec3* v1, Vec3* v2, Vec3* v3);
extern int func_02053200(int x);
int func_02008b4c(void* a0, short* p1, int* p2, char* tbl){
  int idx;
  char* elem;
  int i;
  Vec3 v[4];
  int lo, hi, m;
  idx = *p1;
  if (idx + 3 >= *(unsigned char*)tbl) return 1;
  elem = *(char**)(tbl + 4) + (idx << 3);
  if (*(signed char*)elem < 0 || *(signed char*)(elem + 8) < 0 || *(signed char*)(elem + 0x10) < 0) return 1;
  for (i = 0; i < 4; i++) {
    short* s = (short*)(elem + (i << 3));
    v[i].x = s[1] << 12;
    v[i].y = s[2] << 12;
    v[i].z = s[3] << 12;
  }
  func_020effb8(a0, *(void**)p2, &v[0], &v[1], &v[2], &v[3]);
  lo = 0;
  hi = 0;
  if (*(unsigned char*)(elem + 9) != 0) lo = func_02053200(*(unsigned char*)(elem + 9) << 12);
  if (*(unsigned char*)(elem + 0x11) != 0) hi = func_02053200(*(unsigned char*)(elem + 0x11) << 12);
  m = *p2;
  *p2 = m + lo + (int)(((long long)(hi - lo) * m + 0x800) >> 12);
  if (*p2 >= 0x1000) {
    *p1 = *p1 + 1;
    *p2 = *p2 - 0x1000;
  }
  return 0;
}
