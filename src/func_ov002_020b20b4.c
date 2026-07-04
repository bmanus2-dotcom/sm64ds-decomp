//cpp
// NONMATCHING: different op / idiom (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void func_ov002_020b1008(void* c);
extern int _ZN5Event6GetBitEj(unsigned int b);
extern void* _ZN5Actor15FindWithActorIDEjPS_(unsigned int id, void* start);
void func_ov002_020b20b4(char* c){
  func_ov002_020b1008(c);
  if (*(unsigned char*)(c+0x3ae) & 1) return;
  if (_ZN5Event6GetBitEj(*(unsigned char*)(c+0x3ab)) == 0) return;
  *(unsigned char*)(c+0x3ae) = (*(unsigned char*)(c+0x3ae) & ~1) | 1;
  *(int*)(c+0x3a4) = 4;
  *(int*)(c+0x190) &= ~1;
  char* found = (char*)_ZN5Actor15FindWithActorIDEjPS_(0xa, 0);
  if (found) {
    *(short*)(c+0x3a8) = *(unsigned short*)(found+0x32a);
  } else {
    *(short*)(c+0x3a8) = 0xfa;
  }
}
}
