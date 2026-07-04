// NONMATCHING: different op / idiom (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vec3 { int x, y, z; };
extern void _ZN6Player7SetAnimEji5Fix12IiEj(char* c, unsigned int anim, int a, int fix, unsigned int z);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(unsigned int a, unsigned int b, void* v);
extern void _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(char* o, struct Vec3* p);
int _ZN6Player17St_LedgeHang_InitEv(char* c){
  struct Vec3 z3;
  struct Vec3 off;
  *(unsigned short*)(c+0x600+0xa6) = 0;
  if(*(unsigned char*)(c+0x6e3) == 0){
    _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x22, 0x40000000, 0x1000, 0);
  }else{
    _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x21, 0, 0x1000, 0);
  }
  *(unsigned short*)(c+0x600+0xa6) = 2;
  *(short*)(c+0x94) = *(short*)(c+0x8e);
  *(int*)(c+0xa8) = 0;
  *(int*)(c+0x98) = 0;
  *(unsigned char*)(c+0x6de) = 0;
  _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(unsigned char*)(c+0x6d9), 0x16, c+0x74);
  z3.x = 0;
  z3.y = 0;
  z3.z = 0;
  off.x = -0x64000;
  off.y = z3.x;
  off.z = -0x64000;
  off.x = z3.z;
  _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(c+0x2d4, &off);
  *(unsigned char*)(c+0x6e6) = 0;
  return 1;
}
