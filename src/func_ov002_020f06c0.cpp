//cpp
class ActorBase {
public:
    void MarkForDestruction();
};
class Actor {
public:
    static Actor *FindWithActorID(unsigned int id, Actor *p);
};
class CylinderClsn {
public:
    void Clear();
    void Update();
};
extern "C" unsigned char DecIfAbove0_Byte(unsigned char* p);
extern "C" void func_ov002_020f05f4(void *o);
extern "C" void func_ov002_020f051c(void *o);
extern "C" void func_ov002_020f0438(void *o);

extern "C" int func_ov002_020f06c0(char *c)
{
    if (*(unsigned char *)(c + 0x113)) {
        if (DecIfAbove0_Byte((unsigned char *)(c + 0x113)) == 0) {
            func_ov002_020f05f4(c);
            ((ActorBase *)c)->MarkForDestruction();
        }
        return 1;
    }
    if (*(unsigned char *)(c + 0x10f) == 0) {
        unsigned char st = *(unsigned char *)(c + 0x10e);
        if (st == 0 || st == 0xf) {
            {
                Actor *o = 0;
                *(unsigned char *)(c + 0x10f) = 1;
                *(int *)(c + 0x108) = *(int *)(c + 4);
                for (;;) {
                    o = Actor::FindWithActorID(0x149, o);
                    if (o == 0) break;
                    if (o != (Actor *)c) {
                        *(unsigned char *)((char *)o + 0x10f) = 2;
                        *(int *)((char *)o + 0x108) = *(int *)(c + 4);
                    }
                }
            }
        }
    }
    if (*(unsigned char *)(c + 0x10f) == 1 && *(unsigned char *)(c + 0x110) == 5) {
        ((ActorBase *)c)->MarkForDestruction();
        return 1;
    }
    func_ov002_020f051c(c);
    if (*(int *)(c + 0xf8)) {
        func_ov002_020f0438(c);
    }
    ((CylinderClsn *)(c + 0xd4))->Clear();
    if (*(unsigned char *)(c + 0x111) == 0) {
        ((CylinderClsn *)(c + 0xd4))->Update();
    }
    return 1;
}
