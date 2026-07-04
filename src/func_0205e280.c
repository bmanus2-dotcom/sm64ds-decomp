// NONMATCHING: different op / idiom (div=33). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_0205e3d4(void* c);

int func_0205e280(char* c)
{
    unsigned char* p;
    if (*(int*)(c + 0x1c) > 0x37)
    {
        p = (unsigned char*)(c + 0x20 + *(int*)(c + 0x1c));
        (*(int*)(c + 0x1c))++;
        *p = 0x80;
        while (*(int*)(c + 0x1c) < 0x40)
        {
            p = (unsigned char*)(c + 0x20 + *(int*)(c + 0x1c));
            (*(int*)(c + 0x1c))++;
            *p = 0;
        }
        func_0205e3d4(c);
        while (*(int*)(c + 0x1c) < 0x38)
        {
            p = (unsigned char*)(c + 0x20 + *(int*)(c + 0x1c));
            (*(int*)(c + 0x1c))++;
            *p = 0;
        }
    }
    else
    {
        p = (unsigned char*)(c + 0x20 + *(int*)(c + 0x1c));
        (*(int*)(c + 0x1c))++;
        *p = 0x80;
        while (*(int*)(c + 0x1c) < 0x38)
        {
            p = (unsigned char*)(c + 0x20 + *(int*)(c + 0x1c));
            (*(int*)(c + 0x1c))++;
            *p = 0;
        }
    }
    *(unsigned char*)(c + 0x58) = *(int*)(c + 0x18) >> 24;
    *(unsigned char*)(c + 0x59) = *(int*)(c + 0x18) >> 16;
    *(unsigned char*)(c + 0x5a) = *(int*)(c + 0x18) >> 8;
    *(unsigned char*)(c + 0x5b) = *(int*)(c + 0x18);
    *(unsigned char*)(c + 0x5c) = *(int*)(c + 0x14) >> 24;
    *(unsigned char*)(c + 0x5d) = *(int*)(c + 0x14) >> 16;
    *(unsigned char*)(c + 0x5e) = *(int*)(c + 0x14) >> 8;
    *(unsigned char*)(c + 0x5f) = *(int*)(c + 0x14);
    func_0205e3d4(c);
    return 0;
}
