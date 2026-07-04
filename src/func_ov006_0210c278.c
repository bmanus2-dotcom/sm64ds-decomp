// NONMATCHING: base materialization / addressing (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

void func_ov006_0210c278(unsigned char *o)
{
  int new_var2;
  int *new_var;
  new_var2 = 0;
  new_var = (int *) (o + 4);
  if ((*((int *) (o + 4))) <= new_var2)
  {
    return;
  }
  int *p = new_var;
  p[new_var2] = p[new_var2] - 1;
  new_var2 = 1;
  if (((*((int *) (o - -4))) & 7) == 0)
  {
    unsigned char *f = o + 8;
    f[0] = f[new_var2] ^ new_var2;
  }
}
