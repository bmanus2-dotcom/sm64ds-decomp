//cpp
// NONMATCHING: register allocation (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C;
typedef void (C::*PMF)();
extern PMF data_ov002_0210db80[];
struct C {
  char pad0[0x9c];
  int f9c;
  char pad1[0x10];
  int fb0;
  char pad2[0x4e];
  short f102;
  char pad3[8];
  int f10c;
};
extern "C" void func_ov002_020aea30(C* c) {
  if (c->f10c == 0) return;
  c->fb0 &= ~0x10000000;
  c->f102 = 0;
  (c->*data_ov002_0210db80[c->f10c - 1])();
  c->f9c = -0x2000;
  c->fb0 &= ~0x10000000;
}
