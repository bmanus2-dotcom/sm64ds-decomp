//cpp
// NONMATCHING: base materialization / addressing (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern int _ZN6Player15IsCollectingCapEv(void* p);
extern void _ZN5Actor15GivePlayerCoinsER6Playerhj(void* a, void* p, unsigned char h, unsigned int j);
extern void _ZN6Player20RegisterEggCoinCountEjbb(void* p, unsigned int n, int b1, int b2);
extern void func_ov071_021202ec(void* a);
extern void _ZN9ActorBase18MarkForDestructionEv(void* a);
void func_ov071_02120580(char* a, void* p) {
  if (_ZN6Player15IsCollectingCapEv(p))
    _ZN5Actor15GivePlayerCoinsER6Playerhj(a, p, *(unsigned char*)(a + 0x3aa), 0);
  else
    _ZN6Player20RegisterEggCoinCountEjbb(p, *(unsigned char*)(a + 0x3aa), 0, 0);
  if (*(int*)(a + 8) != 0) {
    int* f;
    *(unsigned char*)(a + 0x3aa) = 0;
    f = (int*)(a + 0xb0);
    *f = *f & ~0x40000;
    func_ov071_021202ec(a);
    return;
  }
  _ZN9ActorBase18MarkForDestructionEv(a);
}
}
