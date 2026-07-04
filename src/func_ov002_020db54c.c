//cpp
// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned short u16;
struct Vector3 { int x, y, z; };
struct State;
extern "C" void func_02035860(void *a, struct Vector3 *v);
extern struct State data_ov002_021101cc;
extern "C" void _ZN6Player11ChangeStateERNS_5StateE(void *self, struct State &s);

extern "C" void func_ov002_020db54c(unsigned char *self, int a, int b, short c)
{
    void *node;
    *(short *)(self + 0x94) = c;
    *(int *)(self + 0x98) = a;
    *(int *)(self + 0xa8) = b;
    node = *(void **)(self + 0x35c);
    if (node != 0) {
        int bb = (int)(*(u16 *)((char *)node + 0xc) == 0xbf);
        if (bb != 0) {
            struct Vector3 *src = (struct Vector3 *)((char *)node + 0x5c);
            struct Vector3 v;
            v.x = src->x;
            v.y = src->y;
            v.z = src->z;
            v.y = src->y + 0x64000;
            func_02035860(self + 0x380, &v);
            *(int *)(self + 0x68) = v.x;
            *(int *)(self + 0x6c) = v.y;
            *(int *)(self + 0x70) = v.z;
        }
    }
    *(int *)(self + 0x35c) = 0;
    _ZN6Player11ChangeStateERNS_5StateE(self, data_ov002_021101cc);
}
