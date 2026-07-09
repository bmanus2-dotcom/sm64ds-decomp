extern unsigned int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int a);
extern void MultiStore_Int(int val, int *dst, int len);
extern void MultiStore16(short val, char *dst, int nbytes);
extern void func_0205a61c(void *dst, void *src, int n);
extern int func_02069038(void);

extern int *data_020a9db8;
extern int data_020a9db4;
extern short data_020a9db0;
extern int **data_0209a084;

int func_02068e4c(int alignBase, short *src, short arg2, short arg3, short arg4, short arg5)
{
    unsigned int irq;
    int r7;
    int r6;
    int i;
    int j;
    short *dst;
    short *ip;
    short **queue;
    short *entry;

    if (data_020a9db8[0] != 0) {
        if (*(short *)(data_020a9db8[0] + 0x1316) != 0) {
            return 2;
        }
    }

    r7 = (alignBase + 0x1f) & ~0x1f;
    r6 = (r7 + 0x371f) & ~0x1f;

    irq = _ZN3IRQ7DisableEv();
    data_020a9db4 = r7;
    data_020a9db0 = arg5;
    data_020a9db8[0] = r6;
    MultiStore_Int(0, (int *)(r7 + 0), 0x3700);

    MultiStore16(0, (char *)r6, 0x1340);

    dst = (short *)(r7 + 0x1e30);
    for (i = 0; i < 0xa; i++) {
        if (src[i + 1] == 0) {
            break;
        }
        *dst++ = src[i + 1];
    }

    ip = (short *)(r7 + 0x1e38);
    queue = (short **)data_0209a084;
    for (j = 0; j < 0x10; j++) {
        entry = *queue;
        if (entry[0] == 0) {
            break;
        }
        *queue = entry + 1;
        *ip++ = entry[0];
    }

    func_0205a61c((void *)(r6 + 0x1300), src, 0x16);

    *(short *)(r7 + 0x1400) = 0x100;
    *(short *)(r7 + 0x1402) = 8;
    *(short *)(r6 + 0x1e18) = 0;
    *(short *)(r6 + 0x1e1a) = 0;
    *(short *)(r6 + 0x1e2c) = 1;
    *(int *)(r7 + 0x1404) = r6;
    *(int *)(r7 + 0x1408) = r6 + 0x400;
    *(short *)(r6 + 0x1314) = 1;
    *(short *)(r6 + 0x1312) = 0;
    *(short *)(r6 + 0x1306) = arg2;
    *(short *)(r6 + 0x1308) = arg3;
    *(short *)(r6 + 0x130a) = arg4;
    *(short *)(r6 + 0x130c) = 1;
    *(short *)(r6 + 0x1310) = 0;
    *(short *)(r6 + 0x1316) = (short)(func_02069038() + 0xc8);
    *(short *)(r6 + 0x130e) = 0xf;
    *(unsigned char *)(r7 + 0x1410) = 0;
    *(unsigned char *)(r7 + 0x1411) = 0;
    *(int *)(r6 + 0x1324) = 0;

    _ZN3IRQ7RestoreEj(irq);
    *(short *)(r6 + 0x1316) = 1;
    return 0;
}