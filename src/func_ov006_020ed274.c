// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned char data_020a0e40[];
extern unsigned char data_020a0de8[];
extern unsigned char data_020a0de9[];
extern int data_ov006_0213ca54[];

void func_ov006_020ed274(char *c)
{
    int idx;
    int b = 0;
    *(int *)(c + 0x466c) -= 1;
    if (*(int *)(c + 0x4000 + 0x66c) == 0)
        return;
    idx = data_020a0e40[0];
    if (data_020a0de8[idx * 4] != 0 && data_020a0de9[idx * 4] != 0)
        b = 1;
    if (b == 0)
        return;
    *(int *)(c + 0x4660) = data_ov006_0213ca54[0];
    *(int *)(c + 0x4664) = data_ov006_0213ca54[1];
}
