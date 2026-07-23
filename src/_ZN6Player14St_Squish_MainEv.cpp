//cpp
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;

extern u8 data_ov002_0211117c;
extern char data_ov002_0211013c;
extern char data_ov002_021101b4;

extern "C" {
extern int func_ov002_020c6908(char *c);
extern int func_ov002_020c647c(char *c, int a);
extern int func_ov002_020d91e0(char *c, int a, int b);
extern void func_ov002_020db8bc(char *c, int a);
extern int func_ov002_020c6538(char *c);
extern void KillPlayer(void);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(unsigned int a, unsigned int b, char *v);
extern void _ZN6Player11ChangeStateERNS_5StateE(char *c, char *s);
extern int _ZN6Player9GetHealthEv(char *c);

int _ZN6Player14St_Squish_MainEv(char *c)
{
    switch (*(u8 *)(c + 0x6e3)) {
    case 0:
        if (func_ov002_020c6908(c) != 0)
            return 1;
        {
            int r = func_ov002_020c647c(c, *(int *)(c + 0x688));
            if (r >= 0) {
                *(int *)(c + 0x84) = (r << 12) / 160;
                if (r >= 0x20)
                    break;
                if (*(u8 *)(c + 0x6e6) != 2)
                    break;
                _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(u8 *)(c + 0x6d9), 7, c + 0x74);
                *(int *)(c + 0x84) = 0x100;
                *(u8 *)(c + 0x6e3) = 2;
                *(u8 *)(c + 0x70c) = 1;
                if (*(u8 *)(c + 0x6f9) == 0) {
                    if (func_ov002_020d91e0(c, 0x300, 1) != 0)
                        *(u8 *)(c + 0x70c) = 2;
                }
                {
                    char *a = *(char **)(c + 0x364);
                    if (a != 0) {
                        u16 id = *(u16 *)(a + 0xc);
                        int b1 = (id == 0xa4);
                        int b2;
                        if (b1 || (b2 = (id == 0xa5)) != 0)
                            *(u8 *)(a + 0x407) = 1;
                    }
                }
            } else {
                *(u16 *)(c + 0x6a4) = 0xa;
                (*(u8 *)(int)(((long long)(int)(c + 0x6e3)) & 0xFFFFFFFFFFFFFFFFLL))++;
            }
        }
        break;
    case 1:
        if (*(u16 *)(c + 0x6a4) != 0) {
            (*(int *)(int)(((long long)(int)(c + 0x84)) & 0xFFFFFFFFFFFFFFFFLL)) += 0x100;
            if (*(int *)(c + 0x84) > 0x1000)
                *(int *)(c + 0x84) = 0x1000;
        } else {
            *(int *)(c + 0x84) = 0x1000;
            _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_0211013c);
        }
        break;
    case 2:
        if (func_ov002_020c6908(c) != 0)
            return 1;
        if (func_ov002_020c647c(c, *(int *)(c + 0x688)) < 0) {
            if (*(u8 *)(c + 0x70c) == 1) {
                func_ov002_020db8bc(c, 1);
                _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_0211013c);
            } else {
                (*(u8 *)(int)(((long long)(int)(c + 0x6e3)) & 0xFFFFFFFFFFFFFFFFLL))++;
                *(u8 *)(c + 0x70c) = 0;
            }
        }
        break;
    case 3:
        if (*(u8 *)(c + 0x6e5) == 2 && func_ov002_020c6538(c) == 0) {
            _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_021101b4);
            return 1;
        }
        if (*(u8 *)(c + 0x70c) != 0)
            break;
        if (_ZN6Player9GetHealthEv(c) != 0) {
            func_ov002_020db8bc(c, 1);
            _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_0211013c);
        }
        if (data_ov002_0211117c != 0)
            break;
        KillPlayer();
        (*(u8 *)(int)(((long long)(int)(c + 0x70c)) & 0xFFFFFFFFFFFFFFFFLL))++;
        break;
    case 4:
        if (*(u16 *)(c + 0x6a4) != 0)
            break;
        if (*(u8 *)(c + 0x70c) != 1) {
            *(u8 *)(c + 0x6e3) = 3;
            break;
        }
        func_ov002_020db8bc(c, 1);
        _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_0211013c);
        break;
    }
    return 1;
}
}
