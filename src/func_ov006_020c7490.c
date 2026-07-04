// NONMATCHING: missing logic (ROM does more) (div=28). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void func_ov006_020c862c(int* c, int v);
extern void func_ov006_020c76e0(char *c);
extern int data_ov006_02140418;
extern char data_ov006_0212dddc[];
extern int data_ov006_02140414;
extern int data_ov006_02140420;
extern int data_ov006_0213b014;

struct E { short a; int b; int c; };

void func_ov006_020c7490(void)
{
    int sl;
    for (sl = 0; sl < data_ov006_02140418; sl++) {
        struct E *e = (struct E *)(data_ov006_0212dddc + data_ov006_02140414 * 0x24 + sl * 0xc);
        func_ov006_020c862c((int *)(data_ov006_02140420 + sl * 0xb8), e->a);
        *(int *)(data_ov006_02140420 + sl * 0xb8 + 0x14) = e->b;
        *(int *)(data_ov006_02140420 + sl * 0xb8 + 0x20) =
            (int)(((long long)data_ov006_0213b014 * e->c + 0x800) >> 12);
        func_ov006_020c76e0((char *)(data_ov006_02140420 + sl * 0xb8));
    }
}
