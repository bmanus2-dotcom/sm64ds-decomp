extern int _ZN8Platform21UpdateModelPosAndRotYEv(void *c);
extern int _ZN8Platform13IsClsnInRangeE5Fix12IiES1_(void *c, int a, int b);
extern int _ZN8Platform19UpdateClsnPosAndRotEv(void *c);
int func_ov045_0211129c(char *c)
{
    switch (*(unsigned char*)(c + 0x327)) {
    case 0:
        if (*(unsigned char*)(c + 0x326) != 0)
            *(unsigned char*)(((int)c + 0x327) & 0xFFFFFFFFFFFFFFFF) =
                *(unsigned char*)(((int)c + 0x327) & 0xFFFFFFFFFFFFFFFF) + 1;
        break;
    case 1:
        if (*(unsigned short*)(c + 0x324) >= 0x14) {
            int lim;
            *(int*)(((int)c + 0x60) & 0xFFFFFFFFFFFFFFFF) =
                *(int*)(((int)c + 0x60) & 0xFFFFFFFFFFFFFFFF) + 0xa000;
            lim = *(int*)(c + 0x320) + 0x5dc000;
            if (*(int*)(c + 0x60) >= lim) {
                *(int*)(c + 0x60) = lim;
                *(unsigned char*)(((int)c + 0x327) & 0xFFFFFFFFFFFFFFFF) =
                    *(unsigned char*)(((int)c + 0x327) & 0xFFFFFFFFFFFFFFFF) + 1;
                *(unsigned short*)(c + 0x324) = 0;
            }
        } else {
            *(unsigned short*)(((int)c + 0x324) & 0xFFFFFFFFFFFFFFFF) =
                *(unsigned short*)(((int)c + 0x324) & 0xFFFFFFFFFFFFFFFF) + 1;
        }
        break;
    case 2:
        if (*(unsigned short*)(c + 0x324) >= 0x14) {
            int lim;
            *(int*)(((int)c + 0x60) & 0xFFFFFFFFFFFFFFFF) =
                *(int*)(((int)c + 0x60) & 0xFFFFFFFFFFFFFFFF) - 0xa000;
            lim = *(int*)(c + 0x320);
            if (*(int*)(c + 0x60) <= lim) {
                *(int*)(c + 0x60) = lim;
                *(unsigned char*)(c + 0x327) = 0;
                *(unsigned short*)(c + 0x324) = 0;
            }
        } else {
            *(unsigned short*)(((int)c + 0x324) & 0xFFFFFFFFFFFFFFFF) =
                *(unsigned short*)(((int)c + 0x324) & 0xFFFFFFFFFFFFFFFF) + 1;
        }
        break;
    }
    _ZN8Platform21UpdateModelPosAndRotYEv(c);
    if (_ZN8Platform13IsClsnInRangeE5Fix12IiES1_(c, 0x1f4000, 0))
        _ZN8Platform19UpdateClsnPosAndRotEv(c);
    *(unsigned char*)(c + 0x326) = 0;
    return 1;
}
