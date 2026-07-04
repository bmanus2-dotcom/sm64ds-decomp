//cpp
// NONMATCHING: different op / idiom (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" int func_ov006_020d836c(void);
extern "C" void func_ov006_020d7604(void*);
extern "C" void func_ov006_020d5e1c(void*);
struct E { char d[0x40]; };
extern "C" void func_ov006_020d8cc4(char* r5){
  func_ov006_020d836c();
  int c4 = 0;
  int c2 = 0;
  int i = 0;
  do {
    char* e = (char*)&((E*)(r5 + 0x4000))[i];
    if (*(unsigned char*)(e+0x698) != 0 && *(unsigned char*)(e+0x697) == 6) {
      unsigned char v = *(unsigned char*)(e+0x69b);
      if (v != 2) c2++;
      if (v != 4) c4++;
    }
    i++;
  } while (i < 0x70);
  if (c2 == 0 && *(unsigned char*)(r5+0x6000+0x2f4) == 0) {
    func_ov006_020d7604(r5);
  }
  if (c4 != 0) return;
  func_ov006_020d5e1c(r5);
  *(short*)(r5+0x6200+0xe8) = 0x10;
  *(int*)(r5+0x6000+0x2d4) = 2;
  *(unsigned char*)(r5+0x6000+0x2f9) = 1;
}
