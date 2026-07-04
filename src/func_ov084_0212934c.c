// NONMATCHING: different op / idiom (div=34). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZNK12WithMeshClsn10IsOnGroundEv(void* c);
extern void func_02012694(int a, void* p);

extern int data_ov084_02130ce8[2];
extern int data_ov084_02130cf0[2];

typedef struct {
    unsigned char b0 : 1;
    unsigned char flag : 1;
} Flags;

void func_ov084_0212934c(char* c)
{
    unsigned int kind;
    int v;
    int type;

    if (*(int*)(c + 0x434) != 0)
        return;

    if (!_ZNK12WithMeshClsn10IsOnGroundEv(c + 0x1b4))
        return;

    v = *(int*)(c + 0x3c8);
    type = *(int*)(c + 0x3d0);
    kind = (unsigned)(v << 4) >> 0x10;

    if (type == data_ov084_02130ce8[1]) {
        if (kind > 4) {
            if (kind >= 0xc && kind <= 0x10) {
                if (((Flags*)(c + 0x468))->flag)
                    return;
                func_02012694(0xd0, c + 0x74);
            } else {
                ((Flags*)(c + 0x468))->flag = 0;
                return;
            }
        }
        ((Flags*)(c + 0x468))->flag = 1;
        return;
    }

    if (type == data_ov084_02130cf0[1]) {
        if (kind > 3) {
            if (kind >= 0x10 && kind <= 0x13) {
                if (((Flags*)(c + 0x468))->flag)
                    return;
                func_02012694(0xd0, c + 0x74);
            } else {
                ((Flags*)(c + 0x468))->flag = 0;
                return;
            }
        }
        ((Flags*)(c + 0x468))->flag = 1;
    }
}
