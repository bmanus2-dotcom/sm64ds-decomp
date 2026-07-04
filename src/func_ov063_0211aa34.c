// NONMATCHING: different op / idiom (div=26). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;

extern void _ZN5Model12SetPolygonIDEi(void* m, int id);

void func_ov063_0211aa34(char* self)
{
    u8 cur = *(u8*)(self + 0x5c8);
    u8 tgt = *(u8*)(self + 0x5c9);
    int v;
    if (tgt != cur) {
        if (tgt > cur) {
            if (cur + 0x14 >= tgt)
                *(u8*)(self + 0x5c8) = tgt;
            else
                *(u8*)(self + 0x5c8) += 0x14;
        } else {
            if (cur - 0x14 <= tgt)
                *(u8*)(self + 0x5c8) = tgt;
            else
                *(u8*)(self + 0x5c8) -= 0x14;
        }
    }
    if (*(u8*)(self + 0x5c8) == 0xff) {
        _ZN5Model12SetPolygonIDEi(self + 0x380, 1);
    } else if ((*(unsigned short*)(self + 0x5d4) >> 8) & 1) {
        _ZN5Model12SetPolygonIDEi(self + 0x380, 2);
    } else {
        _ZN5Model12SetPolygonIDEi(self + 0x380, 0x16);
    }
    v = *(int*)(self + 0x584) * 8 / 10
        + *(int*)(self + 0x584) * (*(u8*)(self + 0x5c8) * 2) / 2550;
    *(int*)(self + 0x80) = v;
    *(int*)(self + 0x84) = v;
    *(int*)(self + 0x88) = v;
    *(int*)(self + 0x188) = *(int*)(self + 0x590) * v;
    *(int*)(self + 0x18c) = *(int*)(self + 0x594) * v;
}
