//cpp
extern "C" {
extern void* data_ov002_02110a48[];
extern void _ZN19CylinderClsnWithPosD1Ev(void* self);
extern void _ZN6Memory16operator_delete2EPv(void* p);
int func_ov002_020ec020(char* self){
  char* base=self+0xd4;
  void** pp=data_ov002_02110a48;
  int i;
  for(i=0;i<5;i++,base+=0x50,pp++){
    if(*(void**)(base+0x4c)){
      char* node;
      while((node=(char*)*pp)!=0){
        *pp=*(void**)(node+0x48);
        if(node){
          _ZN19CylinderClsnWithPosD1Ev(node+0xc);
          _ZN6Memory16operator_delete2EPv(node);
        }
      }
    }
  }
  return 1;
}
}
