//cpp
// NONMATCHING: different op / idiom (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void func_ov006_021050bc(void* c);
void func_ov006_0210713c(char* c) {
  if (*(int*)(c + 0x4cac) == 0) {
    func_ov006_021050bc(c);
    *(unsigned char*)(c + 0x4fe7) = 0;
    *(unsigned char*)(c + 0x4fe8) = 2;
    return;
  }
  {
    unsigned char* p = (unsigned char*)(c + 0x4fe7);
    *p = *p + 1;
  }
  if (*(unsigned char*)(c + 0x4fe7) >= 8) {
    unsigned char* q = (unsigned char*)(c + 0x4fe8);
    *(unsigned char*)(c + 0x4fe7) = 0;
    *q = *q - 1;
  }
  if (*(unsigned char*)(c + 0x4fe8) == 0)
    *(int*)(c + 0x4ca8) = 2;
}
}
