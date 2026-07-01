extern void _ZN5Scene22ResetHardwareRegistersEv(void);
extern void func_0205583c(void);
extern void _ZN2GX15SetGraphicsModeEiii(int a, int b, int c);
extern void Initialise3dGraphics(int arg);

void _ZN5Scene20Initialise3dGraphicsEv(void)
{
    _ZN5Scene22ResetHardwareRegistersEv();
    func_0205583c();
    _ZN2GX15SetGraphicsModeEiii(1, 0, 1);
    *(volatile unsigned int*)0x40004c8 = 0x296a5800;
    *(volatile unsigned int*)0x40004cc = 0x7fff;
    *(volatile unsigned int*)0x40004c0 = 0x7fff;
    *(volatile unsigned int*)0x40004c4 = 0;
    Initialise3dGraphics(0);
}
