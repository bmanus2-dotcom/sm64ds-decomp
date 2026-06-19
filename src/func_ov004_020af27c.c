extern void func_02012e78(void);

void func_ov004_020af27c(void *c)
{
    if (*(int*)((char*)c+0x4630) != 0) return;
    func_02012e78();
    *(short*)((char*)c+0x4634) = -0x80;
    *(short*)((char*)c+0x4636) = 0x30;
    *(short*)((char*)c+0x4638) = 0x180;
    *(short*)((char*)c+0x463a) = 0x60;
    *(short*)((char*)c+0x463c) = 0x80;
    *(short*)((char*)c+0x463e) = 0xe0;
    *(unsigned char*)((char*)c+0xc3) = 0;
    *(int*)((char*)c+0x4628) = 1;
    *(short*)((char*)c+0x4646) = -1;
    *(int*)((char*)c+0x4640) = 0;
}
