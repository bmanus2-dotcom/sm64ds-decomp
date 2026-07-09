//cpp
typedef unsigned int u32;
typedef unsigned char u8;

struct Vec3 { int x, y, z; };
struct StateFn { u32 fn; int off; };

extern "C" {
extern void func_ov002_020e700c(char *c);
extern int _ZN5Enemy14UpdateYoshiEatER12WithMeshClsn(char *c, char *clsn);
extern void func_ov002_020d718c(void);
extern void func_ov002_020e84ec(char *c);
extern void _ZN12CylinderClsn5ClearEv(char *c);
extern void func_ov002_020e763c(char *c, int a);
extern void _ZN5Actor9UpdatePosEP12CylinderClsn(char *c, void *cc);
extern void _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(char *c, Vec3 *v);
extern void _ZN12CylinderClsn6UpdateEv(char *c);
extern void func_ov002_020e7eb8(char *c);

extern u32 data_0209b454;
extern StateFn data_ov002_021109d8[];
extern Vec3 data_ov002_0210aa0c;

int func_ov002_020eb05c(char *c)
{
    int st;
    u32 flags;
    char *held;
    StateFn *tbl;
    void (*fn)(char *);
    void *vt;
    Vec3 sp;

    func_ov002_020e700c(c);
    *(int *)(c + 0x4a8) = 0;
    *(int *)(c + 0x4ac) = 0;
    *(int *)(c + 0x4b0) = 0;

    if (_ZN5Enemy14UpdateYoshiEatER12WithMeshClsn(c, c + 0x150) != 0) {
        st = *(int *)(c + 0x440);
        if (st >= 5 && st <= 7 && *(void **)(c + 0xd0) != 0) {
            func_ov002_020d718c();
            *(void **)(c + 0xd0) = 0;
            flags = *(u32 *)(c + 0xb0);
            *(u32 *)(c + 0xb0) = flags & ~0xe0000;
            func_ov002_020e84ec(c);
            _ZN12CylinderClsn5ClearEv(c + 0x110);
            return 1;
        }

        if ((data_0209b454 & 0x4000000) != 0 && (*(u32 *)(c + 0xb0) & 0x4000000) != 0) {
            held = *(char **)(c + 0xd0);
            if (held != 0)
                *(u32 *)(held + 0xb0) |= 0x4000000;
        }

        func_ov002_020e84ec(c);
        _ZN12CylinderClsn5ClearEv(c + 0x110);
        return 1;
    }

    *(void **)(c + 0xd0) = 0;
    func_ov002_020e763c(c, 0);

    st = *(int *)(c + 0x440);
    tbl = &data_ov002_021109d8[st];
    if (tbl->off & 1) {
        vt = *(void **)((char *)c + (tbl->off >> 1));
        fn = *(void (**)(char *))((char *)vt + tbl->fn);
    } else {
        fn = (void (*)(char *))tbl->fn;
    }
    fn(c);

    _ZN5Actor9UpdatePosEP12CylinderClsn(c, 0);
    func_ov002_020e84ec(c);
    _ZN12CylinderClsn5ClearEv(c + 0x110);

    sp = data_ov002_0210aa0c;
    _ZN25MovingCylinderClsnWithPos21SetPosRelativeToActorERK7Vector3(c + 0x110, &sp);
    if (*(u8 *)(c + 0x49f) == 0)
        _ZN12CylinderClsn6UpdateEv(c + 0x110);
    func_ov002_020e7eb8(c);
    return 1;
}
}