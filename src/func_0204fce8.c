// NONMATCHING: base materialization / addressing (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern int __aeabi_uidiv(unsigned int a, unsigned int b);
extern struct LL
{
  int lo;
  int hi;
} data_020a5578[];
extern int data_020a5538[];
typedef void (*FP)(void *, int, int *, int, int, int);
void func_0204fce8(int *thiz, void *arg)
{
  int new_var;
  int i;
  unsigned char *p = (unsigned char *) thiz;
  int q = __aeabi_uidiv(thiz[4], thiz[5]);
  int scaled = q * thiz[8];
  for (i = 0; i < thiz[0xc]; i++)
  {
    new_var = data_020a5578[(p + i)[0x34]].lo;
    data_020a5538[i] = new_var + scaled;
  }

  ((FP) thiz[6])(arg, thiz[0xc], data_020a5538, q, thiz[2], thiz[7]);
  thiz[8]++;
  if (thiz[8] >= thiz[5])
  {
    thiz[8] = 0;
  }
}
