// NONMATCHING: different op / idiom (div=44). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int Vec3_Dist(void* a, void* b);
extern int func_ov062_02115f84(char* c);
extern int func_ov062_02116cd8(void* c, void* p);
extern void ApproachAngle(void* p, int target, int a, int b, int limit);
extern char* _ZN5Actor13ClosestPlayerEv(void);
extern int _ZN5Sound8PlayLongEjjjRK7Vector3j(unsigned int, unsigned int, unsigned int, void*, unsigned int);
extern char data_ov062_0211df00[];
extern char data_ov062_0211de70[];
extern char data_ov062_0211de90[];
extern char data_ov062_0211dee0[];
int func_ov062_02116a08(char* c) {
    int vd0[3];
    int vd1[3];
    int r;
    char* pl;
    vd0[0] = 0;
    vd0[1] = 0;
    vd0[2] = 0;
    Vec3_Dist(c+0x5c, c+0x3c0);
    r = func_ov062_02115f84(c);
    if (r == 0) {
        if (*(unsigned char*)(c+0x3e4) == 1) {
            if (r == 2) {
                func_ov062_02116cd8(c, data_ov062_0211df00);
            } else {
                func_ov062_02116cd8(c, data_ov062_0211de70);
            }
            return 1;
        }
    }
    ApproachAngle(c+0x94, *(short*)(c+0x3f4), 0xa, 0x200, 0x100);
    pl = (*(int*)(c+0x98) = 0xa000, _ZN5Actor13ClosestPlayerEv());
    *(int*)(c+0x3ec) = _ZN5Sound8PlayLongEjjjRK7Vector3j(*(unsigned int*)(c+0x3ec), 3, 0x18a, c+0x74, 0);
    if (pl != 0 && *(unsigned short*)(c+0x3e8) == 0) {
        vd1[0] = *(int*)(pl+0x5c);
        vd1[1] = *(int*)(pl+0x60);
        vd1[2] = *(int*)(pl+0x64);
        if (Vec3_Dist(c+0x3c0, vd1) < 0x3e8000) {
            *(int*)(c+0x98) = 0;
            func_ov062_02116cd8(c, data_ov062_0211de90);
            return 1;
        }
    }
    if (*(unsigned short*)(c+0x100) != 0) {
        func_ov062_02116cd8(c, data_ov062_0211dee0);
    }
    return 1;
}
