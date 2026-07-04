// NONMATCHING: register allocation (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern int data_ov062_0211deb0[];
extern int func_ov062_02116cd8(unsigned char *c, void *p);
int func_ov062_02116274(unsigned char *c)
{
  int new_var;
  new_var = 0x94;
  *((short *) (c + new_var)) += (new_var = 0x500);
  if ((*((unsigned short *) (c + 0x100))) == 0)
  {
    func_ov062_02116cd8(c, data_ov062_0211deb0);
  }
  return 1;
}
