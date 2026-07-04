// NONMATCHING: base materialization / addressing (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
struct Vector3 { int x, y, z; };
extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int id, const struct Vector3* v);
extern void _ZN8Platform21UpdateModelPosAndRotYEv(char* c);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(char* c);

void func_ov002_020bb27c(char* self, char* arg){
  if (*(u8*)(self+0x58e) == 0) return;
  if (*(u8*)(self+0x58f) != 0) return;
  _ZN5Sound9PlayBank3EjRK7Vector3(0x62, (struct Vector3*)(self+0x74));
  if (*(int*)(arg+8) == 2 || *(u8*)(arg+0x703) != 0) {
    *(int*)(self+0x60) -= (*(u8*)(self+0x58e) * 0x2d) << 12;
    *(u8*)(self+0x58e) = 0;
    _ZN8Platform21UpdateModelPosAndRotYEv(self);
    _ZN8Platform19UpdateClsnPosAndRotEv(self);
    *(u8*)(self+0x591) = 0x1e;
  } else {
    *(int*)(self+0x60) -= 0x2d000;
    *(u8*)(self+0x58e) -= 1;
    _ZN8Platform21UpdateModelPosAndRotYEv(self);
    _ZN8Platform19UpdateClsnPosAndRotEv(self);
    *(u8*)(self+0x58f) = 0xf;
    *(u8*)(self+0x591) = 0x1e;
  }
  return;
}
