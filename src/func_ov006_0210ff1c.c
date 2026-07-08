struct S_0210ff1c {
    char _0[8];
    int f8;   /* 0x8 */
    int fc;   /* 0xc */
    char _10[0x34 - 0x10];
    struct { int a; int b; } arr[3]; /* 0x34: a=0x34, b=0x38, stride 8 */
};

extern void* data_021379dc;
extern void* data_021379e8;
extern void* data_02137a00;
extern void* data_021379f4;
extern void func_ov004_020afdd0(void*, int, int, int, int);

void func_ov006_0210ff1c(void* self) {
    struct S_0210ff1c* s = (struct S_0210ff1c*)self;
    int i;
    int x;
    int xo;

    for (i = 0, x = 0; i < 3; i++, x += 0x18) {
        func_ov004_020afdd0(data_021379dc,
            (x - 0x18) + (s->f8 >> 12),
            s->fc >> 12, -1, 2);
    }
    for (i = 0, x = 0; i < 3; i++, x += 0x18) {
        xo = x - 0x18;
        func_ov004_020afdd0(data_021379e8,
            (s->f8 >> 12) + (s->arr[i].a >> 12) + xo,
            (s->fc >> 12) + (s->arr[i].b >> 12), -1, 3);
        func_ov004_020afdd0(data_02137a00,
            (s->f8 >> 12) + (s->arr[i].a >> 12) + xo,
            (s->fc >> 12) + (s->arr[i].b >> 12) - 0x10, -1, 3);
        func_ov004_020afdd0(data_021379f4,
            (s->f8 >> 12) + (s->arr[i].a >> 12) + xo,
            (s->fc >> 12) + (s->arr[i].b >> 12) - 0x20, -1, 3);
        func_ov004_020afdd0(data_021379e8,
            (s->f8 >> 12) + (s->arr[i].a >> 12) + xo,
            (s->fc >> 12) + (s->arr[i].b >> 12) - 0x30, -1, 3);
    }
}
