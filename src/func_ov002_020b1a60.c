// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZN9ActorBase18MarkForDestructionEv(void*);
void func_ov002_020b1a60(void* c) {
  *(unsigned short*)((char*)c+0x3a8) += 1;
  {
    int* s = (int*)((char*)*(void**)((char*)c+0x39c)+0x5c);
    *(int*)((char*)c+0x5c) = s[0];
    *(int*)((char*)c+0x60) = s[1];
    *(int*)((char*)c+0x64) = s[2];
  }
  *(int*)((char*)c+0x60) += 0xc8000;
  if (*(unsigned short*)((char*)c+0x3a8) < 0x41) return;
  _ZN9ActorBase18MarkForDestructionEv(c);
  *(unsigned short*)((char*)c+0x3a8) = 0;
}
