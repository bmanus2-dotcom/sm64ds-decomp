//cpp
struct Vec3 { int x, y, z; };
extern "C" signed char NumRedCoins(void);
extern "C" void* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int id, unsigned int p, struct Vec3* pos, void* rot, int a, int b);
extern "C" void _ZN9PowerStar13AddStarMarkerEv(void* p);
extern "C" void _ZN10StarMarker27SpawnRedCoinStarIfNecessaryEv(char* c){
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
  *(unsigned short*)(((int)star + 0x4a2) & 0xFFFFFFFFFFFFFFFF) |= 0x1000;
  *(int*)(star+0x434) = *(int*)(c+4);
  *(unsigned char*)(((int)c + 0x1db) & 0xFFFFFFFFFFFFFFFF) |= 4;
}
