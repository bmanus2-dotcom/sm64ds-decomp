//cpp
// NONMATCHING: different op / idiom (div=7). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void _ZN8Platform21IsClsnInRangeOnScreenE5Fix12IiES1_(void* t, int a, int b);
extern void func_ov027_02111cfc(void* c);
extern void* _ZN5Actor13ClosestPlayerEv(void* c);
extern int _ZN6Player16IsInsideOfCannonEv(void* p);
extern void _ZN9Animation7AdvanceEv(void* a);
extern void _ZN12CylinderClsn5ClearEv(void* a);
extern void _ZN12CylinderClsn6UpdateEv(void* a);
extern void func_ov027_02111994(char* c);

int func_ov027_02111e34(char* c){
  _ZN8Platform21IsClsnInRangeOnScreenE5Fix12IiES1_(c, 0, 0);
  func_ov027_02111cfc(c);
  if(_ZN6Player16IsInsideOfCannonEv(_ZN5Actor13ClosestPlayerEv(c))){
    int* fl = (int*)(c+0xb0);
    *fl &= ~2;
  } else {
    int* fl = (int*)(c+0xb0);
    *fl |= 2;
  }
  _ZN9Animation7AdvanceEv(c+0x370);
  _ZN9Animation7AdvanceEv(c+0x384);
  _ZN12CylinderClsn5ClearEv(c+0x398);
  _ZN12CylinderClsn6UpdateEv(c+0x398);
  func_ov027_02111994(c);
  return 1;
}
}
