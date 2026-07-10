typedef struct Vector3 { int x, y, z; } Vector3;
typedef struct Vector3_16 { short x, y, z; } Vector3_16;

extern unsigned short DecIfAbove0_Short(unsigned short *p);
extern void _ZN9ActorBase18MarkForDestructionEv(void *self);
extern void *_ZN5Actor13ClosestPlayerEv(void *self);
extern int _ZN6Player17SetNoControlStateEhih(void *self, unsigned char a, int b, unsigned char d);
extern void _ZN6Player18SetNewHatCharacterEjjb(void *self, unsigned int a, unsigned int b, int c);
extern void func_02013a88(void);
extern void _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void *m, void *f, int a, int fix, unsigned int j);
extern int _ZN9Animation8FinishedEv(void *self);
extern int _ZN6Player12Unk_020c9e5cEh(void *self, unsigned char a);
extern int _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int a, unsigned int b, Vector3 *v, Vector3_16 *v16, int c, int d);

extern int data_ov002_0210de38;
extern int data_ov002_0210de30;

int func_ov002_020b74d0(char *c) {
    short *p;
    int *q;
    if (DecIfAbove0_Short((unsigned short*)(c + 0x100)) == 0) {
        _ZN9ActorBase18MarkForDestructionEv(c);
        return 1;
    }

    if (*(void**)(c + 0x3c0) == 0) {
        *(void**)(c + 0x3c0) = _ZN5Actor13ClosestPlayerEv(c);
        return 1;
    }

    *(int*)(c + 0xc8) = 0;
    p = (short*)(((long long)((char*)*(void**)(c + 0x3c0) + 0x8c)) & 0xFFFFFFFFFFFFFFFFLL);
    *(short*)(c + 0x92) = p[0];
    *(short*)(c + 0x94) = p[1];
    *(short*)(c + 0x96) = p[2];
    *(short*)(c + 0x8c) = *(short*)(c + 0x92);
    *(short*)(c + 0x8e) = *(short*)(c + 0x94);
    *(short*)(c + 0x90) = *(short*)(c + 0x96);

    q = (int*)(((long long)((char*)*(void**)(c + 0x3c0) + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
    *(int*)(c + 0x5c) = q[0];
    *(int*)(c + 0x60) = q[1];
    *(int*)(c + 0x64) = q[2];

    switch (*(unsigned char*)(c + 0x401)) {
    case 1:
        if (_ZN6Player17SetNoControlStateEhih(*(void**)(c + 0x3c0), 0xf, -1, 0) == 1) {
            _ZN6Player18SetNewHatCharacterEjjb(*(void**)(c + 0x3c0), *(unsigned int*)(c + 0x3f4) & 0xff, 0, 0);
            func_02013a88();
            _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c + 0x300, (void *)((int *)&data_ov002_0210de38)[1], 0x40000000, 0x1000, 0);
            *(unsigned char*)(c + 0x401) = 2;
        }
        break;
    case 2:
        if (_ZN9Animation8FinishedEv(c + 0x350) != 0) {
            _ZN9ActorBase18MarkForDestructionEv(c);
        }
        break;
    default:
        break;
    }
    if (*(unsigned char*)(c + 0x401) != 0) return 1;

    if (*(unsigned char*)(c + 0x3fe) == 0) {
        if (_ZN6Player12Unk_020c9e5cEh(*(void**)(c + 0x3c0), 8) == 1) {
            _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(c + 0x300, (void *)((int *)&data_ov002_0210de30)[1], 0x40000000, 0x1000, 0);
            *(unsigned char*)(c + 0x3fe) = 1;
        }
    }

    if (*(unsigned char*)(c + 0x3fe) == 1 && _ZN9Animation8FinishedEv(c + 0x350) != 0) {
        if (*(int*)(c + 0x3f0) == 4) {
            _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0x10d, *(unsigned int*)(c + 8),
                (Vector3*)(c + 0x3c4), (Vector3_16*)0, *(signed char*)(c + 0xcc), -1);
        }
        _ZN9ActorBase18MarkForDestructionEv(c);
    }

    return 1;
}
