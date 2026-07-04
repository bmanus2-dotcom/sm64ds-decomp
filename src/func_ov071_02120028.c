// NONMATCHING: base materialization / addressing (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Vec3 { int x, y, z; };
void _ZN9Animation7AdvanceEv(void *p);
void _ZN5Actor9UpdatePosEP12CylinderClsn(void *thiz, void *clsn);
void func_02038420(void *p);
int _ZNK12WithMeshClsn13JustHitGroundEv(void *p);
void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int effect, struct Vec3 v);
int _ZNK12WithMeshClsn10IsOnGroundEv(void *p);
void _ZN12WithMeshClsn15ClearLimMovFlagEv(void *p);
void func_ov071_021202ec(void *c, int mode);
void func_ov071_0211f29c(void *thiz);
void _ZN12CylinderClsn5ClearEv(void *p);
void _ZN12CylinderClsn6UpdateEv(void *p);

int func_ov071_02120028(char *c) {
    _ZN9Animation7AdvanceEv(c + 0x124);
    _ZN5Actor9UpdatePosEP12CylinderClsn(c, c + 0x160);
    func_02038420(c + 0x194);
    if (_ZNK12WithMeshClsn13JustHitGroundEv(c + 0x194)) {
        struct Vec3 v;
        v.x = *(int*)(c + 0x5c);
        v.y = *(int*)(c + 0x60) + 0x28000;
        v.z = *(int*)(c + 0x64);
        _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0xb2, v);
        *(int*)(c + 0xa8) = (*(int*)(c + 0xa8) * -40) / 100;
    } else if (_ZNK12WithMeshClsn10IsOnGroundEv(c + 0x194)) {
        *(int*)(c + 0xa8) = 0;
        _ZN12WithMeshClsn15ClearLimMovFlagEv(c + 0x194);
        *(int*)(c + 0x390) = *(int*)(c + 0x5c);
        *(int*)(c + 0x394) = *(int*)(c + 0x60);
        *(int*)(c + 0x398) = *(int*)(c + 0x64);
        *(int*)(c + 0xb0) |= 0x10000001;
        func_ov071_021202ec(c, 2);
        func_ov071_0211f29c(c);
    }
    _ZN12CylinderClsn5ClearEv(c + 0x160);
    _ZN12CylinderClsn6UpdateEv(c + 0x160);
    return 1;
}
