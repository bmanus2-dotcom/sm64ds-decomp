// NONMATCHING: div=1 size-exact; 6u cond-opt (beq vs moveq); pure C replaces HAND-ASM
typedef unsigned char u8;
extern u8 data_020a9d2c[];
extern void func_02068484(void);

int func_02068398(void)
{
    void *sel = *(void **)data_020a9d2c;
    void *p;

    if (sel == 0)
        return 0;

    p = *(void **)(data_020a9d2c + 4);
    if (p == 0)
        goto done;
    p = *(void **)((u8 *)p + 0x4b4);
    sel = p ? p : sel;
done:
    *(void **)(data_020a9d2c + 4) = sel;
    func_02068484();
    {
        u8 *d = data_020a9d2c;
        void *q = *(void **)(d + 4);
        d[0xe] = *((u8 *)q + 0x4ac);
        d[0xc] = 2;
    }
    return 1;
}
