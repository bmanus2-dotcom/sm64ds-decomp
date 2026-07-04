//cpp
// NONMATCHING: constant / value (div=26). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" void* _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
  unsigned int a, unsigned int b, int c, int d, int e, const void* f, void* g);
extern signed char data_0209f2f8;

extern "C" void func_ov002_020cb474(char* c){
  int* r1 = *(int**)(c+0x37c);
  if ((*(int*)((char*)r1+0x18) & 0x1000000) == 0) return;
  if (((*(int*)((char*)r1+8)) >> 2) > *(int*)(c+0x688)) return;
  int x = *(int*)(c+0x5c);
  int y = *(int*)(c+0x60) + 0x32000;
  int z = *(int*)(c+0x64);
  unsigned int id;
  switch (data_0209f2f8) {
    case 0x13:
    case 0xa:
      id = 0xba;
      break;
    case 6:
      id = 0xb8;
      break;
    case 0x10:
      return;
    default:
      id = 0xb9;
      break;
  }
  *(void**)(c+0x628) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    *(unsigned int*)(c+0x628), id, x, y, z, 0, 0);
}
