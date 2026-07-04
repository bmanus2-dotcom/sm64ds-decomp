//cpp
// NONMATCHING: different op / idiom (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void func_ov004_020af68c(void* a0, int a1, int a2, int a3, int a4);
extern void* data_ov006_0213f730[];
void func_ov006_02119bdc(char* c) {
  int i;
  char* o = c;
  for (i = 0; i < 10; i++) {
    if (*(unsigned char*)(o + 0x50f6) != 0 && *(unsigned char*)(o + 0x50f5) != 0) {
      int a1 = *(int*)(o + 0x50e8) >> 12;
      int a2 = *(int*)(o + 0x50ec) >> 12;
      int a4 = (*(int*)(c + 0x5608) != 1) ? 1 : 0;
      unsigned char sel = *(unsigned char*)(o + 0x50f7);
      func_ov004_020af68c(data_ov006_0213f730[sel], a1, a2, -1, a4);
    }
    o += 0x14;
  }
}
}
