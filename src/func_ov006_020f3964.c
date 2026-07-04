void func_ov006_020f3964(char* c)
{
    if (*(unsigned char*)(c + 0x5000 + 0x310) == 0)
        return;

    {
        unsigned short* e = (unsigned short*)(((long long)(int)(c + 0x530c)) & 0xFFFFFFFFFFFFFFFFLL);
        *e = *e + 1;
        if (*e < 0x14)
            return;
        *e = 0;
    }
    {
        unsigned char* p = (unsigned char*)(((long long)(int)(c + 0x5311)) & 0xFFFFFFFFFFFFFFFFLL);
        *p = *p + 1;
        *p = *p & 1;
    }
}
