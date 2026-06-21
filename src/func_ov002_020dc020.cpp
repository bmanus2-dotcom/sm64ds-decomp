//cpp
struct Vector3 { int x, y, z; };
extern "C" {
extern void func_ov002_020dc174(char* self, const Vector3& v, int fix, int d, unsigned int stackA, unsigned int stackB);
void func_ov002_020dc020(char* self){
  Vector3 v;
  int fix, d;
  if(!*(unsigned char*)(self+0x703)){
    v.x=0; v.y=0xa000; v.z=0x3c000;
    d=0x46000; fix=0x28000;
  }else{
    v.x=0; v.y=0x40000; v.z=0xc0000;
    d=0x100000; fix=0x80000;
  }
  func_ov002_020dc174(self, v, fix, d, 0x1000, 0);
}
}
