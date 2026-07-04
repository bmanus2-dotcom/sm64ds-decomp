// NONMATCHING: different op / idiom (div=22). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void func_ov006_020c9098(char* o);
void func_ov006_020c8ecc(char* o);

extern int  data_ov006_021405bc;
extern int  data_ov006_021405b4;
extern int  data_ov006_021405b0;
extern int  data_ov006_021405ac;
extern int  data_ov006_02140554;

void func_ov006_020ca840(void)
{
    int off;
    int i;
    data_ov006_021405b4 = -0x4800;
    data_ov006_021405b0 = 0x100;
    data_ov006_021405ac = 1;
    off = 0;
    for (i = 0; i < data_ov006_021405bc; i++) {
        func_ov006_020c9098((char*)(data_ov006_02140554 + off));
        func_ov006_020c8ecc((char*)(data_ov006_02140554 + off));
        off += 0xdc;
    }
}
