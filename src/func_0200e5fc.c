//cpp
// NONMATCHING: missing logic (ROM does more) (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vector3 { int x, y, z; };
struct Vector3_16 { short x, y, z; };

namespace SaveData { int IsCharacterUnlocked(unsigned int); }
namespace Actor {
    void *Spawn(unsigned int, unsigned int, Vector3 const &, Vector3_16 const *, int, int);
}

extern int data_0209b284[];
extern u8 data_0209f2d8;
extern u8 data_0209b270;

extern "C" void *func_0200e5fc(unsigned int idx) {
    if (data_0209b284[idx] != 0) return 0;
    int flag = 0x11;
    int b = (int)(data_0209f2d8 == 2);
    if (b != 0) {
        if (SaveData::IsCharacterUnlocked(idx) == 0) return 0;
        flag = 0;
    }
    unsigned int arg = idx | (idx << 3) | (data_0209b270 << 6) | (flag << 8);
    void *res = Actor::Spawn(0xbf, arg, *(Vector3 const *)0, (Vector3_16 const *)0, -1, -1);
    if (res == 0) return res;
    int f4 = *((int*)res + 1);
    data_0209b284[idx] = f4;
    data_0209b270++;
    return res;
}
