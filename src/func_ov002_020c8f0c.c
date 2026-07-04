//cpp
// NONMATCHING: base materialization / addressing (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void EnterBigBoosHaunt(void);
int func_ov002_020c8f0c(char* c){
  *(int*)(c+0x80) -= 0x80;
  *(int*)(c+0x84) -= 0x80;
  *(int*)(c+0x88) -= 0x80;
  if (*(int*)(c+0x80) < 0) {
    *(int*)(c+0x80) = 0;
    *(int*)(c+0x84) = 0;
    *(int*)(c+0x88) = 0;
  }
  if (*(unsigned char*)(c+0x6de) == 0) EnterBigBoosHaunt();
  *(unsigned char*)(c+0x6e3) = 6;
  return 0;
}
}
