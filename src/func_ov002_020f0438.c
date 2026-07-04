//cpp
// NONMATCHING: base materialization / addressing (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vector3 { int x, y, z; };
struct Actor {
  char pad[0x5c];
  Vector3 pos;          // 0x5c
  char pad2[160];       // 0x68 .. 0x108
  unsigned int id;      // 0x108
  char b10e_pad[2];     // 0x10c .. 0x10e
  unsigned char b10e;   // 0x10e
  unsigned char b10f;   // 0x10f
  unsigned char b110;   // 0x110
  unsigned char b111[2];
  unsigned char b113;   // 0x113
};
extern "C" {
Actor* _ZN5Actor10FindWithIDEj(unsigned int id);
void func_02012790(int);
short _ZN5Actor11SpawnNumberERK7Vector3jbtPS_(Actor* thiz, const Vector3& v, unsigned int a, bool b, unsigned short c, Actor* d);
void _ZN9ActorBase18MarkForDestructionEv(Actor* thiz);

void func_ov002_020f0438(Actor* thiz)
{
  Actor* o = _ZN5Actor10FindWithIDEj(thiz->id);
  if (!o) return;
  if (thiz->b10e != 0xf && thiz->b10e != o->b110) return;
  func_02012790(0x25);
  o->b110++;
  {
    Vector3 v;
    v.x = thiz->pos.x;
    v.y = thiz->pos.y;
    v.z = thiz->pos.z;
    _ZN5Actor11SpawnNumberERK7Vector3jbtPS_(thiz, v, o->b110, false, 0, 0);
  }
  *(int*)((char*)thiz+0xec) |= 1;
  if (o->b110 == 5) { thiz->b113 = 0x1e; return; }
  if (thiz->b10f != 2) return;
  _ZN9ActorBase18MarkForDestructionEv(thiz);
}
}
