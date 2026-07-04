// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_ov018_021123d0(void*,int);
void func_ov018_02111968(char* c, int v, char* a){
  if (a && *(unsigned short*)(a+0xc)==0x100 && *(int*)(a+8)==1) {
    *(int*)(c+0x374) = v;
    *(short*)(c+0x384) = 0xae;
    *(char*)(c+0x387) = 1;
    func_ov018_021123d0(c, 1);
    return;
  }
  if (*(unsigned char*)(c+0x386)) return;
  if (a && *(unsigned short*)(a+0xc)==0x100 && *(int*)(a+8)==0) {
    *(short*)(c+0x384) = 0xad;
    return;
  }
  if (*(unsigned char*)(c+0x387)) return;
  *(short*)(c+0x384) = 0xac;
  *(int*)(c+0x374) = v;
  func_ov018_021123d0(c, 1);
}
