//cpp
extern "C" {
extern void func_ov007_020c40b4(void *c);
extern int _ZN6Player17St_EndingFly_MainEv(void *p);
extern int func_ov007_020c1180(char *c);

void func_ov007_020c3e7c(char *c){
  int i;
  for(i = 0; i < **(int**)c; i++){
    func_ov007_020c40b4((*(void***)(c+8))[i]);
  }
  _ZN6Player17St_EndingFly_MainEv(*(void**)(c+8));
  func_ov007_020c1180(*(char**)(c+4));
  func_ov007_020c40b4(*(void**)(c+0xc));
  _ZN6Player17St_EndingFly_MainEv(c);
}
}
