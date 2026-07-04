//cpp
// NONMATCHING: different op / idiom (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
struct Vec3 { int x, y, z; };
extern int func_ov002_020beb38(char* c);
extern unsigned int _ZNK6Player14GetBodyModelIDEjb(char* c, unsigned int a, int b);
extern void MulVec3Mat4x3(void* a, void* b, struct Vec3* out);
extern void Vec3_MulScalar(struct Vec3* out, struct Vec3* in, int s);
extern void* _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
  unsigned int a, unsigned int b, int c, int d, int e, const void* f, void* g);

void func_ov002_020d98b4(char* self){
  *(unsigned short*)(self+0x6a4) -= func_ov002_020beb38(self);
  if (*(short*)(self+0x6a4) < 0) *(short*)(self+0x6a4) = 0;
  {
    unsigned int id = _ZNK6Player14GetBodyModelIDEjb(self, *(int*)(self+8) & 0xff, 0);
    int r5 = *(int*)(*(int*)(self + (id << 2) + 0xdc) + 0x14) + 0x2d0;
    unsigned int id2 = _ZNK6Player14GetBodyModelIDEjb(self, *(int*)(self+8) & 0xff, 0);
    struct Vec3 v;
    struct Vec3 s;
    MulVec3Mat4x3((void*)(r5 + 0x24), (void*)(*(int*)(self + (id2 << 2) + 0xdc) + 0x1c), &v);
    Vec3_MulScalar(&s, &v, 0x8000);
    s.y += 0x50000;
    *(void**)(self+0x628) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
      *(unsigned int*)(self+0x628), 0xd6, s.x, s.y, s.z, 0, 0);
  }
  *(int*)(self+0xb0) |= 0x80;
}
}
