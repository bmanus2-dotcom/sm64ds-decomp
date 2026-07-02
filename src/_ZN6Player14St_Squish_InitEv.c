typedef int Fix12i;
extern void func_ov002_020dab14(void*);
extern int _ZN6Player7SetAnimEji5Fix12IiEj(void*, unsigned int, int, Fix12i, unsigned int);
int _ZN6Player14St_Squish_InitEv(void* c) {
  func_ov002_020dab14(c);
  _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x47, 0, 0x1000, 0);
  *(unsigned char*)((char*)c+0x6e5) = 0;
  *(unsigned char*)((char*)c+0x6e6) = 0;
  *(int*)((char*)c+0x98) = 0;
  *(int*)((char*)c+0xa8) = 0;
  *(int*)((char*)c+0x9c) = 0;
  *(unsigned char*)((char*)c+0x6e3) = 0;
  *(unsigned char*)((char*)c+0x716) = 1;
  *(int*)((char*)c+0x688) = *(int*)((char*)c+0x60);
  {
    int *p = (int *)(((int)c + 0x2ec) & 0xFFFFFFFFFFFFFFFF);
    *p |= 4;
  }
  return 1;
}
