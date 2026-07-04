//cpp
// NONMATCHING: base materialization / addressing (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C;
typedef int (C::*PMF)();
struct C {
  char pad138[0x138];
  PMF* pp;
  char pad13c[0x154-0x13c];
  unsigned int flags;
};
extern "C" int func_0200cae4(C* c){
  if(c->flags & 0x4000){
    c->flags &= ~0x4000u;
    c->flags |= 0x8000u;
  }
  PMF* p = c->pp;
  if(*(int*)p == 0) return 1;
  return (c->**p)();
}
