// NONMATCHING: register allocation (div=23). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020d5f2c(char* c, int i){
  char* ip = c + i*0x10 + 0x6000;
  if ((unsigned char)*(unsigned char*)(ip + 0x2ae) >= 4) {
    *(unsigned char*)(ip + 0x2ae) = 4;
    *(unsigned char*)(ip + 0x2ac) = 2;
    return;
  }
  {
    unsigned short* p = (unsigned short*)(c + 0x62a8 + i*0x10);
    *p = *p + 1;
  }
  if (*(unsigned short*)(c + i*0x10 + 0x62a8) < 3)
    return;
  *(unsigned short*)(c + i*0x10 + 0x62a8) = 0;
  {
    unsigned char* q = (unsigned char*)(c + 0x62ae + i*0x10);
    *q = *q + 1;
  }
  if ((unsigned char)*(unsigned char*)(ip + 0x2ae) >= 4) {
    *(unsigned char*)(ip + 0x2ae) = 4;
    *(unsigned char*)(ip + 0x2ac) = 2;
  }
}
