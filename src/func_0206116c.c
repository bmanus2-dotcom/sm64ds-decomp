typedef unsigned short u16;

void func_0206116c(void)
{
    u16 *p = (u16*)0x027fff96;
    if (*p & 1)
        *p &= ~1;
}
