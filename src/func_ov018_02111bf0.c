//cpp
// NONMATCHING: different op / idiom (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
typedef struct { int x, y, z; } Vector3;
typedef struct WithMeshClsn WithMeshClsn;
struct SurfaceInfo {
  int a, b, c, d, e;      // +0..+0x10 (5 ints)
  unsigned short f, g;    // +0x14,+0x16
  int h, i, j;            // +0x18,+0x1c,+0x20
};
struct ClsnResult {
  void* vt;
  struct SurfaceInfo info;
};
void func_02038420(void* w);
int _ZNK12WithMeshClsn10IsOnGroundEv(WithMeshClsn* w);
void* _ZNK12WithMeshClsn14GetFloorResultEv(WithMeshClsn* w);
void _ZNK11SurfaceInfo12CopyNormalToER7Vector3(struct SurfaceInfo* s, Vector3* v);
int _ZN4cstd4fdivEii(int a, int b);
int _ZNK12WithMeshClsn8IsOnWallEv(WithMeshClsn* w);
struct ClsnResult* _ZNK12WithMeshClsn13GetWallResultEv(WithMeshClsn* w);
void _ZN10ClsnResultD1Ev(struct ClsnResult* r);
extern void* data_02099368;

void func_ov018_02111bf0(char* c, WithMeshClsn* w){
  func_02038420(w);
  if (_ZNK12WithMeshClsn10IsOnGroundEv(w) != 0) {
    Vector3 n;
    _ZNK11SurfaceInfo12CopyNormalToER7Vector3((struct SurfaceInfo*)((char*)_ZNK12WithMeshClsn14GetFloorResultEv(w) + 4), &n);
    if (n.y != 0) {
      int s = (int)(((long long)n.x * *(int*)(c+0xa4) + 0x800) >> 0xc)
            + (int)(((long long)n.z * *(int*)(c+0xac) + 0x800) >> 0xc);
      *(int*)(c+0xa8) = -(_ZN4cstd4fdivEii(s, n.y) + 0x8000);
    }
  }
  if (_ZNK12WithMeshClsn8IsOnWallEv(w) != 0) {
    struct ClsnResult* src = _ZNK12WithMeshClsn13GetWallResultEv(w);
    struct ClsnResult cr;
    struct SurfaceInfo* dst = &cr.info;
    *dst = src->info;
    cr.vt = &data_02099368;
    Vector3 wn;
    _ZNK11SurfaceInfo12CopyNormalToER7Vector3(dst, &wn);
    _ZN10ClsnResultD1Ev(&cr);
  }
}
}
