//cpp
// NONMATCHING: base materialization / addressing (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void func_ov002_020da9d4(void* c);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(unsigned int, unsigned int, void*);
extern int _ZN6Player7SetAnimEji5Fix12IiEj(void*, unsigned int, int, int, unsigned int);
void _ZN6Player15St_Grabbed_InitEv(char* c){
  func_ov002_020da9d4(c);
  *(int*)(c+0x2ec) |= 2;
  *(unsigned char*)(c+0x713) = 0;
  *(unsigned char*)(c+0x716) = 1;
  _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(unsigned char*)(c+0x6d9), 6, c+0x74);
  _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x71, 0, 0x1000, 0);
  *(unsigned char*)(c+0x717) = 1;
  *(unsigned char*)(c+0x6e3) = 0;
}
}
