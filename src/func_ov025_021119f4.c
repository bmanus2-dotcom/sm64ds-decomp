// NONMATCHING: different op / idiom (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern int func_0201267c(int a, void *b);
void func_ov025_021119f4(char *c)
{
  char *new_var3;
  int new_var2;
  unsigned char *new_var;
  unsigned char *p = (unsigned char *) (c - -0x39e);
  int new_var4;
  *new_var = (new_var2 = (*p) - 1);
  new_var = p;
  if (*((unsigned char *) (c + (0x39e & 0xFFFFFFFFu))))
  {
    return;
  }
  new_var4 = 0x39c;
  if (((*((unsigned char *) (c + 0x39f))) != 4) & 0xFFFFFFFF)
  {
    *((int *) (c + 0x398)) = 5;
    *((int *) (c + 0xa8)) = 0x3c000;
    if (c)
    {
    }
    func_0201267c(0xf4, c + 0x74);
    return;
  }
  *((int *) (c + 0x398)) = 7;
  new_var3 = c + new_var4;
  *((short *) new_var3) = (*((short *) (c + 0x8e))) + 0x8000;
}
