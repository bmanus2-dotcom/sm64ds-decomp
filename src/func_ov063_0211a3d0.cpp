//cpp
struct Vec3 { int x, y, z; };
extern "C" {
extern int _ZNK12WithMeshClsn8IsOnWallEv(void* self);
extern void _ZN5Actor10PoofDustAtERK7Vector3(void* self, const Vec3& v);
extern void _ZN5Actor8PoofDustEv(void* self);
extern void* _ZN5Actor10FindWithIDEj(unsigned int id);
extern void func_ov063_02116244(char* c);
}

extern "C" int func_ov063_0211a3d0(char* c)
{
    if (*(unsigned short*)(c + 0x100) == 0) {
        *(int*)(c + 0x98) = 0x28000;
        *(short*)(c + 0x94) = *(short*)(*(char**)(c + 0x484) + 0x8e);
        *(int*)(c + 0x5a0) = 1;
        {
            unsigned short* f = (unsigned short*)(((long long)(int)(c + 0x5d4)) & 0xFFFFFFFFFFFFFFFFLL);
            *f &= ~4;
        }
    } else {
        if (*(unsigned short*)(c + 0x100) == 5)
            *(unsigned char*)(c + 0x5c9) = 8;
        if (*(unsigned short*)(c + 0x100) > 0x1e || _ZNK12WithMeshClsn8IsOnWallEv(c + 0x1c4) != 0) {
            if (*(unsigned char*)(c + 0x5cf) == 0xf) {
                int x = *(int*)(c + 0x5c);
                volatile int s[3];
                int y;
                Vec3 v;
                s[0] = x;
                s[1] = *(int*)(c + 0x60);
                s[2] = *(int*)(c + 0x64);
                y = s[1];
                if (((unsigned)(*(unsigned short*)(c + 0x5d4) << 23)) >> 31)
                    s[0] = (int)(x * 0xFFFFFFFFu);
                v.x = s[0];
                v.y = y;
                v.z = s[2];
                _ZN5Actor10PoofDustAtERK7Vector3(c, v);
            } else {
                _ZN5Actor8PoofDustEv(c);
            }
            *(int*)(c + 0x5a0) = 2;
            if (*(unsigned char*)(c + 0x5cf) != 0) {
                unsigned int id = *(unsigned int*)(c + 0x490);
                if (id != 0) {
                    *(void**)(c + 0x48c) = _ZN5Actor10FindWithIDEj(id);
                    {
                        char* a = *(char**)(c + 0x48c);
                        if (a != 0) {
                            if (*(unsigned char*)(c + 0x5cf) != 2) {
                                int* p = (int*)(((long long)(int)(a + 0x180)) & 0xFFFFFFFFFFFFFFFFLL);
                                *p = *p + 1;
                            }
                            func_ov063_02116244(*(char**)(c + 0x48c));
                        }
                    }
                    *(void**)(c + 0x48c) = 0;
                }
            }
            return 1;
        }
    }

    *(int*)(c + 0xa8) = 0x5000;
    {
        short* a = (short*)(((long long)(int)(c + 0x90)) & 0xFFFFFFFFFFFFFFFFLL);
        short* b = (short*)(((long long)(int)(c + 0x8e)) & 0xFFFFFFFFFFFFFFFFLL);
        *a = *a + 0x800;
        *b = *b + 0x800;
    }
    return 0;
}
