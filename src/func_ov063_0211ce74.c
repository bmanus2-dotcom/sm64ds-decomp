//cpp
// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void func_ov063_0211c684(char* c);
extern int func_ov063_0211c6f8(char* c);
}
struct C;
typedef void (C::*PMF)();
extern PMF data_ov063_0211ef38[];

extern "C" int func_ov063_0211ce74(char* c);
extern "C" int func_ov063_0211ce74(char* c){
  unsigned char before = *(unsigned char*)(c + 0x150);
  int idx = *(int*)(c + 0x140);
  C* obj = (C*)c;
  (obj->*data_ov063_0211ef38[idx])();
  unsigned short* ctr = (unsigned short*)(c + 0x14c);
  *ctr = *ctr + 1;
  if (before != *(unsigned char*)(c + 0x150)) {
    *(unsigned short*)(c + 0x100 + 0x4c) = 0;
  }
  func_ov063_0211c684(c);
  func_ov063_0211c6f8(c);
  *(int*)(c + 0x124) = 0;
  return 1;
}
