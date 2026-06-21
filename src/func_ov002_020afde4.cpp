//cpp
extern "C" {
struct Actor;
Actor *_ZN5Actor13ClosestPlayerEv(Actor *self);
short Vec3_HorzAngle(const void *a, const void *b);
void func_ov002_020af3a8(Actor *self);
int _ZNK12WithMeshClsn8IsOnWallEv(void *clsn);
int _ZN5Actor15IsPlayerInRangeEi(Actor *self, int r);
}

extern "C" void func_ov002_020afde4(Actor *self) {
    char *p = (char *)self;
    Actor *cp = _ZN5Actor13ClosestPlayerEv(self);
    if (cp) {
        *(short *)(p + 0x94) = Vec3_HorzAngle(p + 0x5c, (char *)cp + 0x5c) + 0x8000;
    }
    func_ov002_020af3a8(self);
    if (_ZNK12WithMeshClsn8IsOnWallEv(p + 0x144)) {
        *(int *)(p + 0x388) = 2;
    }
    if (_ZN5Actor15IsPlayerInRangeEi(self, 0xbb8) == 0) {
        *(int *)(p + 0x388) = 2;
    }
}
