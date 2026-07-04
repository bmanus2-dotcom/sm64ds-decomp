//cpp
// NONMATCHING: different op / idiom (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct CylinderClsn { void Clear(); void Update(); };
struct WithMeshClsn {
    bool JustHitGround() const;
    bool IsOnGround() const;
    void ClearLimMovFlag();
};
struct Actor { void UpdatePos(CylinderClsn* c); };

extern "C" void func_02038414(void* p);
extern "C" void func_ov081_021265c8(void* c);
extern "C" void func_ov081_02126758(void* c);

extern "C" bool func_ov081_02126d64(Actor* self) {
    char* s = (char*)self;
    func_02038414(s + 0x1e4);
    *(short*)(s + 0x8c) += 0x1000;
    if (((WithMeshClsn*)(s + 0x1e4))->JustHitGround()) {
        *(int*)(s + 0xa8) = *(int*)(s + 0xa8) * -0x3c / 100;
    } else if (((WithMeshClsn*)(s + 0x1e4))->IsOnGround()) {
        *(int*)(s + 0xa8) = 0;
        ((WithMeshClsn*)(s + 0x1e4))->ClearLimMovFlag();
    }
    short v94 = *(short*)(s + 0x94);
    *(short*)(s + 0x8c) = 0;
    *(short*)(s + 0x8e) = v94;
    *(short*)(s + 0x90) = 0;
    func_ov081_021265c8(self);
    ((Actor*)self)->UpdatePos((CylinderClsn*)(s + 0x1b0));
    func_ov081_02126758(self);
    ((CylinderClsn*)(s + 0x1b0))->Clear();
    ((CylinderClsn*)(s + 0x1b0))->Update();
    return true;
}
