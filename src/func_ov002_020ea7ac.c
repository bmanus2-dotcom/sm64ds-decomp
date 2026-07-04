// NONMATCHING: constant / value (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov002_020e9464(char *p);
extern void func_ov002_020e7e24(char *thiz);
extern void func_ov002_020e81e0(char *p);
extern void func_ov002_020e7d08(char *p);
void func_ov002_020ea7ac(char* c){
  if(*(int*)(c+0xa8) <= -0x18000){
    int* f = (int*)(c+0x128);
    func_ov002_020e9464(c);
    *f &= ~1;
  }else{
    if(*(int*)(c+0x9c) == 0){
      *(int*)(c+0x440) = 4;
      *(unsigned short*)(c+0x400+0x96) = 0x1d6;
    }else{
      func_ov002_020e7e24(c);
    }
  }
  func_ov002_020e81e0(c);
  func_ov002_020e7d08(c);
}
