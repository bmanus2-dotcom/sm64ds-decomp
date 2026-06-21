//cpp
extern "C" void _ZN9ModelAnimD1Ev(void*);
extern "C" void _ZN18MovingMeshColliderD1Ev(void*);
extern "C" void _ZN5ModelD1Ev(void*);
extern "C" void _ZN5ActorD1Ev(void*);
extern void *data_ov002_02108e5c;
extern void *data_ov002_0210ae38;
extern "C" void *func_ov002_020b4ed8(void *self) {
    char *b = (char*)self;
    *(void**)b = &data_ov002_02108e5c;
    _ZN9ModelAnimD1Ev(b + 0x6b4);
    _ZN18MovingMeshColliderD1Ev(b + 0x4ec);
    _ZN18MovingMeshColliderD1Ev(b + 0x324);
    *(void**)b = &data_ov002_0210ae38;
    _ZN18MovingMeshColliderD1Ev(b + 0x124);
    _ZN5ModelD1Ev(b + 0xd4);
    _ZN5ActorD1Ev(self);
    return self;
}
