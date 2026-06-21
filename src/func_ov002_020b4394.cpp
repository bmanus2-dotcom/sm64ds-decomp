//cpp
struct SharedFilePtr { void Release(); };
extern void UnloadSilverStarAndNumber(void);

extern SharedFilePtr data_ov002_0210d9d8;
extern SharedFilePtr data_ov002_0210da30;
extern SharedFilePtr data_ov002_0210da18;

struct Obj { char pad[0xc]; unsigned short id; };

extern "C" int func_ov002_020b4394(Obj* self)
{
    switch (self->id) {
    default: break;
    case 0x141:
        data_ov002_0210d9d8.Release();
        break;
    case 0x142:
        data_ov002_0210da30.Release();
        break;
    case 0x143:
        data_ov002_0210da18.Release();
        break;
    case 0x144:
        UnloadSilverStarAndNumber();
    }
    return 1;
}
