//cpp
/* Player::St_YoshiPower_Init at 0x020d7ed0 (ov002), size 0x200
 * Matched byte-for-byte with mwccarm 1.2/sp2p3
 * flags: -O4,p -enum int -lang c++ -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc
 */
extern "C" {
extern void _ZN6Player7SetAnimEji5Fix12IiEj(char*, unsigned int, int, int, unsigned int);
extern void _ZN5Sound13PlayCharVoiceEjjRK7Vector3(unsigned int, unsigned int, void*);
extern void func_ov002_020d71a0(char*);
extern void _ZN12CylinderClsn5ClearEv(void*);
extern void func_ov002_020d708c(char*);
extern void func_ov002_020ed63c(void*, int);

int _ZN6Player18St_YoshiPower_InitEv(char* c)
{
    *(unsigned short*)(((int)c + 0x6ce) & 0xFFFFFFFFFFFFFFFFLL) |= 0x200;
    *(unsigned char*)(c+0x6ee) = 0;
    *(unsigned char*)(c+0x704) = 0;
    if (*(unsigned short*)(c+0x6be) != 0) {
        *(unsigned char*)(c+0x6f4) = 2;
    }
    if (*(int*)(c+0x98) >= 0x1c000) {
        *(int*)(c+0x98) = 0x1c000;
    }
    if (**(int**)(c+0x588) == 0) {
        if (*(unsigned char*)(c+0x6f4) != 0) {
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x6d, 0x40000000, 0x1000, 0);
            *(unsigned char*)(c+0x6e3) = 5;
            *(unsigned short*)(c+0x6a4) = 0x1e;
            *(unsigned char*)(((int)c + 0x6f4) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
            _ZN5Sound13PlayCharVoiceEjjRK7Vector3(0, 0x101, c+0x74);
        } else if (*(void**)(c+0x360) == 0) {
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x6c, 0x40000000, 0x1000, 0);
            if (*(unsigned char*)(c+0x714) != 0) {
                func_ov002_020d71a0(c);
            }
            *(unsigned char*)(c+0x6e3) = 0;
            *(unsigned char*)(c+0x70c) = 0;
            _ZN12CylinderClsn5ClearEv(c+0x314);
            func_ov002_020d708c(c);
            _ZN5Sound13PlayCharVoiceEjjRK7Vector3(0, 0xfc, c+0x74);
        } else {
            _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x6d, 0x40000000, 0x1000, 0);
            *(unsigned char*)(c+0x6e3) = 4;
        }
    } else {
        int i;
        _ZN6Player7SetAnimEji5Fix12IiEj(c, 0x30, 0x40000000, 0x1000, 0);
        *(unsigned char*)(c+0x6e3) = 6;
        *(void**)(c+0x358) = **(void***)(c+0x588);
        *(int*)(((int)*(void**)(c+0x358) + 0xb0) & 0xFFFFFFFFFFFFFFFFLL) |= 0x100;
        func_ov002_020ed63c(*(void**)(c+0x358), 1);
        (*(int**)(c+0x588))[0] = 0;
        for (i = 1; i < 5; i++) {
            int* p = *(int**)(c+0x588);
            int v = p[i];
            if (v != 0) {
                (p + i)[-1] = v;
                (*(int**)(c+0x588))[i] = 0;
            }
        }
    }
    return 1;
}
}
