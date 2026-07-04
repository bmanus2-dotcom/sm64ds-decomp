// NONMATCHING: different op / idiom (div=44). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov063_02119c18(void* c, unsigned int id);
extern char* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int a, unsigned int b, void* pos, void* rot, int e, int f);

void func_ov063_02116bf4(char* c)
{
    *(unsigned short*)(c + 0x5d4) &= ~8;
    *(int*)(c + 0x19c) |= 1;
    func_ov063_02119c18(c, 0x9f);

    switch (*(unsigned char*)(c + 0x5cc)) {
    case 0:
        if (*(int*)(c + 0x580) >= 0x3e8000)
            break;
        if (*(int*)(c + 0x5a0) >= 5) {
            if ((unsigned short)*(unsigned short*)(c + 0x100) > 0x3c)
                *(unsigned char*)(c + 0x5cc) = 0;
            break;
        }
        if (*(unsigned char*)(c + 0x5cb) != 5
            && *(unsigned char*)(c + 0x5cb) - *(int*)(c + 0x5a0) < 2) {
            char* p = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
                0xd1, 0xfff1, c + 0x5c, c + 0x92, *(signed char*)(c + 0x5d0), -1);
            if (p) {
                *(int*)(p + 0x494) = *(int*)(c + 4);
                *(int*)(p + 0x498) = *(int*)(c + 0x498);
            }
        }
        (*(unsigned char*)(c + 0x5cb))++;
        (*(unsigned char*)(c + 0x5cc))++;
        if (*(int*)(c + 0x5a0) >= 5)
            *(unsigned char*)(c + 0x5cc) = 2;
        break;
    case 1:
        break;
    }
}
