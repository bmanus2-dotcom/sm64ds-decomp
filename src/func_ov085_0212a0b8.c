extern void Actor__UpdatePos(void*, void*);
extern int func_ov085_02129ebc(void*, void*);
extern int func_ov085_02129f8c(void*);
int func_ov085_0212a0b8(char* c){
  Actor__UpdatePos(c, c+0x160);
  func_ov085_02129ebc(c, c+0x194);
  func_ov085_02129f8c(c);
  return 1;
}
