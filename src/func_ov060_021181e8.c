extern void _ZN16MeshColliderBase7DisableEv(void *);
extern void _ZN13SharedFilePtr7ReleaseEv(void *);
extern void *data_ov060_02119514[];
extern void *data_ov060_0211953c[];
int func_ov060_021181e8(char *c)
{
    _ZN16MeshColliderBase7DisableEv(c + 0x124);
    _ZN13SharedFilePtr7ReleaseEv(data_ov060_02119514[*(unsigned char *)(c + 0x329)]);
    _ZN13SharedFilePtr7ReleaseEv(data_ov060_0211953c[*(unsigned char *)(c + 0x329)]);
    return 1;
}
