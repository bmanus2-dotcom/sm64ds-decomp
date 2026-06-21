//cpp
extern "C" {
extern int data_ov002_021102bc[];
extern int data_ov002_02110484[];
extern int _ZN6Player7IsStateERNS_5StateE(void*,void*);
extern void _ZN6Player11ChangeStateERNS_5StateE(void*,void*);
int func_ov002_020de33c(char* self, int a1){
  if(!*(unsigned char*)(self+0x709)){
    if(!_ZN6Player7IsStateERNS_5StateE(self,data_ov002_021102bc)){
      if(!_ZN6Player7IsStateERNS_5StateE(self,data_ov002_02110484)) goto ok;
    }
  }
  return 0;
ok:
  *(int*)(self+0x364)=a1;
  _ZN6Player11ChangeStateERNS_5StateE(self,data_ov002_021102bc);
  return 1;
}
}
