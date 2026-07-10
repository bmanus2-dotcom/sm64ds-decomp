extern void func_ov004_020aeed8(void* a);

void func_ov006_0210aa10(void* a)
{
    *(volatile unsigned short*)0x400000A = (*(volatile unsigned short*)0x400000A & 0x43) | 0x1118;
    func_ov004_020aeed8(a);
}
