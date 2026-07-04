// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern char* data_020a9db8;
void func_02065f08(int idx){
  char* b = data_020a9db8 + idx * 0x5c4;
  if(*(unsigned char*)(b + 0x1d4a) == 0) return;
  unsigned short r1 = *(unsigned short*)(b + 0x1d44);
  if(r1 == 0) return;
  {
    unsigned short lo = *(unsigned short*)(b + 0x1d40);
    unsigned short hi = *(unsigned short*)(b + 0x1d42);
    if(hi <= lo){
      if((int)lo <= (int)hi + 2){
        unsigned short* p = (unsigned short*)(b + 0x1d40);
        *p = *p + 1;
        return;
      }
    }
    *(unsigned short*)(b + 0x1d40) = hi;
  }
}
