int func_ov102_0214d020(char *c)
{
    *(int *)(((int)c + 0x128) & 0xFFFFFFFFFFFFFFFF) |= 2;
    *(int *)(((int)c + 0x128) & 0xFFFFFFFFFFFFFFFF) &= ~4;
    return 1;
}
