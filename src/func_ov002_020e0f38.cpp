//cpp
extern "C" {
extern int data_ov002_020ff17c[];
extern int data_ov002_020ff188[];
extern void _ZN5Actor11LandingDustEb(void* self, int b);
extern void func_0201267c(int a, void* p);
void func_ov002_020e0f38(char* self, int type){
  *(int*)(self+0xa8)=data_ov002_020ff17c[type];
  *(int*)(self+0x98)=data_ov002_020ff188[type];
  if(type!=0) _ZN5Actor11LandingDustEb(self,1);
  if(type!=2) func_0201267c(0x6c, self+0x74);
  else func_0201267c(0x6d, self+0x74);
}
}
