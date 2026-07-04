//cpp
// NONMATCHING: different op / idiom (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct BCA_File;

extern "C" {

extern int data_ov078_02126ee0;
extern int data_ov078_0212708c;

int func_ov078_02125c48(void* c, void* p);
int Vec3_Dist(const void* a, const void* b);
void BlendModelAnim_SetAnim(void* self, BCA_File& f, int a, int b, int fix, unsigned short d);
void Player_DropActor(void* p);

struct Vec3 { int x, y, z; };

int func_ov078_02124f28(unsigned char* c)
{
    if (c[0x499] == 0) {
        int b = (int)((*(int*)(c + 0xb0) & 0x4000) != 0);
        if (b != 0) {
            BlendModelAnim_SetAnim(
                c + 0x2cc,
                *(BCA_File*)*(void**)((unsigned char*)&data_ov078_02126ee0 + 4),
                0, 0, 0x1000, 0);
            c[0x499] = 1;
        }
    }

    {
        unsigned char* obj = *(unsigned char**)(c + 0x494);
        if (obj == 0) {
            func_ov078_02125c48(c, &data_ov078_0212708c);
            return 1;
        }
        Vec3 copy = *(Vec3*)(obj + 0x5c);
        if (Vec3_Dist(c + 0x4d4, &copy) <= 0x640000) {
            if ((int)(*(int*)(c + 0x4d8) - 0xa000) > copy.y) {
                Player_DropActor(*(void**)(c + 0x494));
                *(int*)(c + 0x494) = 0;
                func_ov078_02125c48(c, &data_ov078_0212708c);
                return 1;
            }
        }
    }

    {
        int flags = *(int*)(c + 0xb0);
        int b0 = (int)((flags & 0x400) != 0);
        if (b0 == 0) {
            int b1 = (int)((flags & 0x2000) != 0);
            if (b1 == 0) {
                int b2 = (int)((flags & 0x100) != 0);
                if (b2 != 0) {
                    goto done;
                }
            }
        }
        int* p354 = (int*)(c + 0x354);
        if (b0 != 0) {
            *(short*)(c + 0x94) = *(short*)(*(unsigned char**)(c + 0x494) + 0x8e);
        }
        {
            short t = *(short*)(c + 0x94);
            *(short*)(c + 0x8e) = t;
        }
        *p354 = *p354 & ~2;
        func_ov078_02125c48(c, &data_ov078_0212708c);
        if (*(int*)(c + 0x494) != 0) {
            if (*(int*)(*(unsigned char**)(c + 0x494) + 8) == 2) {
                *(int*)(c + 0xa8) = 0x32000;
                *(int*)(c + 0x98) = 0x1e000;
            }
        }
        *(int*)(c + 0x494) = 0;
    }
done:
    return 1;
}

}
