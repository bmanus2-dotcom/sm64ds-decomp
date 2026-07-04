// NONMATCHING: base materialization / addressing (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern void ShowArea(int idx);
extern int func_02012694(int a, void *b);
extern char *data_0209f318;
inline short inline_fn(char *arg0, int arg1)
{
  return *((short *) (arg0 + arg1));
}

int func_ov100_02144950(char *c)
{
  unsigned char new_var;
  int new_var2;
  new_var2 = 0x90;
  *((int *) (c + 0x12c)) = 0;
  new_var = new_var;
  ShowArea((signed char) inline_fn(c, 0x8c));
  ShowArea((signed char) inline_fn(c, new_var2));
  {
    int *q = (int *) (data_0209f318 + ((0xFFFFu & 0xFFFFu) & 0xFFFFu));
    *q |= 0xc00;
  }
  new_var = 0x74;
  func_02012694(((*((int *) (c + 8))) == 0x10) ? (6) : (4), c + new_var);
  *((unsigned char *) (c + 0x145)) = 0;
  return 1;
}
