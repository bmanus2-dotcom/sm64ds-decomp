//cpp
extern "C" {
extern int func_0207328c(void*, int, int, void*);
extern void _ZN5ActorD1Ev(void*);
extern int data_ov095_021376f0[];
extern int func_020072c0[];
extern int _ZN19CylinderClsnWithPosD1Ev();
int func_ov095_0213682c(char* c){
  *(int**)c = data_ov095_021376f0;
  func_0207328c((char*)c+0x3a4, 0xc, 0xc, (void*)func_020072c0);
  func_0207328c((char*)c+0xd4, 0xc, 0x3c, (void*)&_ZN19CylinderClsnWithPosD1Ev);
  _ZN5ActorD1Ev(c);
  return (int)c;
}
}
