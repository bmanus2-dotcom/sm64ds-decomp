// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
int func_ov006_02106664(char* self)
{
  int i,bad,j;char* row=self;
  for (i = 0; i < 5; i++) {
    bad = 0;
    for (j = 0; j < 0xa; j++) {
      if (*(unsigned char*)(self + 0x4fae + j) != *(unsigned char*)(row + 0x4ec8 + j)) { bad = 1; break; }
    }
    if (bad == 0) return 0;
    row += 0xa;
  }
  {
    int r6; char* s = self;
    for (r6=0;r6<4;r6++){ char* d=self+(r6+1)*0xa; for(j=0;j<0xa;j++){*(unsigned char*)(d+0x4ec8)=*(unsigned char*)(s+0x4ec8+j);d++;} s+=0xa; }
  }
  for (i = 0; i < 0xa; i++) {
    *(unsigned char*)(self + 0x4ec8 + i) = *(unsigned char*)(self + 0x4fae + i);
  }
  return 1;
}
