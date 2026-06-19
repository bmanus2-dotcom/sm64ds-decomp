char *_ZN4cstd7strncpyEPcPKcj(char *dst, const char *src, unsigned int n){
  char *d = dst;
  const unsigned char *s = (const unsigned char*)src;
  if(n == 0) return dst;
  do {
    unsigned char c = *s++;
    char *p = d;
    *d++ = c;
    if(*(unsigned char*)p == 0){
      while(--n) *d++ = 0;
      return dst;
    }
  } while(--n);
  return dst;
}
