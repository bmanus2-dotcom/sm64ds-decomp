// NONMATCHING: different op / idiom (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_02012790(int);
extern void func_ov006_020c271c(void *c);
extern void func_ov006_020c2664(char *c);

struct E { char _[0x14]; };

void func_ov006_0211b80c(char *c){
  if((unsigned char)c[0x5625] < 2) return;
  if(*(unsigned short*)(c+0x5614) != 0){
    *(unsigned short*)(c+0x5614) -= 1;
    if(*(short*)(c+0x5614) <= 0) *(unsigned short*)(c+0x5614) = 0;
    return;
  }
  if((*(unsigned short*)(c+0x5610) & 0xff) == (*(unsigned short*)(c+0x5612) & 0xff)){
    *((char*)&((struct E*)c)[*(unsigned short*)(c+0x5610) >> 8] + 0x50f5) = 0;
    *((char*)&((struct E*)c)[*(unsigned short*)(c+0x5612) >> 8] + 0x50f5) = 0;
    func_02012790(0x26);
    func_ov006_020c271c(c+0x4f38);
  } else {
    *((char*)&((struct E*)c)[*(unsigned short*)(c+0x5610) >> 8] + 0x50f4) = 3;
    *((char*)&((struct E*)c)[*(unsigned short*)(c+0x5612) >> 8] + 0x50f4) = 3;
    func_02012790(0xe);
    *(unsigned char*)(c+0x5626) -= 1;
    func_02012790(0x12f);
    func_ov006_020c2664(c+0x4f38);
  }
  *(unsigned short*)(c+0x5612) = 0;
  *(unsigned short*)(c+0x5610) = *(unsigned short*)(c+0x5612);
  c[0x5625] = 0;
  c[0x5624] = 0;
}
