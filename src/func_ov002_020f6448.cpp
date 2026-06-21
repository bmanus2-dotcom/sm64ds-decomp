//cpp
void *operator new(unsigned long);
extern "C" void func_02022298(void *);
extern "C" void func_ov002_020f5fe4(void);
extern "C" int func_ov002_020f6424(char *o);

struct Obj {
    char pad[0xd8];
    void *fd8;                   /* +0xd8 */
    char pad2[0x100 - 0xdc];
    unsigned char f100;          /* +0x100 */
};

extern "C" int func_ov002_020f6448(Obj *self, unsigned char *src) {
    self->f100 = *src;
    char *m = (char *)operator new(0x518);
    if (m)
        func_02022298(m + 0x200);
    self->fd8 = m;
    if (self->fd8 == 0)
        return 0;
    func_ov002_020f5fe4();
    return func_ov002_020f6424((char *)self);
}
