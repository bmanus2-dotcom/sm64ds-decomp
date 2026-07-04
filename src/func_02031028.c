// NONMATCHING: register allocation (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 data_0209fc84;
extern u8 data_0209fca0;
extern u8 data_0209fc88;
extern u8 data_0209fcd8;
extern u8 data_02092818[];
extern u16 data_02075d14[];
extern u16 data_02075b14[];
extern u8 data_0208f074[];
extern u8 data_0208f174[];
extern void* func_0203d8a0(int idx);

void func_02031028(int arg)
{
    u16* p;
    int i;
    int j;
    int n;
    u8* out;
    u16 val;

    p = (u16*)func_0203d8a0(data_0209fc84);
    i = 0;
    data_0209fca0 = ((u8*)p)[1];
    n = data_0209fca0;
    if (n <= 0)
        return;

    out = data_02092818;
    do {
        val = (p + i)[1];
        j = 0;
        while (data_02075b14[j] != val && data_02075d14[j] != val && j < 0x100)
            j++;
        if (j == 0x100)
            *out = 0x47;
        else
            *out = j;

        if (arg >= 0) {
            if (arg == 0)
                data_0209fc88 += data_0208f074[*out];
            else
                data_0209fc88 += data_0208f174[*out];
            data_0209fcd8 += 1;
        }
        i++;
        out++;
    } while (i < n);
}
