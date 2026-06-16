//cpp
struct Base { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void M(void*); };
struct Sub : Base { };
struct C { char p1[0x30c]; Sub sub; };
extern "C" int func_ov073_02121870(C* c){
  c->sub.M((char*)c+0x80);
  return 1;
}
