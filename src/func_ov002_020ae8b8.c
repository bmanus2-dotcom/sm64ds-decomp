// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned short data_ov002_020ff01c[];
void func_ov002_020ae8b8(char* c, char* arg){
  int eq = (*(unsigned short*)(arg+0xc) == 0xbf);
  if (eq == 0) {
    *(int*)(c+0x98) = 0xa000;
    *(int*)(c+0xa8) = 0x28000;
  } else {
    int v = *(int*)(arg+8);
    int t = data_ov002_020ff01c[(unsigned short)v];
    int r4 = t << 3;
    *(int*)(c+0x98) = (r4 << 12) / 100;
    *(int*)(c+0xa8) = ((r4 / 100) + 0x20) << 12;
  }
  *(int*)(c+0xb0) &= ~1;
}
