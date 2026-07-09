extern void func_ov002_020e9590(char *self);
extern void func_02043824(char *c);
extern void func_02012694(unsigned int id, void *v);
extern void func_ov002_020e9448(unsigned char *p);
extern void *func_02010f3c(unsigned int id);
extern int func_0203cf40(char *a, char *b);
extern void func_ov002_020e947c(char *a0, char *a1, int a2);
extern int func_ov002_020e8dd8(unsigned char *self);
extern void func_ov002_020e7e24(char *c);
extern void func_ov002_020e7d08(char *c);
extern signed char data_0209f2f8;
extern int data_0209b454;

void func_ov002_020ea9d0(char *c)
{
    char *found;
    int pos[3];
    signed char course;

    if (*(unsigned char *)(c + 0x49d) != 0) {
        func_ov002_020e9590(c);
        if (*(int *)(c + 0x434) != 0) {
            return;
        }
        func_02043824(c);
        return;
    }

    *(int *)(c + 0xb0) |= 0x4000000;
    data_0209b454 |= 0x4000000;
    *(short *)(c + 0x496) = 0;
    func_02012694(0x57, c + 0x74);
    *(int *)(c + 0xa8) = 0x20000;
    func_ov002_020e9448((unsigned char *)c);

    found = (char *)func_02010f3c(*(unsigned int *)(c + 0x434));
    if (*(int *)(c + 0x43c) == 4) {
        if (found == 0 || func_0203cf40(c + 0x5c, found + 0x5c) == 0) {
            *(int *)(c + 0xa8) = 0x18000;
            *(int *)(c + 0x440) = 3;
        } else {
            *(int *)(c + 0x440) = 2;
            pos[0] = *(int *)(found + 0x5c);
            pos[1] = *(int *)(found + 0x60) + 0xc8000;
            pos[2] = *(int *)(found + 0x64);
            course = data_0209f2f8;
            if (course == 0x11) {
                func_ov002_020e947c(c, (char *)pos, 0x64000);
            } else if (course == 0xb && *(unsigned char *)(c + 0x49d) == 3) {
                func_ov002_020e947c(c, (char *)pos, 0x46000);
            } else {
                func_ov002_020e947c(c, (char *)pos, 0x190000);
            }
        }
    } else {
        *(int *)(c + 0x440) = 1;
    }

    func_ov002_020e8dd8((unsigned char *)c);
    func_ov002_020e7e24(c);
    func_ov002_020e7d08(c);
}