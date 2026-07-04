// NONMATCHING: missing logic (ROM does more) (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern int _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(char *anim, void *file, int a, int b, unsigned int u);
struct G
{
  int *p[2];
};
extern struct G data_ov034_02113888;
struct E
{
  int w[16];
};
void func_ov034_02112020(char *c)
{
  struct E *new_var2;
  int i;
  struct E *arr = (struct E *) c;
  char *new_var3;
  char *new_var;
  if (1)
  {
  }
  new_var3 = ((char *) (new_var2 = &arr[i])) + 0x490;
  for (i = 0; i < 5; i++)
  {
    *((int *) new_var3) &= ~4;
  }

  *((unsigned char *) (c + 0x8da)) = 0;
  new_var = c + 0x110;
  _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(new_var, (void *) data_ov034_02113888.p[0][1], 0x40000000, 0x1000, 0);
  _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c + 0x174, (void *) data_ov034_02113888.p[1][1], 0x40000000, 0x1000, 0);
}
