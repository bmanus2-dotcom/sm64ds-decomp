// NONMATCHING: different op / idiom (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vec3 { int x, y, z; };
struct PathPtr { int a, b; };
extern void PathPtr_ctor(struct PathPtr* p);
extern void PathPtr_FromID(struct PathPtr* p, unsigned id);
extern void PathPtr_GetNode(struct PathPtr* p, struct Vec3* out, unsigned i);
extern void Vec3_Sub(struct Vec3* out, struct Vec3* a, struct Vec3* b);
extern int LenVec3(struct Vec3* v);
extern void SetAnim(void* thiz, void* f, int a, int frame, unsigned g);
extern void* data_ov081_02128d98[];

int func_ov081_0212538c(char* c){
  struct PathPtr pp;
  PathPtr_ctor(&pp);
  PathPtr_FromID(&pp, *(unsigned*)(c+0x418));
  struct Vec3 node;
  PathPtr_GetNode(&pp, &node, *(unsigned*)(c+0x424));
  node.y = *(int*)(c+0x60);
  struct Vec3 diff;
  Vec3_Sub(&diff, (struct Vec3*)(c+0x5c), &node);
  int len = LenVec3(&diff);
  *(int*)(c+0x458) = 0xa000;
  *(int*)(c+0x408) = 0;
  if (len == 0 || len <= *(int*)(c+0x458)) {
    *(int*)(c+0x5c) = node.x;
    *(int*)(c+0x60) = node.y;
    *(int*)(c+0x64) = node.z;
    (*(int*)(c+0x424))++;
    if (*(int*)(c+0x424) >= *(int*)(c+0x420)) *(int*)(c+0x424) = 0;
    *(int*)(c+0x408) = 1;
  }
  *(short*)(c+0x100) = 0xa;
  SetAnim(c+0x30c, data_ov081_02128d98[1], 0, 0x1000, 0);
  return 1;
}
