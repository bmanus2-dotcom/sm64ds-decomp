//cpp
// NONMATCHING: different op / idiom (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" int func_ov085_0212d2b8(void*);
extern "C" int data_ov085_0213072c[];

struct Sub {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void m5(int);
};

extern "C" int func_ov085_0212d39c(char* c){
  short *p = (short*)(c+0x8e);
  if(*(int**)(c+0x188) == data_ov085_0213072c){
    *p = *p + 0x500;
  }
  func_ov085_0212d2b8(c);
  Sub* o = (Sub*)(c+0x110);
  o->m5(0);
  return 1;
}
