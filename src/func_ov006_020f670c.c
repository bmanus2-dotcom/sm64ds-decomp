// NONMATCHING: register allocation (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void* func_ov006_020f670c(char* c){
  int cnt = 0;
  int i;
  char* p = c;
  for (i = 0; i < 0x14; i++) {
    char* b = p + 0x5000;
    if (*(unsigned char*)(b + 0x1bb) != 0) {
      if (*(unsigned char*)(b + 0x1bc) != 1) cnt++;
    }
    p += 0x18;
  }
  if (cnt != 0) return c;
  p = c;
  for (i = 0; i < 0x14; i++) {
    *(unsigned char*)(p + 0x51bc) = 2;
    p += 0x18;
  }
  *(int*)(c + 0x53d8) = 0;
  *(int*)(c + 0x53d4) = 2;
}
