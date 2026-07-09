extern int func_ov002_020becc8(char *self, unsigned int a, int b);
extern int func_ov002_020bed98(char *self);
extern int _ZNK9Animation12WillHitFrameEi(char *self, int frame);
extern int func_0201392c(unsigned int a);
extern void func_0200d3f8(void *thiz, unsigned char playerID, void *ptr);
extern void func_ov002_020e30a0(char *self, void *st);

extern unsigned char data_0209f2d8;
extern int data_0209caa0;
extern void *data_0209f318;
extern int data_0209b454;
extern void *data_ov002_0211067c;
extern void *data_ov002_0211013c;

int func_ov002_020c92fc(char *self)
{
    int id;
    char *anim;
    int done;
    unsigned int flags;

    done = 0;
    *(int *)(self + 0xa8) = 0;
    if (*(int *)(self + 0x688) != -1) {
        if (*(unsigned char *)(self + 0x706) == 0) {
            id = func_ov002_020becc8(self, *(unsigned int *)(self + 8) & 0xff, 0);
            anim = *(*(char ***)((char *)self + id * 4 + 0xdc)) + 0x50;
            if (_ZNK9Animation12WillHitFrameEi(anim, 0x20) != 0) {
                done = 1;
            }
        } else {
            if (func_ov002_020bed98(self) != 0) {
                done = 1;
            }
        }
    }

    if (done != 0) {
        *(unsigned short *)(self + 0x6a4) = 0x14;
        *(unsigned char *)(self + 0x6e3) = 0x14;
        *(int *)(self + 0xa8) = 0;
        flags = *(unsigned int *)(self + 0xb0);
        *(unsigned int *)(self + 0xb0) = flags | 0x800000;
        data_0209b454 |= 0x800000;
        return 0;
    }

    if (func_ov002_020bed98(self) != 0) {
        if (*(unsigned char *)(self + 0x6e3) == 9) {
            if (data_0209f2d8 != 1) {
                return 0;
            }
            if ((*(int *)(data_0209caa0 + 8) & 0x10000000) != 0) {
                return 0;
            }
            if (func_0201392c(0) != 0) {
                return 0;
            }
            if (*(unsigned char *)(self + 0x6dd) != 0) {
                return 0;
            }
            if (*(unsigned char *)(self + 0x6dc) != 3) {
                return 0;
            }
            *(unsigned char *)(self + 0x6e3) = 0xa;
            *(unsigned char *)(self + 0x6e6) = 0;
            func_0200d3f8(data_0209f318, *(unsigned char *)(self + 0x6d8), 0);
            return 0;
        }
    }

    if (*(unsigned char *)(self + 0x706) != 0) {
        func_ov002_020e30a0(self, data_ov002_0211067c);
    } else {
        func_ov002_020e30a0(self, data_ov002_0211013c);
    }
    return 0;
}