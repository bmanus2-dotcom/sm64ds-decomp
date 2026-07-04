// NONMATCHING: different op / idiom (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void *data_020a8060;
extern int data_020a805c;
extern int data_020a8064[2];
extern int data_020a806c[2];
extern int data_020a8074;
extern int data_0209a048;
extern int func_0205da94;
extern int func_0205db2c;
extern int func_0205db24;
extern int func_02057020(void);
extern void func_02060890(void);
extern void func_0205cd34(void *o);
extern int func_0205cc80(void *thiz, void *a, int b);
extern void func_0205c7c4(void *p, void *a, int b);
extern void func_0205cb68(void *a, int b, int c, int d, int e, int f, void *g, void *h);

void func_0205d96c(void *arg)
{
    int *a = (int *)0x27ffe40;
    int *b = (int *)0x27ffe48;
    data_020a8060 = arg;
    data_020a805c = func_02057020();
    data_020a8064[0] = 0;
    data_020a8064[1] = 0;
    data_020a806c[0] = 0;
    data_020a806c[1] = 0;
    func_02060890();
    func_0205cd34(&data_020a8074);
    func_0205cc80(&data_020a8074, &data_0209a048, 3);
    if (*a == -1) return;
    if (*a == 0) return;
    if (*b == -1) return;
    if (*b == 0) return;
    func_0205c7c4(&data_020a8074, &func_0205da94, 0x602);
    func_0205cb68(&data_020a8074, 0, b[0], b[1], a[0], a[1],
                  &func_0205db2c, &func_0205db24);
}
