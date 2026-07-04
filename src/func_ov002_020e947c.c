// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12i;
typedef short s16;
typedef long long s64;
typedef unsigned long long u64;
struct Vector3 { int x, y, z; };
extern int _ZN4cstd4sqrtEy(u64 v);
extern int __aeabi_idiv(int a, int b);
extern int Vec3_HorzDist(const struct Vector3* a, const struct Vector3* b);
extern s16 Vec3_HorzAngle(const struct Vector3* a, const struct Vector3* b);
void func_ov002_020e947c(char* a0, char* a1, int a2){
  int dy = *(int*)(a1 + 4) - *(int*)(a0 + 0x60);
  int ady = dy < 0 ? -dy : dy;
  int s0 = _ZN4cstd4sqrtEy((u64)(s64)a2);
  int s1 = _ZN4cstd4sqrtEy((u64)(s64)(a2 + ady));
  int s2 = _ZN4cstd4sqrtEy((u64)(s64)a2);
  int t = __aeabi_idiv(s0 * 0x32, s1 + s2);
  int q = __aeabi_idiv(-(a2 << 1), t * t);
  *(int*)(a0 + 0x9c) = q;
  if (*(int*)(a1 + 4) < *(int*)(a0 + 0x60)){
    int aq = q < 0 ? -q : q;
    *(int*)(a0 + 0xa8) = (0x32 - t) * aq;
  } else {
    int aq = q < 0 ? -q : q;
    *(int*)(a0 + 0xa8) = (t + 1) * aq;
  }
  *(int*)(a0 + 0xa0) = -0x32000;
  *(int*)(a0 + 0x98) = Vec3_HorzDist((struct Vector3*)(a0 + 0x5c), (struct Vector3*)a1) / 0x64;
  *(s16*)(a0 + 0x94) = Vec3_HorzAngle((struct Vector3*)(a0 + 0x5c), (struct Vector3*)a1);
}
