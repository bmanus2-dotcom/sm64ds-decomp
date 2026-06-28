//cpp
extern "C" {
struct Vector3 { int x, y, z; };
extern int func_ov091_02133254(void* c);
extern void _ZN11RaycastLineC1Ev(void* self);
extern void _ZN11RaycastLine13SetObjAndLineERK7Vector3S2_P5Actor(void* self, void* a, void* b, void* act);
extern int _ZN11RaycastLine10DetectClsnEv(void* self);
extern void _ZN11RaycastLine10GetClsnPosEv(void* out, void* self);
extern void _ZN11RaycastLineD1Ev(void* self);
extern int data_ov025_02113814[];
int func_ov025_02111c24(char* c)
{
    *(void**)(c + 0x320) = data_ov025_02113814;
    int r = func_ov091_02133254(c);
    if (*(int*)(c + 8) & 1) {
        *(int*)(c + 0x398) = 6;
    } else {
        *(int*)(c + 0x398) = 0;
        char rl[0x78];
        Vector3 va;
        Vector3 vb;
        Vector3 p1;
        Vector3 p2;
        _ZN11RaycastLineC1Ev(rl);
        int x = *(int*)(c + 0x5c);
        vb.x = x;
        int y = *(int*)(c + 0x60);
        vb.y = y;
        int z = *(int*)(c + 0x64);
        va.x = x;
        vb.z = z;
        va.y = y;
        va.z = z;
        vb.y = y + 0x7d0000;
        _ZN11RaycastLine13SetObjAndLineERK7Vector3S2_P5Actor(rl, &va, &vb, c);
        if (_ZN11RaycastLine10DetectClsnEv(rl) != 0) {
            _ZN11RaycastLine10GetClsnPosEv(&p1, rl);
            _ZN11RaycastLine10GetClsnPosEv(&p2, rl);
            *(int*)(c + 0x390) = p2.y - 0x190000;
        }
        _ZN11RaycastLineD1Ev(rl);
    }
    return r;
}
}
