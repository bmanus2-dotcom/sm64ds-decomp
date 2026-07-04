//cpp
// NONMATCHING: push-set / frame (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct C;
typedef void (C::*PMF)();
extern "C" PMF data_ov002_0210dd30[];
extern "C" {
void* _ZN5Actor4NextEPKS_(const void* prev);
int Vec3_Dist(const void* a, const void* b);
void _ZN9ActorBase18MarkForDestructionEv(void* c);
}
struct C { char pad[0x1000]; };
extern "C" int func_ov002_020b440c(char* c){
  if (*(unsigned char*)(c + 0xd8) == 0){
    char* o = (char*)_ZN5Actor4NextEPKS_(0);
    while (o){
      unsigned short t = *(unsigned short*)(o + 0xc);
      int b;
      b = (t == 0x10);
      if (!b){
        b = (t == 0xf);
        if (!b){
          b = (t == 0x11);
          if (!b) goto next;
        }
      }
      if (Vec3_Dist(c + 0x5c, o + 0x5c) < 0x32000){
        *(char**)(o + 0x328) = c;
        *(unsigned char*)(c + 0xd8) = 1;
        return 1;
      }
    next:
      o = (char*)_ZN5Actor4NextEPKS_(o);
    }
  }
  if (*(unsigned char*)(c + 0xd6) != 0){
    int idx = *(unsigned char*)(c + 0xd7);
    (((C*)c)->*data_ov002_0210dd30[idx])();
  }
  _ZN9ActorBase18MarkForDestructionEv(c);
  return 1;
}
