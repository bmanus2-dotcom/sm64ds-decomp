//cpp
// NONMATCHING: different op / idiom (div=13). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void MultiCopy_Int(int *dst, int *src, int len);
void MultiCopy32Bytes(int *src, int *dst, int len);
}

struct OAMEntry { u32 a; u16 b; u16 pad; };

extern u8 data_0209e660;
extern OAMEntry data_0209e674[];
extern int data_0209e67c[];
extern int data_0209e694[];
extern int data_0209ea74[];
extern int data_0209e670;
extern int data_0209e66c;
extern int data_0209e664;
extern int data_0209e668;

namespace OAM {
void Reset() {
    int i;
    if (data_0209e660 != 0) {
        for (i = 0; i < 0x80; i++) {
            data_0209e674[i].a = 0xc0;
            data_0209e674[i].b = 0;
        }
    } else {
        data_0209e674[0].a = 0xc0;
        data_0209e674[0].b = 0;
        MultiCopy_Int((int*)data_0209e674, data_0209e67c, 0x18);
    }
    MultiCopy32Bytes((int*)data_0209e674, data_0209e694, 0x3e0);
    MultiCopy32Bytes((int*)data_0209e674, data_0209ea74, 0x400);
    data_0209e670 = data_0209e66c = 0;
    data_0209e664 = data_0209e668 = 0;
}
}
