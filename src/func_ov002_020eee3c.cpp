//cpp
struct ClsnResult { unsigned int GetClsnID() const; };
struct WithMeshClsn {
    bool IsOnWall() const;
    ClsnResult *GetWallResult() const;
};
struct Actor {
    static Actor *FindWithID(unsigned int);
    virtual void v0();
};

extern "C" int func_ov002_020eee3c(WithMeshClsn *self, void *arg)
{
    if (self->IsOnWall()) {
        ClsnResult *res = self->GetWallResult();
        if ((int)res->GetClsnID() != -1) {
            Actor *a = Actor::FindWithID(res->GetClsnID());
            if (a != 0) {
                (*(void (**)(Actor *, void *))(*(int *)a + 0x64))(a, arg);
                return 1;
            }
        }
    }
    return 0;
}
