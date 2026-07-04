// NONMATCHING: different op / idiom (div=49). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int _ZNK7PathPtr8NumNodesEv(void* p);
extern void _ZNK7PathPtr7GetNodeER7Vector3j(void* p, void* out, unsigned int i);
extern int Vec3_Dist(void* a, void* b);
extern int Vec3_HorzAngle(void* a, void* b);
extern void _Z14ApproachLinearRsss(short* p, short t, short s);
extern void _ZN5Actor9UpdatePosEP12CylinderClsn(void* self, void* clsn);
extern int func_ov019_0211140c(int* self, void* clsn);
extern void func_0201267c(int a, void* p);
extern int func_ov019_021122dc(void* c, int s);
int func_ov019_021117a8(char* c) {
    int node[3];
    switch (*(unsigned char*)(c+0x38f)) {
    case 0: {
        int n = _ZNK7PathPtr8NumNodesEv(c+0x364);
        _ZNK7PathPtr7GetNodeER7Vector3j(c+0x364, node, n - 1);
        *(int*)(c+0x380) = Vec3_Dist(c+0x5c, node);
        *(short*)(c+0x38c) = (short)Vec3_HorzAngle(c+0x5c, node);
        _Z14ApproachLinearRsss((short*)(c+0x38e), *(short*)(c+0x38c), 0x200);
        *(short*)(c+0x94) = *(short*)(c+0x38e);
        if (*(int*)(c+0x380) < *(int*)(c+0x98)) {
            *(int*)(c+0x98) = *(int*)(c+0x380);
            (*(unsigned char*)(c+0x38f))++;
        }
        _ZN5Actor9UpdatePosEP12CylinderClsn(c, c+0x174);
        func_ov019_0211140c((int*)c, c+0x1a8);
        {
            int s = (unsigned short)(*(int*)(c+0x12c) << 4) >> 0x10;
            if (s == 9 || s == 0x15) {
                func_0201267c(0xde, c+0x74);
            }
        }
        break;
    }
    case 1: {
        if (Vec3_HorzAngle(c+0x5c, *(char**)(c+0x378)+0x5c) ) {}
        _Z14ApproachLinearRsss((short*)(c+0x38e), (short)Vec3_HorzAngle(c+0x5c, *(char**)(c+0x378)+0x5c), 0x514);
        if (func_ov019_021122dc(c, 5)) {}
        {
            int s = (unsigned short)(*(int*)(c+0x12c) << 4) >> 0x10;
            if (s == 9 || s == 0x15) {
                func_0201267c(0xf3, c+0x74);
            }
        }
        break;
    }
    }
    return 1;
}
