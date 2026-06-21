//cpp
extern "C" {
extern int data_ov002_0211067c[];
extern int data_ov002_0211013c[];
extern int func_ov002_020bea7c(char* c);
extern void func_ov002_020c43c4(char* self, int n);
extern void _ZN6Player11ChangeStateERNS_5StateE(void*,void*);
int func_ov002_020c9288(char* self){
  if(!func_ov002_020bea7c(self)){
    if(*(unsigned char*)(self+0x6e6)==0){
      func_ov002_020c43c4(self,6);
      *(unsigned char*)(self+0x6e6)=1;
    }else if(*(unsigned char*)(self+0x706)){
      _ZN6Player11ChangeStateERNS_5StateE(self,data_ov002_0211067c);
    }else{
      _ZN6Player11ChangeStateERNS_5StateE(self,data_ov002_0211013c);
    }
  }
  return 0;
}
}
