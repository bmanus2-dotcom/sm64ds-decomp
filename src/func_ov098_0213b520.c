// NONMATCHING: different op / idiom (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_0201267c(int, void*);
void func_ov098_0213b520(char* c){
  unsigned char* p;
  *(int*)(c+0x3b8) = 0x600;
  *(int*)(c+0x3bc) = *(int*)(c+0x84);
  p = (unsigned char*)(c+0x3b6);
  *p = *p + 1;
  *(short*)(c+0x3b4) = 0;
  *(int*)(c+0xa8) = 0;
  *(int*)(c+0x98) = 0;
  *(int*)(c+0x3c0) = 0;
  func_0201267c(0xd9, c+0x74);
}
