// NONMATCHING: mov vs movne for arg path; v/j register swap (r1/r2) (div=12)

extern unsigned short *_ZN3G2S12GetBG1ScrPtrEv(void);
extern unsigned short data_ov003_020b174c[];
void func_ov003_020b0730(void *self, int arg) {
  unsigned char *s = (unsigned char *)self;
  int i; unsigned int mask = 0x3ff; unsigned int v1000 = 0x1000; unsigned int v2000 = 0x2000; int z = 0;
  for (i = 0; i < 2; i++) {
    unsigned short *p = _ZN3G2S12GetBG1ScrPtrEv();
    unsigned short d = data_ov003_020b174c[i];
    unsigned int v; int j; unsigned short *row;
    if (arg)
      v = v1000;
    else
      v = v1000;
    row = p + d;
    if (!arg) {
      if ((s[0x91] == i) && (s[0x93] == 0)) v = v2000; else v = v1000;
      v = (unsigned short)v;
    }
    for (j = z; j < 0x20; j++) {
      row[0] = (unsigned short)((row[0] & mask) | v);
      row[0x20] = (unsigned short)((row[0x20] & mask) | v);
      row[0x40] = (unsigned short)((row[0x40] & mask) | v);
      row[0x60] = (unsigned short)((row[0x60] & mask) | v);
      row += 1;
    }
  }
}
