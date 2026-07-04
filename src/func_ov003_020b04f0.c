//cpp
// NONMATCHING: base materialization / addressing (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void* _ZN9ActorBasenwEj(unsigned int);
extern void _ZN9ActorBaseC1Ev(void*);
extern void _ZN5ModelD1Ev(void*);
extern void _ZN5ModelC1Ev(void*);
extern void func_020733a8(void* arr, int count, int size, void(*ctor)(void*), void(*dtor)(void*));
extern void* data_0208e4b8[];
extern void* data_02092680[];
extern void* data_ov003_020b1704[];

void* func_ov003_020b04f0(void){
  char* p = (char*)_ZN9ActorBasenwEj(0x13c);
  if(p){
    _ZN9ActorBaseC1Ev(p);
    *(void***)p = (void**)data_0208e4b8;
    *(void***)p = (void**)data_02092680;
    unsigned char* fl = (unsigned char*)(p+0x13);
    *fl |= 1;
    *fl |= 4;
    *(void***)p = (void**)data_ov003_020b1704;
    func_020733a8(p+0x64, 2, 0x50, _ZN5ModelC1Ev, _ZN5ModelD1Ev);
  }
  return p;
}
}
