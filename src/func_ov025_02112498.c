typedef struct SharedFilePtr SharedFilePtr;

extern int _ZN5Model8LoadFileER13SharedFilePtr(SharedFilePtr *p);
extern void _ZN9ModelBase7SetFileEP8BMD_Fileii(char *m, int file, int a, int b);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(char *a);
extern int _ZN12MeshCollider8LoadFileER13SharedFilePtr(SharedFilePtr *p);
extern void _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(char *m, int kcl, char *mtx, int spd, int sh, char *clps);
extern void func_020393d4(char *p, int v);
extern void func_020393c4(char *p, int v);
extern void _ZN16MeshColliderBase22UpdatePosWithTransformERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_(void);
extern void func_ov025_021125dc(void);

extern SharedFilePtr data_ov025_02113ae0;
extern SharedFilePtr data_ov002_0210d9f0;
extern SharedFilePtr data_ov025_02113ad8;
extern char data_ov025_02112d08[];

int func_ov025_02112498(char *c)
{
    int i;
    char *p;

    _ZN9ModelBase7SetFileEP8BMD_Fileii(c + 0xd4, _ZN5Model8LoadFileER13SharedFilePtr(&data_ov025_02113ae0), 1, -1);
    _ZN9ModelBase7SetFileEP8BMD_Fileii(c + 0x320, _ZN5Model8LoadFileER13SharedFilePtr(&data_ov002_0210d9f0), 1, -1);
    _ZN8Platform19UpdateClsnPosAndRotEv(c);
    _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(
        c + 0x124,
        _ZN12MeshCollider8LoadFileER13SharedFilePtr(&data_ov025_02113ad8),
        c + 0x2ec, 0x199, *(short *)(c + 0x8e), data_ov025_02112d08);
    func_020393d4(c + 0x124, (int)&_ZN16MeshColliderBase22UpdatePosWithTransformERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_);
    func_020393c4(c + 0x124, (int)&func_ov025_021125dc);
    *(int *)(c + 0x370) = *(int *)(c + 0x5c);
    *(int *)(c + 0x374) = *(int *)(c + 0x60);
    *(int *)(c + 0x378) = *(int *)(c + 0x64);
    *(unsigned char *)(c + 0x3f6) = 0;
    *(unsigned char *)(c + 0x3f7) = 0;
    i = 0;
    p = c;
    do {
        *(int *)(p + 0x37c) = *(int *)(c + 0x5c);
        *(int *)(p + 0x380) = *(int *)(c + 0x60);
        *(int *)(p + 0x384) = *(int *)(c + 0x64);
        i++;
        *(int *)(int)(((long long)(int)(p + 0x380)) & 0xFFFFFFFFFFFFFFFFLL) -=
            (int)(((long long)i) & 0xFFFFFFFFFFFFFFFFLL) * 0x1cc000;
        p += 0xc;
    } while (i < 10);
    return 1;
}
