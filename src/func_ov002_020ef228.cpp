//cpp
struct ClsnResult {
    int GetClsnID() const;
};

struct WithMeshClsn {
    int IsOnWall() const;
    ClsnResult *GetWallResult() const;
};

typedef void (*VFn)(void *, void *);

struct Actor {
    static Actor *FindWithID(unsigned int);
};

extern "C" int func_ov002_020ef228(WithMeshClsn *self, void *other) {
    if (self->IsOnWall()) {
        ClsnResult *r = self->GetWallResult();
        if (r->GetClsnID() != -1) {
            Actor *a = Actor::FindWithID(r->GetClsnID());
            if (a) {
                VFn fn = *(VFn *)(*(char **)a + 0x58);
                fn(a, other);
                return 1;
            }
        }
    }
    return 0;
}
