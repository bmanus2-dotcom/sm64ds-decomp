// NONMATCHING: constant / value (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern void func_02012694(int a, void *b);
extern void _ZN12WithMeshClsn15ClearGroundFlagEv(void *);
extern int data_ov084_02130248[];
void func_ov084_02129c9c(char *c)
{
  int new_var2;
  char *new_var;
  func_02012694(0x118, c + 0x74);
  *((int *) (c + 0x434)) = 2;
  *((int *) (c + 0x98)) = 0;
  new_var = c;
  *((int *) (new_var + 0xa8)) = data_ov084_02130248[*((int *) (new_var + 0x460))];
  new_var2 = 0x198;
  _ZN12WithMeshClsn15ClearGroundFlagEv(new_var = new_var + 0x1b4);
  *((int *) (new_var + new_var2)) |= 4;
}
