struct S { int w[2]; };
extern struct S G;
void func_ov004_020b743c(char *p) { *(int *)(p + 0x1c) = 10; *(struct S *)(p + 0x8) = G; }
