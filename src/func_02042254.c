extern char data_02099e6c[];
extern char data_020a1fc0[];
extern char data_020a2400[];

extern void *func_0205d23c(void *a, int b);
extern void func_020580f0(int a);
extern int func_0205d5e8(char *self, int a1, int a2, int a3, int a4);
extern void func_0205d3d4(char *a, char *b, int c);
extern void func_02041d28(char *a, void *b, int c);
extern int func_0205d4cc(char *self);
extern void func_02041a94(char *a, void *b);
extern unsigned int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int state);

void func_02042254(void) {
    void *node;
    int two;
    int three;
    int one;
    unsigned int irq;
    char *sb;
    int sl;

    node = func_0205d23c(data_02099e6c, 3);
    two = 2;
    three = 3;
    one = 1;
    irq = _ZN3IRQ7DisableEv();
    sb = *(char **)(data_020a2400 + 0x2000 + 0x708);
    if (sb == 0) {
        do {
            if (*(int *)(data_020a1fc0 + 0xc) == 0) {
                _ZN3IRQ7RestoreEj(irq);
                return;
            }
            func_020580f0(0);
            sb = *(char **)(data_020a2400 + 0x2000 + 0x708);
        } while (sb == 0);
    }
    _ZN3IRQ7RestoreEj(irq);
    if (*(int *)(sb + 0x7c) == 1) {
        func_0205d5e8(sb + 0x38, (int)node, *(int *)(sb + 0x8c),
                      *(int *)(sb + 0x8c) + *(int *)(sb + 0x90), *(int *)(sb + 0x88));
        for (sl = 0; sl < 3; sl++) {
            *(int *)(sb + sl * 4 + 0xa0) = sl * 0x400;
            func_0205d3d4(sb + 0x38, sb + 0xc0 + sl * 0x400, 0x400);
        }
        *(int *)(sb + 0x94) = 0;
        *(int *)(sb + 0x9c) = two;
        *(int *)(sb + 0x98) = three;
        irq = _ZN3IRQ7DisableEv();
        func_02041d28(data_020a2400, sb, one);
        _ZN3IRQ7RestoreEj(irq);
    } else {
        func_0205d4cc(sb + 0x38);
        irq = _ZN3IRQ7DisableEv();
        func_02041a94(data_020a2400, sb);
        _ZN3IRQ7RestoreEj(irq);
    }
}
