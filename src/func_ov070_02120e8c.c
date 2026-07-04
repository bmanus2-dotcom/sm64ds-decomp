//cpp
// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
extern void func_ov070_02120d34(void *c);
extern void _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(void *self, void *v);
extern void _ZN12CylinderClsn5ClearEv(void *self);
extern void _ZN12CylinderClsn6UpdateEv(void *self);
extern void func_ov070_02120724(void *c);
extern int data_ov070_0212365c[];
int func_ov070_02120e8c(char *c)
{
    func_ov070_02120d34(c);
    *(int *)(c + 0x414) += data_ov070_0212365c[1];
    _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(c + 0x1d8, c + 0x410);
    _ZN12CylinderClsn5ClearEv(c + 0x1d8);
    _ZN12CylinderClsn6UpdateEv(c + 0x1d8);
    func_ov070_02120724(c);
    return 1;
}
}
