int _ZN4cstd11fdiv_resultEv(void){
  while(*(volatile unsigned short*)0x4000280 & 0x8000);
  return (int)((*(volatile long long*)0x40002a0 + 0x80000) >> 20);
}
