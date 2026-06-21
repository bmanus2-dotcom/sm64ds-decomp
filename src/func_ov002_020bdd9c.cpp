//cpp
struct ModelAnim2 {
    void Copy(const ModelAnim2 &, char *, unsigned int);
};
struct Player {
    unsigned int GetBodyModelID(unsigned int, bool) const;
};
extern "C" {
extern void *data_ov002_020ff480[];
extern void func_ov002_020bd984(void *self, unsigned int arg);

void func_ov002_020bdd9c(void *self)
{
    char *s = (char *)self;
    if (*(unsigned char *)(s + 0x6f9) != 1)
        return;
    *(unsigned char *)(s + 0x6f9) = 0;
    unsigned int r5 = *(unsigned int *)(s + 8);
    unsigned int id = ((Player *)self)->GetBodyModelID(r5 & 0xff, false);
    void *tbl = data_ov002_020ff480[*(unsigned int *)(s + 0x63c) + r5];
    ModelAnim2 *dst = *(ModelAnim2 **)(s + 0xdc + (id << 2));
    dst->Copy(*(const ModelAnim2 *)(*(char **)(s + 0xec)),
              *(char **)((char *)tbl + 4), 0);
    func_ov002_020bd984(self, 0x34);
}
}
