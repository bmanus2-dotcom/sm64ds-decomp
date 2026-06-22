extern void Matrix4x3_FromRotationY(void* m, int angle);
struct M48 { int w[12]; };
void func_ov002_020b9a1c(char* t){
  Matrix4x3_FromRotationY(t+0x140, *(short*)(t+0x8e));
  *(int*)(t+0x164) = *(int*)(t+0x5c) >> 3;
  *(int*)(t+0x168) = *(int*)(t+0x60) >> 3;
  *(int*)(t+0x16c) = *(int*)(t+0x64) >> 3;
  *(struct M48*)(t+0xf0) = *(struct M48*)(t+0x140);
}
