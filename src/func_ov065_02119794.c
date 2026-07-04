// NONMATCHING: register allocation (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void Matrix4x3_FromRotationY(void *m, short ang);
extern int _ZN5Actor18DropShadowScaleXYZER11ShadowModelR9Matrix4x35Fix12IiES5_S5_j(void *self, void *sm, void *mtx, int a, int b, int d, unsigned int e);
extern short data_02082214[];
int func_ov065_02119794(char *c) {
    int d, b;
    int d1 = *(int*)(c+0x60) - *(int*)(c+0x37c);
    int ad = d1 < 0 ? -d1 : d1;
    if (ad > 0x9c4000) return ad;
    b = 0x32000;
    d = 0x190000;
    if (*(unsigned char*)(c+0x37a)) { b = 0x17c000; d = b; }
    Matrix4x3_FromRotationY(c+0x3a8, *(short*)(c+0x8e));
    *(int*)(c+0x3cc) = *(int*)(c+0x5c) >> 3;
    *(int*)(c+0x3d0) = (*(int*)(c+0x37c) + 0x1000) >> 3;
    *(int*)(c+0x3d4) = *(int*)(c+0x64) >> 3;
    {
        int idx = (unsigned short)(short)(*(short*)(c+0x90) << 1) >> 4;
        int s = data_02082214[idx << 1];
        int sa = s < 0 ? -s : s;
        int r3 = (int)(((long long)sa * 0x64000 + 0x800) >> 12);
        return _ZN5Actor18DropShadowScaleXYZER11ShadowModelR9Matrix4x35Fix12IiES5_S5_j(c, c+0x380, c+0x3a8, d + r3, b, d, 0xf);
    }
}
