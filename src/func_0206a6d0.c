typedef unsigned short u16;
typedef unsigned char u8;

extern unsigned int _ZN3IRQ7SetIRQsEj(unsigned int);
extern void func_0206a3a4(void *arg0, int *out);
extern void func_0206a458(int *out);
extern void DMASyncHalfTransfer(unsigned int channel, void *src, void *dst, unsigned int numHalfs);
extern void func_0206a424(int *self);
extern void func_0206a37c(int a, int *p);
extern void MultiCopy_Int(int *dst, int *src, int len);
extern void _ZN4CP1527FlushAndInvalidateDataCacheEv(void);
extern void func_0206a318(void *arg);
extern void WaitByLoop(int n);

extern int data_020a9de4;
extern short data_020a9de0;
extern int data_020a9e00;
extern int data_020a9e04;

void func_0206a6d0(void)
{
    int sp[4];
    unsigned int irq;
    u16 save208;
    int flag;
    int i;
    void *arg;

    if (data_020a9de4 != 0)
        return;
    data_020a9de4 = 1;
    if ((*(volatile u16 *)0x4000300 & 1) == 0)
        return;
    irq = _ZN3IRQ7SetIRQsEj(0x40000);
    save208 = *(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = 1;
    func_0206a3a4((void *)&data_020a9de0 + 2, sp);
    flag = (int)((*(volatile u16 *)0x4000204 & 0x8000) >> 15);
    func_0206a458(sp + 2);
    *(volatile u16 *)0x4000204 &= ~0x8000;
    DMASyncHalfTransfer(0, (void *)((char *)&data_020a9e00 + 0x80), (void *)0x8000080, 0x40);
    *(volatile u16 *)0x4000204 = (*(volatile u16 *)0x4000204 & ~0x8000) | (u16)(flag << 15);
    func_0206a424(sp + 2);
    func_0206a37c(*(short *)((char *)&data_020a9de0 + 2), sp);
    *(volatile u16 *)0x27ffc30 = *(u16 *)((char *)&data_020a9e00 + 0xbe);
    for (i = 0; i < 3; i++)
        *(volatile u8 *)(0x27fffc32 + i) = *(u8 *)((char *)&data_020a9e00 + 0xb5 + i);
    *(volatile u16 *)0x27ffc36 = *(u16 *)((char *)&data_020a9e00 + 0xb0);
    *(volatile unsigned int *)0x27ffc38 = *(unsigned int *)((char *)&data_020a9e00 + 0xac);
    MultiCopy_Int(&data_020a9e04, &data_020a9e00, 0x9c);
    _ZN4CP1527FlushAndInvalidateDataCacheEv();
    arg = (void *)((((unsigned int)&data_020a9e00 + 0xfe000000) >> 5) << 6 | 1);
    func_0206a318(arg);
    if (data_020a9de0 != 1) {
        do {
            WaitByLoop(1);
        } while (data_020a9de0 != 1);
    }
    *(volatile u16 *)0x4000208 = save208;
    _ZN3IRQ7SetIRQsEj(irq);
}