//cpp
// NONMATCHING: different op / idiom (div=19). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12;
struct MeshColliderBase { bool IsEnabled(); void Disable(); };
struct Platform {
    void UpdateModelPosAndRotY();
    bool IsClsnInRange(Fix12 a, Fix12 b);
    void UpdateClsnPosAndRot();
};

extern "C" int func_ov036_02111e20(char *c)
{
    short *s = (short *)(c + 0x8e);
    *s = (short)(*s + *(short *)(c + 0x31e));
    int b = (int)((*(int *)(c + 0xb0) & 8) != 0);
    if (b != 0) {
        if (((MeshColliderBase *)(c + 0x124))->IsEnabled())
            ((MeshColliderBase *)(c + 0x124))->Disable();
        return 1;
    }
    Platform *p = (Platform *)c;
    p->UpdateModelPosAndRotY();
    if (p->IsClsnInRange(0, 0))
        p->UpdateClsnPosAndRot();
    return 1;
}
