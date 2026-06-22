//cpp
extern "C" {
extern int data_ov002_0210ac00[];
extern int data_020a0eac[];
extern int _ZN5ModelD1Ev[];
void func_0207328c(void*, int, int, void*);
void _ZN5ActorD1Ev(void*);
void _ZN6Memory10DeallocateEPvP4Heap(void*, void*);
void* func_ov002_020ebfcc(char* c){
  *(int*)c = (int)data_ov002_0210ac00;
  func_0207328c(c+0xd4, 5, 0x50, (void*)_ZN5ModelD1Ev);
  _ZN5ActorD1Ev(c);
  _ZN6Memory10DeallocateEPvP4Heap(c, (void*)data_020a0eac[0]);
  return c;
}
}
