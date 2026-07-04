// NONMATCHING: register allocation (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.

typedef unsigned short u16;
typedef unsigned int u32;
extern long long func_02059650(void *obj);
extern void func_02056e4c(int a, void *fn);
extern void func_02059824(void);
extern void _ZN3IRQ10EnableIRQsEj(unsigned int mask);
typedef struct Obj
{
  char pad0c[0xc];
  long long t;
} Obj;
void func_02059c18(Obj *obj)
{
  long long v;
  int sub;
  u16 timer;
  sub = func_02059650(obj);
  *((volatile u16 *) 0x4000106) = 0;
  v = obj->t - sub;
  func_02056e4c(1, (void *) func_02059824);
  if (v < 0)
  {
    timer = 0xfffe;
  }
  else
    if (v < 0x10000)
  {
    timer = (u16) (~((u32) v));
  }
  else
  {
    timer = 0;
  }
  *((volatile u16 *) 0x4000104) = timer;
  *((volatile u16 *) 0x4000106) = 0xc1;
  _ZN3IRQ10EnableIRQsEj(0x10);
}
