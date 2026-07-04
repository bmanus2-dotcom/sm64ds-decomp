// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vec3 { int x, y, z; };
extern signed char NumRedCoins(void);
extern void* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int id, unsigned int p, struct Vec3* pos, void* rot, int a, int b);
extern void _ZN9PowerStar13AddStarMarkerEv(void* p);
void _ZN10StarMarker27SpawnRedCoinStarIfNecessaryEv(char* c){
  struct Vec3 v;
  char* star;
  int y;
  if(((unsigned int)*(unsigned char*)(c+0x1db) << 29) >> 31) return;
  if(NumRedCoins() != 8) return;
  v.x = *(int*)(c+0x5c);
  y = *(int*)(c+0x60);
  v.y = y;
  v.z = *(int*)(c+0x64);
  v.y = y + 0x78000;
  star = (char*)_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0xb2, *(unsigned char*)(c+0x1d9), &v, 0, *(signed char*)(c+0xcc), -1);
  if(star == 0) return;
  _ZN9PowerStar13AddStarMarkerEv(star);
  *(unsigned short*)(star+0x4a2) |= 0x1000;
  *(int*)(star+0x434) = *(int*)(c+4);
  *(unsigned char*)(c+0x1db) |= 4;
}
