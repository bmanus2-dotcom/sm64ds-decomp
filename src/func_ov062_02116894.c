//cpp
// NONMATCHING: base materialization / addressing (div=15). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
int func_ov062_02115f84(char* c);
void func_ov062_02116cd8(void*, void*);
int AngleDiff(int a, int b);
int ApproachAngle(void*, int, int, int, int);
extern int data_ov062_0211dee0[];
int func_ov062_02116894(char* c){
  if(*(unsigned short*)(c+0x100) != 0) return 1;
  if(*(int*)(c+0x98) != 0){
    if(func_ov062_02115f84(c) == 0){
      if(*(unsigned char*)(c+0x3e4) == 1){
        *(short*)((c+0x300)+0xf4) = *(short*)(c+0x94) - 0x2000;
        goto angle;
      }
    }
    *(short*)(c+0x94) = *(short*)((c+0x300)+0xf4);
    func_ov062_02116cd8(c, data_ov062_0211dee0);
    *(short*)((c+0x300)+0xe8) = 0x1e;
    *(short*)((c+0x300)+0xf4) = *(short*)(c+0x94);
    return 1;
  }
angle:
  if(AngleDiff(*(short*)((c+0x300)+0xf4), *(short*)(c+0x8e)) < 0x100){
    *(int*)(c+0x98) = 0xa000;
  }
  ApproachAngle(c+0x94, *(short*)((c+0x300)+0xf4), 0xa, 0x200, 0x100);
  return 1;
}
}
