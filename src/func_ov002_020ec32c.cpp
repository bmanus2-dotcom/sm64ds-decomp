//cpp
extern "C" {
extern void* _ZN9ActorBasenwEj(unsigned int);
extern void _ZN5ActorC2Ev(void*);
extern void _ZN5ModelD1Ev(void*);
extern void _ZN5ModelC1Ev(void*);
extern void func_020733a8(void* arr, int count, int size, void(*ctor)(void*), void(*dtor)(void*));
extern void* data_ov002_0210ac00[];
int* func_ov002_020ec32c(void){
  int* p = (int*)_ZN9ActorBasenwEj(0x264);
  if(p){
    _ZN5ActorC2Ev(p);
    *(void***)p = (void**)data_ov002_0210ac00;
    func_020733a8((char*)p+0xd4, 5, 0x50, _ZN5ModelC1Ev, _ZN5ModelD1Ev);
  }
  return p;
}
}
