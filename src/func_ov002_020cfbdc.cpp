//cpp
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

struct Vec3 { int x, y, z; };
struct RaycastLine { char pad[0x14]; char surf[0x64]; };

extern "C" {
extern s16 data_02082214[];
extern int data_ov002_021101b4;
extern int _ZNK12WithMeshClsn10IsOnGroundEv(void *clsn);
extern void *_ZNK12WithMeshClsn14GetFloorResultEv(void *clsn);
extern int _ZNK10ClsnResult9GetClsnIDEv(void *res);
extern void *_ZN5Actor10FindWithIDEj(unsigned int id);
extern void func_ov002_020d0948(void *p);
extern void _ZN11RaycastLineC1Ev(RaycastLine *rc);
extern void _ZN11RaycastLine13SetObjAndLineERK7Vector3S2_P5Actor(RaycastLine *rc, Vec3 *a, Vec3 *b, void *actor);
extern int _ZN11RaycastLine10DetectClsnEv(RaycastLine *rc);
extern void _ZN11RaycastLineD1Ev(RaycastLine *rc);
extern void _ZN6Player11ChangeStateERNS_5StateE(char *c, void *st);
extern void func_ov002_020e30a0(void *p);

int func_ov002_020cfbdc(char *r7)
{
    s16 ang;
    int idx;
    int r6;
    int r5;
    int r4;
    Vec3 sp0c;
    Vec3 sp18;
    RaycastLine rc;

    ang = *(s16 *)(r7 + 0x8e);
    idx = ((ang + 0x8000) << 16) >> 16;
    idx = (idx >> 4) & 0xffff;
    r6 = data_02082214[idx * 2];
    r5 = data_02082214[idx * 2 + 1];

    if (*(u16 *)(r7 + 0x6a6) == 0 && (*(u8 *)(r7 + 0x6e9) & 2) != 0) {
        if (_ZNK12WithMeshClsn10IsOnGroundEv(r7 + 0x380) != 0) {
            void *floor;
            int id;
            floor = _ZNK12WithMeshClsn14GetFloorResultEv(r7 + 0x380);
            id = _ZNK10ClsnResult9GetClsnIDEv(floor);
            if (id != -1) {
                id = _ZNK10ClsnResult9GetClsnIDEv(floor);
                if (_ZN5Actor10FindWithIDEj((unsigned int)id) != 0) {
                    func_ov002_020d0948(r7);
                    return 1;
                }
            }
        }
    }

    sp0c.x = *(int *)(r7 + 0x5c) + (r6 << 5);
    sp0c.y = *(int *)(r7 + 0x60) - 0xa000;
    sp0c.z = *(int *)(r7 + 0x64) + (r5 << 5);
    sp18.x = *(int *)(r7 + 0x5c) + (r6 * 0x60);
    sp18.y = *(int *)(r7 + 0x60) - 0xa000;
    sp18.z = *(int *)(r7 + 0x64) + (r5 * 0x60);
    r4 = r5 * 0x60;

    _ZN11RaycastLineC1Ev(&rc);
    _ZN11RaycastLine13SetObjAndLineERK7Vector3S2_P5Actor(&rc, &sp0c, &sp18, r7);
    if (_ZN11RaycastLine10DetectClsnEv(&rc) != 0) {
        *(int *)(r7 + 0x5c) += r4;
        *(int *)(r7 + 0x60) -= 0x80000;
        *(int *)(r7 + 0x64) += r4;
        func_ov002_020e30a0(r7);
        _ZN6Player11ChangeStateERNS_5StateE(r7, &data_ov002_021101b4);
        _ZN11RaycastLineD1Ev(&rc);
        return 1;
    }

    _ZN11RaycastLineD1Ev(&rc);
    return 0;
}
}