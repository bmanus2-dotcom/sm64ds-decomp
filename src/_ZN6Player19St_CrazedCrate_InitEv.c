//cpp
// NONMATCHING: base materialization / addressing (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern int _ZN6Player7SetAnimEji5Fix12IiEj(void*, unsigned int, int, int, unsigned int);
extern void func_ov002_020e0f38(void* c, unsigned char a);
int _ZN6Player19St_CrazedCrate_InitEv(char* c){
  *(unsigned char*)(c+0x71b) = 0;
  *(unsigned char*)(c+0x712) = 1;
  *(unsigned char*)(c+0x70d) = 0;
  *(unsigned char*)(c+0x6e1) = 0;
  *(unsigned char*)(c+0x6de) = 1;
  *(unsigned char*)(c+0x6df) = 0;
  _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x43, 0x40000000, 0x1000, 0);
  func_ov002_020e0f38(c, *(unsigned char*)(c+0x6e1));
  *(unsigned short*)(c+0x94) = *(short*)(c+0x8e);
  *(int*)(c+0x2ec) |= 0x20;
  return 1;
}
}
