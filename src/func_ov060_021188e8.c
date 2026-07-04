// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov060_021184bc(void* c);
void func_ov060_021188e8(char* c){
  int* p = (int*)(c+0x13c);
  *p |= 1;
  int v = *(unsigned short*)(c+0x100+0xac);
  int x = (v * 9) << 12;
  int r = x / 14 + 0x1000;
  *(int*)(c+0x80) = r;
  *(int*)(c+0x84) = r;
  *(int*)(c+0x88) = r;
  if(*(unsigned short*)(c+0x100+0xac) == 0x1c){
    func_ov060_021184bc(c);
    unsigned short* q = (unsigned short*)(c+0x1ac);
    *q = *q + 1;
  }
}
