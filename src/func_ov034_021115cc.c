//cpp
// NONMATCHING: register allocation (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct MA { char b[0x64]; };
extern void _Z14ApproachLinearRiii(int& r, int b, int c);
extern void SetAnim(void* ma, void* bca, int a, int fix, unsigned int u);
extern int _ZN9Animation8FinishedEv(void* a);
extern void func_ov034_021125b8(void* c, int i);
extern char* data_ov034_0211389c[];
extern char* data_ov034_02113860[];
extern "C" void func_ov034_021115cc(char* self)
{
  int i;
  int j;
  MA* p;
  int eq;
  _Z14ApproachLinearRiii(*(int*)(self + 0x98), 0, 0x1000);
  p = (MA*)(self + 0x110) + 2;
  for (i = 2, j = 6; i < 5; i++, j += 3, p++) {
    if (*(unsigned char*)(self + 0x8da) == j - 3) {
      SetAnim(p, *(void**)(data_ov034_0211389c[i] + 4), 0x40000000, 0x1000, 0);
    }
  }
  if (_ZN9Animation8FinishedEv(self + 0x2f0)) {
    p = (MA*)(self + 0x110);
    for (i = 0; i < 5; p++, i++) {
      SetAnim(p, *(void**)(data_ov034_02113860[i] + 4), 0, 0x1000, 0);
    }
  }
  eq = 1;
  p = (MA*)self;
  for (i = 0; i < 5; p++, i++) {
    if (*(int*)((char*)p + 0x170) != *(int*)(data_ov034_02113860[i] + 4)) eq = 0;
  }
  if (eq == 1) func_ov034_021125b8(self, 9);
  *(unsigned char*)(self + 0x8da) += 1;
  if (*(unsigned char*)(self + 0x8da) > 0xc) *(unsigned char*)(self + 0x8da) = 0xd;
}
