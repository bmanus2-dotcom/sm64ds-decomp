//cpp
struct ModelAnim { ~ModelAnim(); };
struct MovingMeshCollider { ~MovingMeshCollider(); };
struct Model { ~Model(); };
struct Actor { ~Actor(); };
struct Heap;
namespace Memory { void Deallocate(void*, Heap*); }
extern void* data_ov002_02108e5c;
extern void* data_ov002_0210ae38;
extern Heap* data_020a0eac;
extern "C" void* func_ov002_020b4f44(void* self) {
    char* p = (char*)self;
    *(void**)p = &data_ov002_02108e5c;
    ((ModelAnim*)(p + 0x6b4))->~ModelAnim();
    ((MovingMeshCollider*)(p + 0x4ec))->~MovingMeshCollider();
    ((MovingMeshCollider*)(p + 0x324))->~MovingMeshCollider();
    *(void**)p = &data_ov002_0210ae38;
    ((MovingMeshCollider*)(p + 0x124))->~MovingMeshCollider();
    ((Model*)(p + 0xd4))->~Model();
    ((Actor*)p)->~Actor();
    Memory::Deallocate(self, data_020a0eac);
    return self;
}
