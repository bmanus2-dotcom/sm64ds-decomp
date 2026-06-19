int _ZN4cstd4sqrtEy(unsigned long long x){
  volatile unsigned short *ime = (volatile unsigned short*)0x4000208;
  unsigned short saved = *ime;
  *ime = 0;
  *(volatile unsigned short*)0x40002b0 = 1;
  *(volatile unsigned long long*)0x40002b8 = x << 2;
  *ime;
  *ime = saved;
  while(*(volatile unsigned short*)0x40002b0 & 0x8000);
  return (*(volatile int*)0x40002b4 + 1) >> 1;
}
