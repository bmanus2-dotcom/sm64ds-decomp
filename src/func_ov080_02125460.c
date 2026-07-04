// NONMATCHING: different op / idiom (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
void func_ov080_02125460(char* c){
  u32* p = *(u32**)(c+0x1a8);
  unsigned char m = (*(u32*)(c+8) >> 0xd) & 3;
  u32 r3 = p[2];
  if (m >= 2 || *(unsigned short*)(c+0x1b6) == 0)
    r3 |= 0x7fff0000;
  *(u32*)0x40004c0 = r3;
  *(u32*)0x40004c4 = (*(u32**)(c+0x1a8))[3];
  {
    u32* q = *(u32**)(c+0x1a8);
    u32 a = q[4];
    u32 b = q[0];
    *(u32*)0x40004a8 = (b >> 3)
      | (((a >> 0x1a) & 7) << 26)
      | (((a >> 0x14) & 7) << 20)
      | (((a >> 0x17) & 7) << 23)
      | (((a >> 0x1d) & 1) << 29);
  }
  {
    u32* q = *(u32**)(c+0x1a8);
    u32 k = (q[4] >> 0x1a) & 7;
    *(u32*)0x40004ac = q[1] >> (4 - (k == 2 ? 1 : 0));
  }
  *(u32*)0x40004a4 = 0x11f0088;
}
