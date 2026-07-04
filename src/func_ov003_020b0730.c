// NONMATCHING: register allocation (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned short *_ZN3G2S12GetBG1ScrPtrEv(void);
extern unsigned short data_ov003_020b174c[];
void func_ov003_020b0730(void *self, int arg)
{
  unsigned char *s = (unsigned char *) self;
  int i;
  for (i = 0; i < 2; i++)
  {
    unsigned int v;
    unsigned short *row;
    int j;
    unsigned short *p = _ZN3G2S12GetBG1ScrPtrEv();
    row = p + data_ov003_020b174c[i];
    if (arg)
      v = 0x1000;
    else if ((s[0x91] == i) && (s[0x93] == 0))
      v = 0x2000;
    else
      v = 0x1000;
    v = (unsigned short) v;
    for (j = 0; j < 0x20; j++)
    {
      row[0] = v | (row[0] & 0x3ff);
      row[0x20] = v | (row[0x20] & 0x3ff);
      row[0x40] = v | (row[0x40] & 0x3ff);
      row[0x60] = v | (row[0x60] & 0x3ff);
      row += 1;
    }
  }
}
