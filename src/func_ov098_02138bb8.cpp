//cpp
extern "C" {
extern int _ZNK12WithMeshClsn10IsOnGroundEv(void *);
extern void *_ZNK12WithMeshClsn14GetFloorResultEv(void *);
extern int func_02037e78(int *p);
int func_ov098_02138bb8(char *c)
{
    if (_ZNK12WithMeshClsn10IsOnGroundEv(c + 0x320))
    {
        if (func_02037e78((int *)((char *)_ZNK12WithMeshClsn14GetFloorResultEv(c + 0x320) + 4)))
            return 1;
    }
    return 0;
}
}
