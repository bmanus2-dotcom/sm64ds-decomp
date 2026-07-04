// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int s32;
typedef struct { s32 x, y, z; } Vector3;
extern void Matrix4x3_FromRotationY(void* m, int angle);
extern void Matrix4x3_ApplyInPlaceToRotationX(void* m, short angX);
extern void MulVec3Mat4x3(const Vector3* v, const void* m, Vector3* res);
extern int data_020a0e68[];

void func_ov062_0211b2fc(char* c){
  Vector3 v;
  Vector3 w;
  v.z = 0;
  v.x = 0;
  v.y = 0;
  v.z = 0x14000;
  w.x = 0;
  w.y = 0;
  w.z = 0;
  v.x = 0;
  v.y = 0;
  v.z = 0x14000;
  if (*(int*)(c+0x468) == 0 && *(int*)(c+0x44c) == 0) {
    if (*(unsigned short*)(c+0x444) == 0) {
      short* a = (short*)(c+0x94);
      *a = *a - 0x100;
    }
  }
  v.z = 0x28000;
  Matrix4x3_FromRotationY(data_020a0e68, *(short*)(c+0x8e));
  Matrix4x3_ApplyInPlaceToRotationX(data_020a0e68, *(short*)(c+0x8c));
  MulVec3Mat4x3(&v, data_020a0e68, (Vector3*)(c+0xa4));
  (void)w;
}
