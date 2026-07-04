// NONMATCHING: different op / idiom (div=25). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020f120c(char *base, int idx)
{
    int i;
    char *p = base;
    for (i = 0; i < 0x10; i++, p += 0x14) {
        if (*(unsigned char *)(p + 0x4670) != 0) continue;
        *(unsigned char *)(base + i * 0x14 + 0x4670) = 1;
        *(unsigned char *)(base + i * 0x14 + 0x4671) = 1;
        *(short *)(base + i * 0x14 + 0x466c) = 0x10;
        *(int *)(base + i * 0x14 + 0x4660) = *(int *)(base + idx * 4 + 0x47f8);
        *(int *)(base + i * 0x14 + 0x4664) = *(int *)(base + idx * 4 + 0x49d8);
        *(int *)(base + i * 0x14 + 0x4668) = 0x1100;
        *(unsigned char *)(base + i * 0x14 + 0x4672) = 0;
        {
            short *d = (short *)(base + 0x5172);
            *d -= 0xa;
        }
        if (*(short *)(base + 0x5172) < 0)
            *(short *)(base + 0x5172) = 0;
        return;
    }
}
