// NONMATCHING: different op / idiom (div=36). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int data_ov006_02141f8c[];

typedef void (*Fn)(void*, int);

void func_ov006_020e8830(char* base, int idx){
  char* e = base + idx*0x20;
  unsigned char b = *(unsigned char*)(e + 0x52da);
  int* ent = &data_ov006_02141f8c[b*2];
  int adj = ent[1];
  void* obj = base + (adj >> 1);
  Fn fn;
  if(adj & 1){
    void* vt = *(void**)obj;
    fn = *(Fn*)((char*)vt + ent[0]);
  }else{
    fn = (Fn)ent[0];
  }
  fn(obj, idx);

  unsigned char c = *(unsigned char*)(e + 0x52d6);
  *(int*)(base + 0x52c8 + idx*0x20) -= (c<<3) + 0x10;
  int sh = *(unsigned short*)(e + 0x52cc) >> 3;
  if(sh >= 7) sh = 7;
  *(unsigned char*)(e + 0x52d7) = 7 - sh;
  if(*(unsigned short*)(e + 0x52cc) != 0){
    *(unsigned short*)(base + 0x52cc + idx*0x20) -= 1;
    if(*(short*)(e + 0x52cc) < 0) *(short*)(e + 0x52cc) = 0;
  }else{
    *(unsigned char*)(e + 0x52d9) = 0;
  }
}
