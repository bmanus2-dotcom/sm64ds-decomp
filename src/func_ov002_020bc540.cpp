//cpp
struct SharedFilePtr {};
struct BMD_File {};
struct BCA_File {};
struct Model {
    static BMD_File *LoadFile(SharedFilePtr &f);
};
struct Animation {
    static BCA_File *LoadFile(SharedFilePtr &f);
};
struct ModelBase {
    void SetFile(BMD_File *f, int a, int b);
};
struct ModelAnim {
    void SetAnim(BCA_File *f, int a, int b, unsigned int c);
};

extern SharedFilePtr data_ov002_0210e0dc;
extern SharedFilePtr data_ov002_0210e0d4;
extern "C" void func_ov002_020bc488(char *t);

extern "C" int func_ov002_020bc540(char *self) {
    BMD_File *m = Model::LoadFile(data_ov002_0210e0dc);
    ((ModelBase *)(self + 0xd4))->SetFile(m, 1, -1);
    BCA_File *a = Animation::LoadFile(data_ov002_0210e0d4);
    ((ModelAnim *)(self + 0xd4))->SetAnim(a, 0, 0x1000, 0);
    func_ov002_020bc488(self);
    return 1;
}
