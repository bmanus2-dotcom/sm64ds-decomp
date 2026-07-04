//cpp
// NONMATCHING: different op / idiom (div=18). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
struct V3 { int x, y, z; };
extern void Actor_UpdatePos(void *c, void *clsn);
extern void *Particle_System_New(unsigned int a, unsigned int b, int f, int t1, int t2, void *v, void *cb);
extern void *Particle_System_NewUnkCallback818(unsigned int a, unsigned int b, int f, int t1, int t2, void *v);
extern void *Particle_System_FromUniqueID(unsigned int id);
extern void func_02038414(void *p);
extern int WithMeshClsn_JustHitGround(void *p);
extern void func_ov096_0213585c(void *t);

int func_ov096_02136434(void *c)
{
    Actor_UpdatePos(c, (char*)c+0x14c);
    if (*(int*)((char*)c+0x3a0) != 0 && *(int*)((char*)c+0x3a4) != 0) {
        volatile struct V3 pos;
        void *p0;
        void *p1;
        pos.x = *(int*)((char*)c+0x5c);
        pos.y = *(int*)((char*)c+0x60) + 0x3c000;
        pos.z = *(int*)((char*)c+0x64);
        *(void**)((char*)c+0x3a0) = Particle_System_New(*(int*)((char*)c+0x3a0), 0x13a, pos.x, pos.y, pos.z, 0, 0);
        *(void**)((char*)c+0x3a4) = Particle_System_NewUnkCallback818(*(int*)((char*)c+0x3a4), 0x13b, pos.x, pos.y, pos.z, 0);
        p0 = Particle_System_FromUniqueID(*(int*)((char*)c+0x3a0));
        p1 = Particle_System_FromUniqueID(*(int*)((char*)c+0x3a4));
        if (p0) *(int*)((char*)p0+0x50) = 0x7fff;
        if (p1) *(int*)((char*)p1+0x50) = 0x7fff;
    }
    func_02038414((char*)c+0x180);
    if (WithMeshClsn_JustHitGround((char*)c+0x180) != 0) {
        func_ov096_0213585c(c);
    }
    return 1;
}
}
