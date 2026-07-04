// NONMATCHING: register allocation (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int (*Fn)(void);

extern int func_02043060(void *a);
extern void func_02043180(int a, int b, int c, int d);
extern void func_020433b8(void);

extern unsigned short data_020a4b50;
extern unsigned char data_020a4b4c;
extern Fn **data_020a4bb8;

int func_02043098(int idx, int b, int c, int d)
{
    int r5;

    data_020a4b50 = (unsigned short)idx;
    data_020a4b4c = 2;
    if (func_02043060((void *)idx) == 3) return 0;

    data_020a4b4c = 3;
    func_02043180(idx, b, c, d);

    data_020a4b4c = 4;
    r5 = (*data_020a4bb8[idx])();
    if (r5 == 0) {
        data_020a4b4c = 0;
        data_020a4b50 = 0xffff;
        return 0;
    }
    data_020a4b4c = 5;
    func_020433b8();
    data_020a4b4c = 0;
    data_020a4b50 = 0xffff;
    return r5;
}
