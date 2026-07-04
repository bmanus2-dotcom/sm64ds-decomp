// NONMATCHING: different op / idiom (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_0204c194(int a, int b)
{
    unsigned short va = (unsigned short)(short)((int)(0x1000 << a << 8) >> 0x10);
    unsigned short vb = (unsigned short)(short)((int)(0x1000 << b << 8) >> 0x10);

    *(volatile int*)0x4000500 = 1;
    *(volatile int*)0x4000488 = 0;
    *(volatile int*)0x4000490 = 0x40003c0;
    *(volatile int*)0x4000488 = va;
    *(volatile int*)0x4000490 = 0x4000040;
    *(volatile int*)0x4000488 = va | (vb << 0x10);
    *(volatile int*)0x4000490 = 0x3c000040;
    *(volatile int*)0x4000488 = vb << 0x10;
    *(volatile int*)0x4000490 = 0x3c0003c0;
    *(volatile int*)0x4000504 = 0;
}
