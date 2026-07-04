// NONMATCHING: different op / idiom (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_02012790(int x);
void func_ov063_0211cae8(char* c, int m){
  unsigned char* p = (unsigned char*)(c+0x157);
  *p |= m;
  unsigned char v = c[0x157] & 7;
  if(v!=1 && v!=3 && v!=7){ func_02012790(0xe); return; }
  func_02012790(0x26);
}
