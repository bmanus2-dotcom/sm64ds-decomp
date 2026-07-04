//cpp
// NONMATCHING: different op / idiom (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12i;
struct Vec { Fix12i x, y, z; };
struct Vector3_16;

struct Entry {
  unsigned short raw;   // 0
  short x;              // 2
  short y;              // 4
  short z;              // 6
};
struct ObjSubTable {
  unsigned char pad0;   // 0
  unsigned char count;  // 1
  unsigned char pad2[2];
  Entry* entries;       // 4
};

extern short data_ov002_0211118c;
extern unsigned short data_ov002_0210cbf4[];

extern "C" {
void _Z23LoadMinimapChangeObjecti5Fix12IiEh(int a, Fix12i b, unsigned char h);
void _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int a, unsigned int b, Vec* v, Vector3_16* rot, int e, int f);

void _Z17LoadSimpleObjectsRN11LVL_Overlay11ObjSubTableEij(ObjSubTable& tbl, int p2, int p3)
{
  Entry* e = tbl.entries;
  int i;
  for (i = 0; i < (int)tbl.count; i++, e++) {
    Vec v;
    int raw;
    int param;
    v.x = e->x << 12;
    v.y = e->y << 12;
    v.z = e->z << 12;
    raw = e->raw;
    param = raw >> 9;
    if ((unsigned short)(raw & 0x1ff) == 0x1ff) {
      _Z23LoadMinimapChangeObjecti5Fix12IiEh(p2, v.y, (signed char)(param & 0xf));
    } else {
      short old = data_ov002_0211118c;
      data_ov002_0211118c = old + 1;
      _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
        data_ov002_0210cbf4[raw & 0x1ff], param, &v, 0, p2, old);
    }
  }
}
}
