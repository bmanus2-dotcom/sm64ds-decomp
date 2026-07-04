// NONMATCHING: push-set / frame (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef unsigned char u8;

extern u8 *data_ov007_0210342c;

extern void *func_ov007_020c9388(void *self);
extern void *func_ov007_020c946c(void *r5);

void func_ov007_020b69c4(void)
{
    int i;

    *(int *)(data_ov007_0210342c + 0xf4) = 0;
    *(int *)(data_ov007_0210342c + 0x100) = 0;
    *(int *)(data_ov007_0210342c + 0x104) = 0;
    *(int *)(data_ov007_0210342c + 0xf0) = 0;
    *(int *)(data_ov007_0210342c + 0xec) = *(int *)(data_ov007_0210342c + 0xf0);

    i = 0;
    do {
        (data_ov007_0210342c + i)[0xfc] = (u8)0;
        i++;
    } while (i < 2);

    *(void **)(data_ov007_0210342c + 0x40) = func_ov007_020c9388((void *)0);

    i = 0;
    do {
        void *r = func_ov007_020c946c((void *)0);
        *(void **)(data_ov007_0210342c + (i << 2) + 0x44) = r;
        i++;
    } while (i < 3);

    {
        int *a = *(int **)(data_ov007_0210342c + 0x4c);
        int **b = *(int ***)(data_ov007_0210342c + 0x44);
        *b = (int *)((char *)a + 4);
    }
    {
        int *a = *(int **)(data_ov007_0210342c + 0x44);
        int **b = *(int ***)(data_ov007_0210342c + 0x48);
        *b = (int *)((char *)a + 4);
    }
}
