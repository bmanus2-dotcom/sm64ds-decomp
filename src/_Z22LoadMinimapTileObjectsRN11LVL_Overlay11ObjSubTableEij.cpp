//cpp
struct ObjSubTable {
  unsigned char pad0;   // 0
  unsigned char count;  // 1
  unsigned char pad2[2];
  void* entries;        // 4
};

extern "C" {
extern void func_0202b044(void*, unsigned int);

void _Z22LoadMinimapTileObjectsRN11LVL_Overlay11ObjSubTableEij(ObjSubTable& tbl, int p2, unsigned int p3) {
    func_0202b044(tbl.entries, tbl.count);
}
}
