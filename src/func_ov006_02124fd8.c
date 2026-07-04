// NONMATCHING: base materialization / addressing (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int Math_Function_0203b14c(void *p, int a, int b, int c, int d);
extern int data_ov006_0213fd44[];

void func_ov006_02124fd8(char *c)
{
  int i;
  int fp;
  int sl;
  char *p;
  char *q;

  fp = 0;
  p = c + 0x51a8;
  q = c + 0x51ac;
  for (i = 0; i < *(short *)(c + 0x51c8); i++)
  {
    if (Math_Function_0203b14c(p, data_ov006_0213fd44[i], 0x800, 0x10000, 0x200) == 0)
      sl = 1;
    else
      sl = 0;

    if (Math_Function_0203b14c(q, 0x60000, 0x800, 0x10000, 0x200) == 0)
    {
      if (sl != 0)
        fp++;
    }
    p += 8;
    q += 8;
  }

  if (fp >= 2)
    (*(int *)(c + 0x51b8))++;
}
