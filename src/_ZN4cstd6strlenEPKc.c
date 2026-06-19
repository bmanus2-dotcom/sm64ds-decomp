unsigned int _ZN4cstd6strlenEPKc(const char *s){
  int n = -1;
  unsigned char c;
  do { c = *s++; n = n + 1; } while(c != 0);
  return n;
}
