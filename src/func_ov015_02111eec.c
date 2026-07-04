// NONMATCHING: base materialization / addressing (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern void Math_Function_0203b0fc(int *p, int target, int scale, int max);
extern void func_ov015_02111fb8(void *self, int idx);
void func_ov015_02111eec(char *c)
{
  int *p;
  p = (int *) (c + 0x320);
  Math_Function_0203b0fc((int *) (c + 0x5c), (*p) - 0x168000, 0x800, 0x46000);
  p = (int *) (c + 0x334);
  *p = (*p) - 1;
  if ((*((int *) (c + 0x334))) > 0)
  {
    return;
  }
  *((int *) (c + 0x5c)) = (*p) - 0x168000;
  func_ov015_02111fb8(c, 2);
}
