typedef short s16;

typedef struct Vector3_16f { s16 x, y, z; } Vector3_16f;
typedef struct Vector3 { int x, y, z; } Vector3;

extern void func_ov002_020bf800(char *c, Vector3_16f v);
extern int func_ov002_020e0478(void *c);
extern unsigned int _ZN5Sound8PlayLongEjjjRK7Vector3j(unsigned int a, unsigned int b, unsigned int c, Vector3 const *v, unsigned int d);
extern int _ZN6Player7IsStateERNS_5StateE(void *c, void *s);
extern void _ZN6Player11ChangeStateERNS_5StateE(void *c, void *s);
extern char data_ov002_02110274[];
extern char data_ov002_021102d4[];
extern char data_ov002_02110244[];

int func_ov002_020dec70(char *self)
{
    int h;
    Vector3_16f v;

    h = *(int *)(self + 0x60);
    if (h + 0x514000 < (int)0xfdecc000)
        return 0;
    v.x = 0;
    v.y = 0x1000;
    v.z = 0;
    func_ov002_020bf800(self, v);
    *(unsigned int *)(self + 0x624) = _ZN5Sound8PlayLongEjjjRK7Vector3j(*(unsigned int *)(self + 0x624), 3, 0x90, (Vector3 *)(self + 0x74), 0);
    if (_ZN6Player7IsStateERNS_5StateE(self, data_ov002_02110274) != 0)
        return 0;
    if (_ZN6Player7IsStateERNS_5StateE(self, data_ov002_021102d4) != 0)
        return 0;
    if (_ZN6Player7IsStateERNS_5StateE(self, data_ov002_02110244) != 0)
        return 0;
    if (self[0x6f9] != 0)
        return 0;
    if (self[0x703] != 0)
        return 0;
    if (self[0x709] != 0)
        return 0;
    if (self[0x6de] == 0)
        return 0;
    if (func_ov002_020e0478(self) != 0)
        goto bump;
    if (self[0x6fd] == 0) {
        _ZN6Player11ChangeStateERNS_5StateE(self, data_ov002_02110274);
        return 1;
    }
bump:
    if (h + 0x514000 < 0x898000)
        *(int *)(self + 0x60) += 0x8000;
    return 0;
}