extern void _ZN4cstd10fdiv_asyncE5Fix12IiE5Fix12IiE(int a, int b);
long long _ZN4cstd4ldivEii(int a, int b){
  _ZN4cstd10fdiv_asyncE5Fix12IiE5Fix12IiE(a, b);
  while(*(volatile unsigned short*)0x4000280 & 0x8000);
  return *(volatile long long*)0x40002a0;
}
