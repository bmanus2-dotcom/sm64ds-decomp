//cpp
// NONMATCHING: base materialization / addressing (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern int _ZN12CylinderClsn5ClearEv(void*);
extern int _ZN12WithMeshClsn15ClearGroundFlagEv(void*);
int func_ov030_021132d4(char* c){
  int* a = (int*)(c+0xb0);
  *a &= ~0x80000;
  *(unsigned char*)(c+0x3c7) = 0;
  *(int*)(c+0x98) = 0;
  _ZN12CylinderClsn5ClearEv(c+0x160);
  _ZN12WithMeshClsn15ClearGroundFlagEv(c+0x194);
  *(int*)(c+0x3b8) = *(int*)(c+0x3b4);
  *(int*)(c+0x3b4) = 5;
  return 1;
}
}
