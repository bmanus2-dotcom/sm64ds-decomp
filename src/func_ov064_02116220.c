//cpp
// NONMATCHING: register allocation (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
typedef struct { int x, y, z; } Vector3;
typedef struct Actor Actor;
typedef struct BCA_File BCA_File;
struct RaycastGround { char buf[0x50]; };
void _ZN13RaycastGroundC1Ev(RaycastGround* self);
void _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(RaycastGround* self, const Vector3* p, Actor* a);
int _ZN13RaycastGround10DetectClsnEv(RaycastGround* self);
int func_02037e38(unsigned int* p);
void _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void* self, BCA_File* f, int a, int b, unsigned int e);
void _ZN13RaycastGroundD1Ev(RaycastGround* self);

void func_ov064_02116220(char* c){
  RaycastGround rg;
  _ZN13RaycastGroundC1Ev(&rg);
  Vector3 v;
  int vy = *(int*)(c+0x60) + *(int*)(c+0x3ec);
  int vz = *(int*)(c+0x64);
  v.x = *(int*)(c+0x5c);
  v.y = vy + 0x96000;
  v.z = vz;
  _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(&rg, &v, (Actor*)c);
  if (_ZN13RaycastGround10DetectClsnEv(&rg) != 0) {
    *(int*)(c+0x3f4) = *(int*)(rg.buf + 0x44);
    if (*(int*)(c+0x60) <= *(int*)(rg.buf + 0x44) + 0x14000) {
      int r = func_02037e38((unsigned int*)(rg.buf + 0x14));
      if (r == 4 || r == 5 || r == 0x13) {
        *(int*)(c+0x398) = 5;
      } else if (r == 1) {
        *(int*)(c+0x398) = 4;
        _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c+0x110,
            *(BCA_File**)(*(int*)(*(int*)(c+0x330) + 4) + 4), 0, 0x1000, 0);
        int* pb0 = (int*)(c+0xb0);
        *pb0 &= ~1;
        (*(void(**)(void*))(*(int*)c + 0x90))(c);
        *(int*)(c+0x3a8) = *(int*)(c+0x5c);
        *(int*)(c+0x3ac) = *(int*)(c+0x60);
        *(int*)(c+0x3b0) = *(int*)(c+0x64);
        *(int*)(c+0x3ac) = *(int*)(rg.buf + 0x44) + 0x5000;
      }
    }
  }
  _ZN13RaycastGroundD1Ev(&rg);
}
}
