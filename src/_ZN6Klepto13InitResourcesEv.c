typedef int Fix12;
typedef struct { int h; } SharedFilePtr;
typedef struct { int x, y, z; } Vector3;

extern void *_ZN5Model8LoadFileER13SharedFilePtr(SharedFilePtr *f);
extern int _ZN9ModelBase7SetFileEP8BMD_Fileii(void *self, void *f, int a, int b);
extern int _ZN11ShadowModel12InitCylinderEv(void *self);
extern void *_ZN9Animation8LoadFileER13SharedFilePtr(SharedFilePtr *f);
extern void _ZN7PathPtrC1Ev(void *self);
extern void _ZN7PathPtr6FromIDEj(void *self, unsigned int id);
extern void _ZNK7PathPtr7GetNodeER7Vector3j(void *self, void *v, unsigned int idx);
extern void _ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj(void *self, void *a, Fix12 r, Fix12 h, unsigned int d, unsigned int e);
extern void _ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_(void *self, void *a, Fix12 b, Fix12 c, void *d, void *e);
extern void *_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int a, unsigned int b, void *pos, void *rot, int e, int f);
extern void _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_(void *self, Fix12 a, Fix12 b, Fix12 c, Fix12 d);
extern int _ZN8SaveData16HasPlayerLostCapEv(void);
extern void func_ov062_0211c658(void *c, void *p);
extern short Vec3_HorzAngle(const Vector3 *a, const Vector3 *b);

extern SharedFilePtr data_ov062_0211e0fc;
extern SharedFilePtr data_ov062_0211e114;
extern SharedFilePtr data_ov062_0211e10c;
extern SharedFilePtr data_ov062_0211e104;
extern SharedFilePtr data_ov002_0210da40;
extern SharedFilePtr data_ov002_0210d9a0;
extern SharedFilePtr data_ov002_0210d9c0;
extern char data_ov062_0211e15c;
extern char data_ov062_0211e17c;
extern void *data_0209f394;

int _ZN6Klepto13InitResourcesEv(char *o)
{
    void *bmd;
    void *spawned;
    void *pl;
    char path1[8];
    char path2[8];
    unsigned char hat;
    int area;
    int param;
    int zero;
    

    bmd = _ZN5Model8LoadFileER13SharedFilePtr(&data_ov062_0211e0fc);
    _ZN9ModelBase7SetFileEP8BMD_Fileii(o + 0x334, bmd, 1, -1);
    _ZN11ShadowModel12InitCylinderEv(o + 0x3a4);
    _ZN9Animation8LoadFileER13SharedFilePtr(&data_ov062_0211e114);
    _ZN9Animation8LoadFileER13SharedFilePtr(&data_ov062_0211e10c);
    _ZN9Animation8LoadFileER13SharedFilePtr(&data_ov062_0211e104);
    _ZN5Model8LoadFileER13SharedFilePtr(&data_ov002_0210da40);
    _ZN5Model8LoadFileER13SharedFilePtr(&data_ov002_0210d9a0);
    _ZN5Model8LoadFileER13SharedFilePtr(&data_ov002_0210d9c0);

    *(int *)(o + 0x464) = *(unsigned int *)(o + 8) & 0xff;
    *(int *)(o + 0x468) = (*(unsigned int *)(o + 8) >> 8) & 0xf;
    *(int *)(o + 0x46c) = (*(unsigned int *)(o + 8) >> 0xc) & 0xf;
    if (*(int *)(o + 0x464) < 0)
        *(int *)(o + 0x464) = 0;
    if (*(int *)(o + 0x468) == 0xff)
        *(int *)(o + 0x468) = 0;
    if (*(int *)(o + 0x468) == 2) {
        *(unsigned char *)(o + 0x448) = 2;
        *(int *)(o + 0x468) = 1;
    }

    _ZN7PathPtrC1Ev(path1);
    _ZN7PathPtr6FromIDEj(path1, *(unsigned int *)(o + 0x464));
    *(int *)(o + 0x470) = 4;
    *(int *)(o + 0xa0) = -0x1e000;
    *(int *)(o + 0x484) = *(int *)(o + 0x5c);
    *(int *)(o + 0x488) = *(int *)(o + 0x60);
    *(int *)(o + 0x48c) = *(int *)(o + 0x64);
    _ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj(o + 0x110, o, 0x64000, 0xa0000, 0x200002, 0x3eff0);
    _ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj(o + 0x144, o, 0x3c000, 0xa0000, 0x200000, 0);
    _ZN12WithMeshClsn4InitEP5Actor5Fix12IiES3_P10Vector3_16S5_(o + 0x178, o, 0x1e000, 0x1e000, 0, 0);

    _ZN7PathPtrC1Ev(path2);
    _ZN7PathPtr6FromIDEj(path2, *(unsigned int *)(o + 0x464));
    _ZNK7PathPtr7GetNodeER7Vector3j(path2, o + 0x430, *(unsigned int *)(o + 0x474));
    *(int *)(o + 0x390) = 0x1000;
    *(int *)(o + 0x44c) = 0;

    if (*(int *)(o + 0x468) == 1) {
        if (*(unsigned char *)(o + 0x448) != 2) {
            spawned = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
                0xb2, *(int *)(o + 0x46c) | 0x50, o + 0x5c, 0, *(signed char *)(o + 0xcc), -1);
        } else {
            spawned = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
                0xb3, 0x50, o + 0x5c, 0, *(signed char *)(o + 0xcc), -1);
        }
        if (spawned != 0) {
            *(int *)(o + 0x44c) = *(int *)((char *)spawned + 4);
            _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_(spawned, 0x64000, 0x258000, 0x1f40000, 0x1f40000);
        }
        *(int *)(o + 0x5c) = *(int *)(o + 0x430);
        *(int *)(o + 0x60) = *(int *)(o + 0x434);
        *(int *)(o + 0x64) = *(int *)(o + 0x438);
        func_ov062_0211c658(o, &data_ov062_0211e15c);
    } else {
        pl = data_0209f394;
        if (pl != 0 && *(int *)((char *)pl + 8) != 3 && _ZN8SaveData16HasPlayerLostCapEv() != 0) {
            {
                unsigned int hat = *(unsigned char *)((char *)pl + 0x6d9);
                int area = *(signed char *)(o + 0xcc);
                unsigned int param = 0;
                param = param | (hat << 8);
                spawned = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
                    0x10d, param, o + 0x5c, 0, area, -1);
            }
            if (spawned != 0) {
                _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_(spawned, 0x64000, 0x258000, 0x1f40000, 0x1f40000);
                *(int *)(o + 0x44c) = *(int *)((char *)spawned + 4);
            }
        }
        *(short *)(o + 0x44a) = Vec3_HorzAngle((Vector3 *)(o + 0x5c), (Vector3 *)(o + 0x484));
        func_ov062_0211c658(o, &data_ov062_0211e17c);
    }
    return 1;
}
