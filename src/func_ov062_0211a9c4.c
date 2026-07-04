// NONMATCHING: register allocation (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vec3 { int x, y, z; };
extern void* ClosestPlayer(void);
extern int Vec3_Dist(struct Vec3* a, struct Vec3* b);
extern int StartTalk(void* thiz, void* ref, int b);
extern void* FindWithActorID(unsigned id, void* p);
extern short Vec3_HorzAngle(struct Vec3* a, struct Vec3* b);

void func_ov062_0211a9c4(char* c){
  unsigned short cnt = *(unsigned short*)(c+0x100);
  if (cnt) { *(unsigned short*)(c+0x100) = cnt-1; return; }
  *(void**)(c+0x398) = ClosestPlayer();
  void* p = *(void**)(c+0x398);
  if (p == 0) return;
  struct Vec3* sp = (struct Vec3*)((char*)p + 0x5c);
  struct Vec3 v;
  v.x = sp->x;
  v.y = sp->y;
  v.z = sp->z;
  if (Vec3_Dist((struct Vec3*)(c+0x5c), &v) >= 0xc8000) return;
  if (StartTalk(*(void**)(c+0x398), c, 1) == 0) return;
  char* a = (char*)FindWithActorID(0xcd, 0);
  if (a == 0) return;
  *(int*)(c+0x394) = *(int*)(a+4);
  *(unsigned char*)(a+0x16e) = 0;
  *(int*)(c+0x38c) = 1;
  *(short*)(c+0x3a8) = Vec3_HorzAngle((struct Vec3*)(c+0x5c), &v);
  *(unsigned char*)(c+0x390) = 0;
}
