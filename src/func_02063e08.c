// NONMATCHING: extra logic (you do more) (div=21). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
int func_02065970(void);
int func_02065bc0(void);
int func_02065bd0(void);
void func_02064eac(int p0, unsigned short mask, unsigned char e2, short a, int b, int c);

int func_02063e08(char* obj, int idx, int p2)
{
    unsigned char* e = (unsigned char*)(obj + 0x1d4 + idx * 0x68);
    unsigned short mask = (unsigned short)(1 << idx);
    int a, b, c;
    if (e[0] != 2) return 0;
    if (e[1] != 2) return 0;
    a = func_02065970();
    b = func_02065bc0();
    c = func_02065bd0();
    func_02064eac(p2, mask, e[2], (short)a, b, c);
    e[0] = 1;
    return 1;
}
