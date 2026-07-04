//cpp
// NONMATCHING: base materialization / addressing (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int id, int a, int b, int c);
extern void func_02012694(int a, void* p);
extern void _ZN9ActorBase18MarkForDestructionEv(void* a);
void func_ov079_02126794(char* c) {
  int* p128;
  short* p8c;
  int* p60;
  if (*(unsigned short*)(c + 0x100) == 0) {
    *(int*)(c + 0x98) = -0x1e000;
    p128 = (int*)(c + 0x128);
    *p128 = *p128 | 1;
  }
  p8c = (short*)(c + 0x8c);
  p60 = (int*)(c + 0x60);
  *p8c = *p8c + 0x2000;
  *p60 = *p60 + 0x14000;
  if (*(unsigned short*)(c + 0x100) <= 0x5a) return;
  _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x8f, *(int*)(c + 0x5c), *p60, *(int*)(c + 0x64));
  func_02012694(0x78, c + 0x74);
  _ZN9ActorBase18MarkForDestructionEv(c);
}
}
