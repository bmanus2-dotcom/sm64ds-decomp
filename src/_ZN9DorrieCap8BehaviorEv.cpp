//cpp
extern "C" int _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int a, unsigned int b, void* pos, void* rot, int e, int f);
extern "C" void func_ov001_020ab110(char* c);
extern "C" void func_ov001_020ab228(char* c, char* a1, int idx, int a3, unsigned char a5);
extern "C" void func_ov065_02118c4c(char* c);
extern "C" int func_ov065_021180d4(char* self);
extern "C" void _ZN12CylinderClsn5ClearEv(void* self);
extern "C" void _ZN12CylinderClsn6UpdateEv(void* self);


extern "C" int _ZN9DorrieCap8BehaviorEv(char* p0){
  char* p = *(char**)(p0+0x174);
  if(p == 0) return 1;
  int b = (*(int*)(p0+0xb0) & 0x20000) != 0;
  if(b != 0){
    char* s = (char*)_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0x10d, 0x1210, p0+0x5c, p0+0x8c, *(signed char*)(p0+0xcc), -1);
    if(s != 0){
      *(int*)(s+0xd0) = *(int*)(p0+0xd0);
      *(char**)(*(char**)(p0+0xd0)+0x360) = s;
      int* qs = (int*)(((int)s + 0xb0) & 0xFFFFFFFFFFFFFFFFull);
      *qs = *qs | 0x20000;
      int* qt = (int*)(((int)p0 + 0xb0) & 0xFFFFFFFFFFFFFFFFull);
      *qt = *qt & ~0x20000;
      *(int*)(p0+0xd0) = 0;
      func_ov001_020ab110(p0+0xd4);
      func_ov001_020ab228(p0+0xd4, p0, 2, 0, 0);
    }
    return 1;
  }
  p = (char*)(((int)p + 0xd8) & 0xFFFFFFFFFFFFFFFFull);
  *(int*)(p0+0x5c) = *(int*)p;
  *(int*)(p0+0x60) = *(int*)(p+4);
  *(int*)(p0+0x64) = *(int*)(p+8);
  *(short*)(p0+0x8c) = *(short*)(*(char**)(p0+0x174)+0xe4);
  *(short*)(p0+0x8e) = *(short*)(*(char**)(p0+0x174)+0x8e);
  if(((unsigned int)*(unsigned char*)(p0+0xef) << 30) >> 31){
    func_ov065_02118c4c(p0);
    if(func_ov065_021180d4(p0) != 0){
      _ZN12CylinderClsn5ClearEv(p0+0x140);
      return 1;
    }
    _ZN12CylinderClsn5ClearEv(p0+0x140);
    _ZN12CylinderClsn6UpdateEv(p0+0x140);
  }
  return 1;
}
