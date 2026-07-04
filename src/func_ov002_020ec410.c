// NONMATCHING: register allocation (div=20). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct Actor;
extern struct Actor* _ZN5Actor10FindWithIDEj(u32 id);
extern u8 IsPlayerWarping(int a0);
extern int _ZN6Player7CanWarpEv(void* p);
extern void WarpPlayer(int i, int val);
extern void _ZN12CylinderClsn5ClearEv(void* p);
extern void _ZN12CylinderClsn6UpdateEv(void* p);

int func_ov002_020ec410(char* c)
{
    u32 id;
    struct Actor* o;

    id = *(u32*)(c + 0xf8);
    if (id != 0) {
        do {
            if (*(s16*)(c + 0x8e) != 0) break;
            o = _ZN5Actor10FindWithIDEj(id);
            if (o == 0) break;
            {
                int b = (int)(*(u16*)((char*)o + 0xc) == 0xbf);
                if (b == 0) break;
            }
            if (IsPlayerWarping(*(u8*)((char*)o + 0x6d8))) {
                *(s16*)(c + 0x8e) = 1;
                break;
            }
            if (_ZN6Player7CanWarpEv(o)) {
                WarpPlayer(*(u8*)((char*)o + 0x6d8), ((*(u32*)(c + 8) >> 0xc) + 1) & 0xff);
            }
        } while (0);
    } else {
        *(s16*)(c + 0x8e) = 0;
        _ZN12CylinderClsn5ClearEv(c + 0xd4);
        _ZN12CylinderClsn6UpdateEv(c + 0xd4);
    }
    return 1;
}
