//cpp

extern "C" int _ZN16MeshColliderBase9IsEnabledEv(void *self);
extern "C" void _ZN16MeshColliderBase7DisableEv(void *self);
extern "C" void _ZN13SharedFilePtr7ReleaseEv(void *self);

struct MeshColliderBase {
    int IsEnabled() { return _ZN16MeshColliderBase9IsEnabledEv(this); }
    void Disable() { _ZN16MeshColliderBase7DisableEv(this); }
};

struct SharedFilePtr {
    void Release() { _ZN13SharedFilePtr7ReleaseEv(this); }
};

struct FileEntry {
    SharedFilePtr *fileptr;  // 0x0
    char pad[0xc - 4];
};

extern "C" FileEntry data_ov002_02108ab0[];  // wildcard address
extern "C" FileEntry data_ov002_02108ab4[];

struct Obj {
    char pad124[0x124];
    MeshColliderBase collider;   // 0x124
    char pad328[0x32c - 0x124 - (int)sizeof(MeshColliderBase)];
    unsigned char f32c;          // 0x32c
};

extern "C" int func_ov002_020b3ab0(Obj *self) {
    if (self->collider.IsEnabled()) {
        self->collider.Disable();
    }
    data_ov002_02108ab0[self->f32c].fileptr->Release();
    data_ov002_02108ab4[self->f32c].fileptr->Release();
    return 1;
}
