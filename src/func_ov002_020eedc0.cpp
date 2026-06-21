//cpp
struct ClsnResult {
    int GetClsnID() const;
};
struct WithMeshClsn {
    bool IsOnWall() const;
    ClsnResult *GetWallResult() const;
};
struct Actor {
    static Actor *FindWithID(unsigned int);
    virtual void v0();
};
extern "C" {

int func_ov002_020eedc0(WithMeshClsn *self, int arg)
{
    Actor *a;
    ClsnResult *res;
    if (!self->IsOnWall())
        goto fail;
    res = self->GetWallResult();
    if (res->GetClsnID() == -1)
        goto fail;
    a = Actor::FindWithID(res->GetClsnID());
    if (!a)
        goto fail;
    (*(void (**)(Actor *, int))(*(void ***)a + 0x68 / 4))(a, arg);
    return 1;
fail:
    return 0;
}
}
