extern void func_ov004_020af094(void* a);

void func_ov006_0210aa3c(void* a)
{
    *(volatile unsigned short*)0x400000A = (*(volatile unsigned short*)0x400000A & 0x43) | 0x1000;
    func_ov004_020af094(a);
}
