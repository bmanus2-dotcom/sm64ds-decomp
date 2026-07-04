// NONMATCHING: different op / idiom (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_02054d88(void);
extern void func_02031028(int a);
extern void func_020316d8(int a, int b, int c, int d);

extern unsigned char data_0209fc7c;
extern unsigned char data_0208f174[];
extern unsigned char data_0209fca0;
extern unsigned char *data_0209fd0c;
extern int data_0209fd18;
extern unsigned char data_02092818[];

void func_020318a4(int sl)
{
    int acc;
    int base;
    int i;
    unsigned char *cmd;
    unsigned char op;

    acc = data_0209fc7c;
    base = func_02054d88() + 0x8000;

    for (;;) {
        cmd = data_0209fd0c;
        op = cmd[0];
        if (op == 0xfd) return;
        if (op == 0xfe) {
            int param = cmd[2];
            int val;
            data_0209fd18 = param;
            val = (unsigned short)(cmd[4] | (cmd[3] << 8));
            if (param == 1 && val == 1) {
                unsigned char *p;
                func_02031028(-1);
                p = data_02092818;
                for (i = 0; i < data_0209fca0; i++) {
                    func_020316d8(sl, *p, acc, base);
                    acc = (acc + data_0208f174[*p]) & 0xff;
                    p++;
                }
            }
            data_0209fd0c = data_0209fd0c + data_0209fd0c[1];
        } else if (op == 0xff) {
            return;
        } else {
            func_020316d8(sl, op, acc, base);
            acc = (acc + data_0208f174[op]) & 0xff;
            data_0209fd0c = data_0209fd0c + 1;
        }
    }
}
