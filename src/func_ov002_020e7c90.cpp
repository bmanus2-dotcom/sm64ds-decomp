//cpp
struct Vector3 { int x, y, z; };
struct Actor {
    char pad[8];
    unsigned int actorFlags; // 0x8
    char pad2[0x5c-0xc];
    Vector3 pos; // 0x5c
    static Actor* FindWithActorID(unsigned int id, Actor* prev);
};
struct Camera {
    void SetLookAt(const Vector3& v);
    void SetPos(const Vector3& v);
};

extern "C" int func_ov002_020e7c90(void* self, Camera* cam)
{
    unsigned int id = 0xb1;
    Actor* a = 0;
    for (;;) {
        a = Actor::FindWithActorID(id, a);
        if (a == 0) break;
        if (*(unsigned char*)((char*)self + 0x49d) == (a->actorFlags & 0xf)) {
            cam->SetLookAt(*(Vector3*)((char*)self + 0x5c));
            cam->SetPos(a->pos);
            return 1;
        }
    }
    return 0;
}
