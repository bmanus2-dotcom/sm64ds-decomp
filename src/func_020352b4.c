// NONMATCHING: base materialization / addressing (div=24). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void *_ZN9ActorBasenwEj(unsigned);
extern void _ZN9ActorBaseC1Ev(void *);

extern int data_0208e4b8[];
extern int data_02092680[];
extern int data_020943c4[];
extern int data_0208eafc[];
extern int data_0208eacc[];
extern int data_0208eb2c[];

typedef unsigned char u8;

void *func_020352b4(void)
{
    char *p = (char *)_ZN9ActorBasenwEj(0x68);
    if (p) {
        _ZN9ActorBaseC1Ev(p);
        *(int **)p = data_0208e4b8;
        *(int **)p = data_02092680;
        *(u8 *)(p + 0x13) |= 1;
        *(u8 *)(p + 0x13) |= 4;
        *(int **)p = data_020943c4;
        *(int **)(p + 0x50) = data_0208eafc;
        *(int **)(p + 0x50) = data_0208eacc;
        *(int *)(p + 0x54) = 0x1000;
        *(int *)(p + 0x58) = 0;
        *(int **)(p + 0x50) = data_0208eb2c;
        *(short *)(p + 0x5c) = 0;
    }
    return p;
}
