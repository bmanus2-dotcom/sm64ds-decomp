// NONMATCHING: base materialization / addressing (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern void *data_ov007_02103450[];
extern void *data_ov007_0210344c;
extern void *_ZN8Particle7Manager9AddSystemEiR7Vector3(void *mgr, int id, void *pos);
void func_ov007_020b7708(int idx, void *pos)
{
  void *sys;
  int *p;
  if (data_ov007_02103450[idx] != 0)
  {
    return;
  }
  data_ov007_02103450[idx] = _ZN8Particle7Manager9AddSystemEiR7Vector3(data_ov007_0210344c, 0, pos);
  sys = (p = data_ov007_02103450[idx]);
  sys = (int *) (((char *) sys) - -0x1c);
  *p |= 2;
}
