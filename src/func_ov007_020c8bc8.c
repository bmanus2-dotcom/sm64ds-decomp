//cpp
// NONMATCHING: different op / idiom (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef long long s64;
extern "C" void func_ov007_020c8bc8(char* r0, int t){
  unsigned char c1 = *(unsigned char*)(r0+0x32);
  unsigned char c0 = *(unsigned char*)(r0+0x30);
  int v2;
  if (t >= 0x1000) { v2 = c1; }
  else if (t <= 0) { v2 = c0; }
  else {
    s64 acc = (s64)t * (c1 << 12);
    acc += (s64)(0x1000 - t) * (c0 << 12);
    v2 = (int)(acc >> 12) >> 12;
  }
  unsigned char d1 = *(unsigned char*)(r0+0x33);
  unsigned char d0 = *(unsigned char*)(r0+0x31);
  int vip;
  if (t >= 0x1000) { vip = d1; }
  else if (t <= 0) { vip = d0; }
  else {
    s64 acc = (s64)t * (d1 << 12);
    acc += (s64)(0x1000 - t) * (d0 << 12);
    vip = (int)(acc >> 12) >> 12;
  }
  if (*(int*)r0 == 3) vip = 0x10 - v2;
  if (*(int*)(r0+4) & 1) *(volatile unsigned short*)0x4000052 = (unsigned short)(v2 | (vip << 8));
  if (*(int*)(r0+4) & 2) *(volatile unsigned short*)0x4001052 = (unsigned short)(v2 | (vip << 8));
}
