int func_ov004_020ae06c(char* c){
  char* r0 = *(char**)(c+4);
  if(r0 == 0) return 1;
  int (*vfn)(void*) = (int(*)(void*))*(int*)(*(int*)r0 + 0x60);
  return vfn(r0);
}
