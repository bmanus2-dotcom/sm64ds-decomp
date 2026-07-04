//cpp
// NONMATCHING: base materialization / addressing (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void* self, void* bca, int a, int fix, unsigned int j);
extern int RandomIntInternal(void* s);
extern int data_ov081_02128ecc[];
extern int data_0209e650[];
int func_ov081_02127314(char* c){
  int* p = (int*)(c+0xb0);
  *p = *p & ~1;
  _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c+0xd4, (void*)data_ov081_02128ecc[1], 0x40000000, 0x1000, 0);
  *(int*)(c+0x12c) = 0;
  *(short*)(c+0x8e) = (short)RandomIntInternal(data_0209e650);
  *(short*)(c+0x94) = *(short*)(c+0x8e);
  *(int*)(c+0x98) = 0;
  *(unsigned char*)(c+0x3f1) = 0;
  *(int*)(c+0x3e0) = 3;
  return 1;
}
}
