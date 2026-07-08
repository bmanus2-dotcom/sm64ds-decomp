//cpp
typedef int Fix12;
struct BCA_File;
struct ModelAnim { void SetAnim(BCA_File *f, int a, Fix12 b, unsigned int c); };
extern void *data_ov062_0211de00[];
extern char data_ov062_0211dec0[];
extern "C" void func_ov062_02116cd8(void *c, void *p);

extern "C" int func_ov062_021164e8(char *c) {
    int t;
    int flags;
    if (*(unsigned char *)(c + 0x3e5) == 0) {
        t = (*(int *)(c + 0xb0) & 0x4000) != 0;
        if (t != false) {
            ((ModelAnim *)(c + 0x300))->SetAnim((BCA_File *)data_ov062_0211de00[1], 0, 0x1000, 0);
        }
    }
    *(unsigned char *)(c + 0x3e5) = 1;
    flags = *(int *)(c + 0xb0);
    t = (flags & 0x400) != 0;
    if (t != false) goto after;
    t = (flags & 0x2000) != 0;
    if (t != false) goto after;
    t = (flags & 0x100) != 0;
    if (t != false) goto after;
    *(short *)(c + 0x94) = *(short *)(*(char **)(c + 0x3f8) + 0x8e);
    *(int *)(((long long)(int)(c + 0x128)) & 0xFFFFFFFFFFFFFFFFLL) |= 2;
    func_ov062_02116cd8(c, data_ov062_0211dec0);
after:
    if (*(int *)(*(char **)(c + 0x3f8) + 8) == 2) {
        *(int *)(c + 0xa8) = 0x50000;
        *(int *)(c + 0x98) = 0x14000;
    }
    *(int *)(c + 0x3f8) = 0;
    return 1;
}
