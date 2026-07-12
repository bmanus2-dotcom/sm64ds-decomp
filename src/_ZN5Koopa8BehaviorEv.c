typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern int _ZN5Enemy26UpdateKillByInvincibleCharER12WithMeshClsnR9ModelAnimj(void *self, void *wm, void *ma, unsigned int j);
extern void _ZN5Actor19MakeVanishLuigiWorkER12CylinderClsn(void *self, void *c);
extern int _ZN5Enemy14UpdateYoshiEatER12WithMeshClsn(void *self, void *c);
extern int _ZN5Enemy27SpawnParticlesIfHitOtherObjER12CylinderClsn(void *self, void *c);
extern void _ZN5Actor8PoofDustEv(void *self);
extern void func_ov062_021179e4(void *c);
extern void _ZN5Actor24KillAndTrackInDeathTableEv(void *self);
extern void func_ov062_02117570(void *self);
extern void func_ov062_02118334(char *c);
extern void _ZN12CylinderClsn5ClearEv(void *c);
extern void _ZN12CylinderClsn6UpdateEv(void *c);
extern int _ZNK12WithMeshClsn10IsOnGroundEv(void *c);
extern int _ZN5Actor22IsTooFarAwayFromPlayerE5Fix12IiE(void *self, int d);
extern void func_ov062_02118258(void *self, int a);
extern void _ZN9Animation7AdvanceEv(void *a);
extern void func_ov062_02117acc(char *c);
extern void func_ov062_02117a3c(char *c);
extern void func_ov062_02117c98(char *c);
extern void _ZN5Actor9UpdatePosEP12CylinderClsn(void *self, void *c);
extern int _ZN5Enemy15IsGoingOffCliffER12WithMeshClsn5Fix12IiEsbbS3_(void *self, void *wm, int a, s16 b, int c, int d, int e);
extern void _ZN5Enemy12UpdateWMClsnER12WithMeshClsnj(void *self, void *wm, unsigned int j);
extern void _ZN5Enemy11UpdateDeathER12WithMeshClsn(void *self, void *wm);

int _ZN5Koopa8BehaviorEv(char *self)
{
    int state;
    int kind;

    if (_ZN5Enemy26UpdateKillByInvincibleCharER12WithMeshClsnR9ModelAnimj(
            self, self + 0x144, self + 0x300, 3) != 0)
        return 1;

    _ZN5Actor19MakeVanishLuigiWorkER12CylinderClsn(self, self + 0x110);

    if (_ZN5Enemy14UpdateYoshiEatER12WithMeshClsn(self, self + 0x144) != 0) {
        int *pb0 = (int *)(((long long)(int)(self + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL);
        *pb0 = *pb0 & ~0x10000000;
        if (_ZN5Enemy27SpawnParticlesIfHitOtherObjER12CylinderClsn(self, self + 0x110) != 0) {
            _ZN5Actor8PoofDustEv(self);
            func_ov062_021179e4(self);
            _ZN5Actor24KillAndTrackInDeathTableEv(self);
        }
        if (*(u8 *)(self + 0x107) != 0)
            func_ov062_02117570(self);
        func_ov062_02118334(self);
        _ZN12CylinderClsn5ClearEv(self + 0x110);
        if (*(u8 *)(self + 0x107) != 0 && *(u16 *)(self + 0x104) == 0)
            _ZN12CylinderClsn6UpdateEv(self + 0x110);
        if (*(int *)(self + 0x390) == 1)
            *(int *)(self + 0x38c) = 4;
        else
            *(int *)(self + 0x38c) = 1;
        if (_ZNK12WithMeshClsn10IsOnGroundEv(self + 0x144) != 0) {
            *(int *)(self + 0x3a8) = *(int *)(self + 0x5c);
            *(int *)(self + 0x3ac) = *(int *)(self + 0x60);
            *(int *)(self + 0x3b0) = *(int *)(self + 0x64);
        }
        return 1;
    }

    if (*(int *)(self + 0x10c) == 0) {
        if (_ZN5Actor22IsTooFarAwayFromPlayerE5Fix12IiE(self, 0x5dc000) != 0)
            return 1;

        {
            int *pb0 = (int *)(self + 0xb0);
            if (*(u8 *)(self + 0x3ce) != 0)
                *(u8 *)(((long long)(int)(self + 0x3ce)) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
            *pb0 = *pb0 | 0x10000000;
        }
        func_ov062_02118258(self, 0x3e8000);

        if (*(int *)(self + 0x38c) != 0)
            _ZN9Animation7AdvanceEv(self + 0x350);

        kind = *(int *)(self + 0x390);
        state = *(int *)(self + 0x38c);
        switch (kind) {
        case 0:
        case 2:
            func_ov062_02117acc(self);
            break;
        case 1:
            func_ov062_02117a3c(self);
            break;
        }

        {
            int ang = *(s16 *)(self + 0x94);
            *(s16 *)(self + 0x8e) = (s16)ang;
            {
                u16 *p100 = (u16 *)(((long long)(int)(self + 0x100)) & 0xFFFFFFFFFFFFFFFFLL);
                *p100 = (u16)(*p100 + 1);
            }
        }
        if (state != *(int *)(self + 0x38c) || kind != *(int *)(self + 0x390)) {
            *(u16 *)(self + 0x100) = 0;
            *(u16 *)(self + 0x3c4) = 0;
        }
        func_ov062_02117c98(self);
        _ZN5Actor9UpdatePosEP12CylinderClsn(self, self + 0x110);

        if (*(int *)(self + 0x10c) == 0 && *(int *)(self + 0x38c) != 0) {
            if (_ZN5Enemy15IsGoingOffCliffER12WithMeshClsn5Fix12IiEsbbS3_(
                    self, self + 0x144, 0x32000, 0x3800, 0, 1, 0x32000) != 0) {
                *(int *)(self + 0x5c) = *(int *)(self + 0x3a8);
                *(int *)(self + 0x60) = *(int *)(self + 0x3ac);
                *(int *)(self + 0x64) = *(int *)(self + 0x3b0);
            } else {
                *(int *)(self + 0x3a8) = *(int *)(self + 0x5c);
                *(int *)(self + 0x3ac) = *(int *)(self + 0x60);
                *(int *)(self + 0x3b0) = *(int *)(self + 0x64);
            }
        }

        _ZN5Enemy12UpdateWMClsnER12WithMeshClsnj(self, self + 0x144, 0);
        func_ov062_02117570(self);
        _ZN12CylinderClsn5ClearEv(self + 0x110);
        if (*(int *)(self + 0x10c) == 0) {
            if (*(u16 *)(self + 0x3ca) == 0) {
                _ZN12CylinderClsn6UpdateEv(self + 0x110);
            } else {
                *(u16 *)(((long long)(int)(self + 0x3ca)) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
            }
        }
    } else {
        _ZN5Enemy11UpdateDeathER12WithMeshClsn(self, self + 0x144);
    }

    func_ov062_02118334(self);
    return 1;
}
