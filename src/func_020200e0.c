extern int func_0203da9c(void);
extern int func_0203db4c(int a, int b);
extern void func_0203db3c(int a, unsigned char b);
void func_020200e0(void){
  int x;
  if (func_0203da9c() != 0) return;
  x = func_0203db4c(0, 2);
  func_0203db3c(2, (unsigned char)(x & ~0x20));
}
