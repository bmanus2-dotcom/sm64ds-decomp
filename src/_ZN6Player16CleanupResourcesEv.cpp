//cpp
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;

enum { false_, true_ };

struct VB { virtual void v0(); virtual void v1(); };

#pragma opt_common_subs off
#pragma opt_strength_reduction off

extern "C" {
void func_ov002_020bdd2c(char *c);
void func_ov002_020bdef0(char *c);
void func_ov002_020bdd9c(char *c);
void func_ov002_020e032c(char *c);
void func_0203cbc0(int p);
void func_020072c0(void);
void func_02073244(int p, int a, int b, void (*f)(void));
void _ZN13SharedFilePtr7ReleaseEv(void *p);
void func_ov002_020bebd4(char *c);
void UnloadSilverStarAndNumber(void);
void UnloadKeyModels(int n);
extern void *data_ov002_020ff480[];
extern u8 data_0209f2d8;
extern char data_ov002_0210d9a0[];
extern char data_ov002_0210d9a8[];
extern char data_ov002_0210d9c0[];
extern char data_ov002_0210da38[];
extern char data_ov002_0210da40[];
extern char data_ov002_0210e1c8[];
extern char data_ov002_0210e1d0[];
extern char data_ov002_0210e1e0[];
extern char data_ov002_0210e1e8[];
extern char data_ov002_0210e230[];
extern char data_ov002_0210e250[];
extern char data_ov002_0210e270[];
extern char data_ov002_0210e288[];
extern char data_ov002_0210e2f0[];
extern char data_ov002_0210e3b0[];
extern char data_ov002_0210e3c8[];
extern char data_ov002_0210e3d8[];
extern char data_ov002_0210e3e0[];
extern char data_ov002_0210e3e8[];
extern char data_ov002_0210e400[];
extern char data_ov002_0210e408[];
extern char data_ov002_0210e430[];
extern char data_ov002_0210e438[];
extern char data_ov002_0210e450[];
extern char data_ov002_0210e458[];
extern char data_ov002_0210e460[];
extern char data_ov002_0210e478[];
extern char data_ov002_0210e4b8[];
extern char data_ov002_0210e4c0[];
extern char data_ov002_0210e4d0[];
extern char data_ov002_0210e4e8[];
extern char data_ov002_0210e4f0[];
extern char data_ov002_0210e500[];
extern char data_ov002_0210e538[];
extern char data_ov002_0210e540[];
extern char data_ov002_0210e588[];
extern char data_ov002_0210e600[];
extern char data_ov002_0210e620[];
extern char data_ov002_0210e640[];
extern char data_ov002_0210e660[];
extern char data_ov002_0210e670[];
extern char data_ov002_0210e680[];
extern char data_ov002_0210e690[];
extern char data_ov002_0210e6a0[];
extern char data_ov002_0210e6b8[];
extern char data_ov002_0210e6c0[];
extern char data_ov002_0210e6e0[];
extern char data_ov002_0210e6f8[];
extern char data_ov002_0210e708[];
extern char data_ov002_0210e728[];
extern char data_ov002_0210e738[];
extern char data_ov002_0210e750[];
extern char data_ov002_0210e758[];
extern char data_ov002_0210e770[];
extern char data_ov002_0210e780[];
extern char data_ov002_0210e788[];
extern char data_ov002_0210e790[];
extern char data_ov002_0210e798[];
extern char data_ov002_0210e7a8[];
extern char data_ov002_0210e7b0[];
extern char data_ov002_0210e7e8[];
extern char data_ov002_0210e7f0[];
extern char data_ov002_0210e800[];
extern char data_ov002_0210e818[];
extern char data_ov002_0210e898[];
extern char data_ov002_0210e8d0[];
extern char data_ov002_0210e8e8[];
extern char data_ov002_0210e910[];
extern char data_ov002_0210e958[];
extern char data_ov002_0210e9d0[];
extern char data_ov002_0210e9e8[];
extern char data_ov002_0210ea10[];
extern char data_ov002_0210ea30[];
extern char data_ov002_0210ea70[];
extern char data_ov002_0210ea88[];
extern char data_ov002_0210eac8[];
extern char data_ov002_0210eaf0[];
extern char data_ov002_0210eb00[];
extern char data_ov002_0210eb10[];
extern char data_ov002_0210eb20[];
extern char data_ov002_0210eb38[];
extern char data_ov002_0210eb58[];
extern char data_ov002_0210eb70[];
extern char data_ov002_0210eb88[];
extern char data_ov002_0210eb90[];
extern char data_ov002_0210eb98[];
extern char data_ov002_0210eba8[];
extern char data_ov002_0210ebb8[];
extern char data_ov002_0210ebc8[];
extern char data_ov002_0210ebd8[];
extern char data_ov002_0210ec00[];
extern char data_ov002_0210ec10[];
extern char data_ov002_0210ec38[];
extern char data_ov002_0210ec40[];
extern char data_ov002_0210ec50[];
extern char data_ov002_0210ec60[];
extern char data_ov002_0210ec98[];
extern char data_ov002_0210eca8[];
extern char data_ov002_0210ecb8[];
extern char data_ov002_02110aa4[];
}

extern "C" int _ZN6Player16CleanupResourcesEv(char *c)
{
    int i;
    u32 b;

    func_ov002_020bdd2c(c);
    func_ov002_020bdef0(c);
    func_ov002_020bdd9c(c);
    func_ov002_020e032c(c);
    for (i = 0; i < 4; i++) {
        int j;
        VB *p = *(VB **)(c + i * 4 + 0xdc);
        if (p != 0) {
            if (p != 0)
                p->v1();
        }
        p = *(VB **)(c + i * 4 + 0x154);
        if (p != 0) {
            if (p != 0)
                p->v1();
        }
        j = i + 4;
        p = *(VB **)(c + j * 4 + 0x154);
        if (p != 0) {
            if (p != 0)
                p->v1();
        }
        {
            int q = *(int *)(c + i * 4 + 0x27c);
            if (q != 0)
                func_0203cbc0(q);
            q = *(int *)(c + i * 4 + 0x28c);
            if (q != 0)
                func_0203cbc0(q);
            q = *(int *)(c + j * 4 + 0x28c);
            if (q != 0)
                func_0203cbc0(q);
        }
    }
    {
        VB *p = *(VB **)(c + 0xec);
        if (p != 0) {
            if (p != 0)
                p->v1();
        }
        p = *(VB **)(c + 0x1d8);
        if (p != 0) {
            if (p != 0)
                p->v1();
        }
    }
    {
        int q = *(int *)(c + 0x578);
        if (q != 0)
            func_02073244(q, 0xc, 8, func_020072c0);
        q = *(int *)(c + 0x57c);
        if (q != 0)
            func_0203cbc0(q);
        q = *(int *)(c + 0x588);
        if (q != 0)
            func_0203cbc0(q);
    }
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_020ff480[*(int *)(c + 0x63c) + (*(int *)(c + 8) & 3)]);
    b = data_0209f2d8;
    b = b == 1;
    if (b != false_)
        func_ov002_020bebd4(c);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ec50);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ebb8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ec60);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e818);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e690);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb20);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e758);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ec38);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb00);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e790);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e7a8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e7f0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e798);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e4f0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e3d8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb88);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e6c0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb98);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e4c0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e500);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e1c8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e770);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e230);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e288);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e478);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e9d0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ea10);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e538);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eac8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e898);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e9e8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eba8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb70);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eaf0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e640);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e670);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e680);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e438);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e3b0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e3c8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e408);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e400);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ecb8);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e8d0);
    _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ebd8);
    b = data_0209f2d8;
    b = b == 1;
    if (b == false_) {
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210d9a8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_02110aa4);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210da38);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e750);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e588);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e7e8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e450);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e788);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e1e8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e1e0);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e4d0);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e4e8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e1d0);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e800);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e4b8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e270);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e458);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ea70);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e540);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e8e8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eca8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ec98);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e600);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ea88);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e910);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e460);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e2f0);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e958);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb38);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e660);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ea30);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e3e8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb90);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e6b8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e620);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e6a0);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb58);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e3e0);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210eb10);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e708);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ebc8);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e6e0);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e430);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ec40);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e738);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e250);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ec10);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210ec00);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e728);
    }
    if (*(u8 *)(c + 0x718) & 1)
        UnloadSilverStarAndNumber();
    if (*(u8 *)(c + 0x718) & 2)
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210da40);
    if (*(u8 *)(c + 0x718) & 4)
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210d9a0);
    if (*(u8 *)(c + 0x718) & 8)
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210d9c0);
    if (*(u8 *)(c + 0x718) & 0x10)
        UnloadKeyModels(*(s8 *)(c + 0x719));
    b = data_0209f2d8;
    b = b == 1;
    if (b == false_) {
        if (*(u8 *)(c + 0x718) & 0x20) {
            _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e6f8);
            _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e7b0);
            _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e780);
        }
    } else {
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_0210e7b0);
    }
    if (*(u8 *)(c + 0x718) & 0x40) {
        u32 idx = *(u8 *)(c + 0x6dd);
        if (idx == (u32)*(int *)(c + 8))
            idx = *(u8 *)(c + 0x6dc);
        _ZN13SharedFilePtr7ReleaseEv(data_ov002_020ff480[*(int *)(c + 0x63c) + idx]);
    }
    return 1;
}
