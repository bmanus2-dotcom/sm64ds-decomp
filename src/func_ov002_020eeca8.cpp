//cpp
extern "C" int func_02035638(unsigned char *p);
extern "C" int func_0203567c(int p);
struct ClsnResult { int GetClsnID() const; };
extern "C" int _ZNK10ClsnResult9GetClsnIDEv(ClsnResult *self);

struct Actor {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(int a); // +0x70
};
extern "C" Actor *_ZN5Actor10FindWithIDEj(unsigned int id);

extern "C" int func_ov002_020eeca8(unsigned char *self, int arg) {
    if (func_02035638(self) != 0) {
        ClsnResult *cr = (ClsnResult *)func_0203567c((int)self);
        if (_ZNK10ClsnResult9GetClsnIDEv(cr) != -1) {
            int id = _ZNK10ClsnResult9GetClsnIDEv(cr);
            Actor *a = _ZN5Actor10FindWithIDEj((unsigned int)id);
            if (a != 0) {
                a->v28(arg);
                return 1;
            }
        }
    }
    return 0;
}
