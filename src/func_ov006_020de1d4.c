// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern char* func_020beb68;
extern void func_ov006_020dc370(void*);
void* func_ov006_020de1d4(char* c){
  char* q = c + 0x5000;
  int* p = (int*)(c + 0x51cc);
  if (*(int*)(q + 0x1cc) != 0) {
    *p = *p - 1;
    if (*(int*)(q + 0x1cc) < 0) *(int*)(q + 0x1cc) = 0;
    return c;
  }
  {
    char* o = func_020beb68;
    int v = o != 0 ? *(int*)(o + 0xa8) : 0;
    if (v != 0) {
      *(unsigned char*)(c + 0x51de) = 0;
      func_ov006_020dc370(c);
      *(int*)(c + 0x51cc) = 0xc0;
      *(int*)(c + 0x51c8) = 5;
    }
  }
  return c;
}
