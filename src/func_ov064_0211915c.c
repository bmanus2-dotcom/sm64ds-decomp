typedef unsigned char u8;

extern int _ZN5Actor13DistToCPlayerEv(void *self);

int func_ov064_0211915c(char *a)
{
    switch (*(u8 *)(a + 0xd5)) {
    case 0:
        if (*(u8 *)(a + 0xd4) == 3) {
            if (_ZN5Actor13DistToCPlayerEv(a) < 0x3e8000) {
                (*(u8 *)(((int)a + 0xd5) & 0xFFFFFFFFFFFFFFFF))++;
            }
        }
        break;
    case 1:
        break;
    }
    return 1;
}
