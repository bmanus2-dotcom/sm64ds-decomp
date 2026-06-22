//cpp
extern "C" {
extern void func_ov007_020c8440(void *p);
extern void func_ov007_020c8098(void *p);
extern void func_ov007_020c78dc(void *p);
extern int _ZN6Player17St_EndingFly_MainEv(void *p);

void func_ov007_020c9fa0(char *c){
  int i;
  for(i = 0; i < 2; i++){
    func_ov007_020c8440(((void**)(c + 0x50))[i]);
    func_ov007_020c8440(((void**)(c + 0x58))[i]);
    func_ov007_020c8098(((void**)(c + 0x60))[i]);
    func_ov007_020c8098(((void**)(c + 0x68))[i]);
  }
  func_ov007_020c78dc(*(void**)(c+0x1c));
  _ZN6Player17St_EndingFly_MainEv(*(void**)(c+0x18));
  _ZN6Player17St_EndingFly_MainEv(c);
}
}
