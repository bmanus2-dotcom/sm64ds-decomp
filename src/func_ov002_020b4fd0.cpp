//cpp
struct Actor;
struct MeshColliderBase {
    int IsEnabled();
    void Disable();
    void Enable(Actor *);
};

struct Obj {
    char pad[0xb0];
    unsigned int fb0;            /* +0xb0 */
    char pad2[0x320 - 0xb4];
    MeshColliderBase *f320;      /* +0x320 */
};

extern "C" int func_ov002_020b4fd0(Obj *self) {
    int on = (self->fb0 & 8) ? 1 : 0;
    if (on) {
        if (self->f320->IsEnabled()) {
            self->f320->Disable();
        }
        return 1;
    }
    if (!self->f320->IsEnabled()) {
        self->f320->Enable((Actor *)self);
    }
    return 0;
}
