//cpp
// NONMATCHING: base materialization / addressing (div=37). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int ApproachLinear(int &, int, int);
extern void func_0203d388(int *p, int angle);
extern void func_ov006_020eb9b0(char *p);
extern int func_02012468(int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_ov006_020ebf20(char *p);

extern "C" void func_ov006_020eb610(char *c)
{
    int v[2];
    int step;
    int *pos;
    short *cnt;

    if (*(unsigned char *)(c + 0x92) != 0) {
        step = 0x1000;
        if (*(int *)(c + 0x40) < 0xa00) step = step >> 2;
        ApproachLinear(*(int *)(c + 0x40), *(int *)(c + 0x44), step);
        v[0] = 0;
        v[1] = -*(int *)(c + 0x40);
        func_0203d388(v, *(short *)(c + 0x7c));
        pos = (int *)(c + 0x20);
        pos[0] = pos[0] + v[0];
        pos[1] = pos[1] + v[1];
        if (*(unsigned char *)(c + 0x93) != 0) {
            cnt = (short *)(c + 0x8e);
            *cnt = *cnt - 1;
            if (*(short *)(c + 0x8e) == 0) {
                func_ov006_020eb9b0(c);
                if (*(int *)(c + 0x6c) != 0 && *(int *)(c + 0x70) == 0) {
                    *(int *)(c + 0x68) = func_02012468(*(int *)(c + 0x68), 2,
                        *(int *)(c + 0x6c), 2, 0,
                        *(unsigned char *)(c + 0x93) != 0 ? 0x1f4 : 0, 0, 0);
                } else {
                    *(int *)(c + 0x68) = 0;
                }
                if (*(int *)c != 0) {
                    int off = *(int *)(c + 4);
                    char *base = c + (off >> 1);
                    void (*fn)(char *);
                    if (off & 1)
                        fn = *(void (**)(char *))(*(char **)base + *(int *)c);
                    else
                        fn = *(void (**)(char *))c;
                    fn(c);
                }
            }
        }
    }
    if (*(unsigned char *)(c + 0x92) == 0) return;
    func_ov006_020ebf20(c);
}
