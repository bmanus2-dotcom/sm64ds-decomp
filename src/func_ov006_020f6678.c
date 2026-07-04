// NONMATCHING: register allocation (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020f593c(void*);
void func_ov006_020f6678(char* c){
  char* q = c + 0x5300;
  char* p;
  int i;
  if (*(unsigned short*)(q + 0xe2) != 0) {
    unsigned short* h = (unsigned short*)(c + 0x53e2);
    *h = (unsigned short)(*h - 1);
    if (*(short*)(q + 0xe2) > 0) return;
    func_ov006_020f593c(c);
    return;
  }
  p = c;
  for (i = 0; i < 0x14; i++) {
    *(unsigned char*)(p + 0x51bc) = 2;
    p += 0x18;
  }
  *(int*)(c + 0x53d8) = 0;
  *(int*)(c + 0x53d4) = 2;
}
