typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_0205d23c(void *p, int a);
extern u32 _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(u32);
extern void func_020580f0(int a);
extern int func_0205d5e8(char *self, int a1, int a2, int a3, int a4);
extern int func_0205d3d4(int *o, int a1, unsigned int len);
extern int func_0205d4cc(char *);
extern void func_02041d28(char *, void *);
extern void func_02041a94(char *, char *);

extern int data_02099e6c;
extern char data_020a1fc0[];
extern char data_020a2400[];

void func_02042254(void)
{
    u32 irq;
    char *sb;
    char *mgr;
    char *fp;
    int sp4;
    int sp8;
    int spc;
    int sp10;
    int r6;
    int r4;
    int sl;
    int r8;
    char *r7;
    char *src;

    sp4 = (int)func_0205d23c(&data_02099e6c, 3);
    sp8 = 2;
    spc = 3;
    sp10 = 1;
    fp = data_020a1fc0;
    r6 = 0;
    r4 = 0x400;
    mgr = data_020a2400 + 0x2000;
    while (1) {
        irq = _ZN3IRQ7DisableEv();
        sb = *(char **)(mgr + 0x708);
        if (sb == 0) {
            if (*(int *)(fp + 0xc) == 0) {
                _ZN3IRQ7RestoreEj(irq);
                return;
            }
            func_020580f0(r6);
            sb = *(char **)(mgr + 0x708);
            if (sb == 0)
                continue;
        }
        _ZN3IRQ7RestoreEj(irq);
        if (*(int *)(sb + 0x7c) != 1) {
            func_0205d4cc(sb + 0x38);
            irq = _ZN3IRQ7DisableEv();
            func_02041a94(data_020a2400, sb);
            _ZN3IRQ7RestoreEj(irq);
            continue;
        }
        func_0205d5e8(sb + 0x38, sp4, *(int *)(sb + 0x88),
                      *(int *)(sb + 0x8c) + *(int *)(sb + 0x90), *(int *)(sb + 0x88));
        sl = 0;
        r8 = 0;
        r7 = sb + 0xc0;
        src = sb + 0x38;
        while (sl < 3) {
            *(int *)(sb + sl * 4 + 0xa0) = r8;
            func_0205d3d4((int *)src, (int)r7, r4);
            sl++;
            r8 += 0x400;
            r7 += 0x400;
        }
        *(int *)(sb + 0x94) = r6;
        *(int *)(sb + 0x9c) = sp8;
        *(int *)(sb + 0x98) = spc;
        irq = _ZN3IRQ7DisableEv();
        func_02041d28(data_020a2400, sb);
        _ZN3IRQ7RestoreEj(irq);
    }
}