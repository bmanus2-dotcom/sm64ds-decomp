// NONMATCHING: different op / idiom (div=17). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov002_020f34bc(unsigned char *s, int idx)
{
    int k = idx * 0x30;
    int flag;
    int h1, h2;
    *(int *)(s + 0x140 + k) -= 0x1800;
    *(int *)(s + 0x144 + k) -= 0x1800;
    *(int *)(s + 0x148 + k) += 0x1800;
    *(int *)(s + 0x14c + k) += 0x1800;
    flag = 0;
    if (*(int *)(s + 0x140 + k) <= 0x80000) *(int *)(s + 0x140 + k) = 0x80000;
    if (*(int *)(s + 0x144 + k) <= 0x56000) *(int *)(s + 0x144 + k) = 0x56000;
    if (*(int *)(s + 0x148 + k) >= 0xfc000) *(int *)(s + 0x148 + k) = 0xfc000;
    if (*(int *)(s + 0x14c + k) >= 0xbc000) { *(int *)(s + 0x14c + k) = 0xbc000; flag++; }
    if (flag != 0) (*(unsigned char *)(s + 0x15e + k))++;
    h2 = (((*(int *)(s + 0x144 + k) >> 12) << 8) & 0xff00) | ((*(int *)(s + 0x14c + k) >> 12) & 0xff);
    h1 = (((*(int *)(s + 0x140 + k) >> 12) << 8) & 0xff00) | ((*(int *)(s + 0x148 + k) >> 12) & 0xff);
    *(unsigned short *)0x4001042 = h1;
    *(unsigned short *)0x4001046 = h2;
}
