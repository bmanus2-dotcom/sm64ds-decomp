extern void func_ov007_020c78dc(int x);
extern void _ZN6Player17St_EndingFly_MainEv(void *p);

struct S {
    int n;        /* [0] */
    int m;        /* [4] */
    int *a;       /* [8] */
    int *b;       /* [0xc] */
};

void func_ov007_020c7368(struct S *s)
{
    int i;
    for (i = 0; i < s->m; i++)
        func_ov007_020c78dc(s->a[i]);
    for (i = 0; i < s->n; i++)
        func_ov007_020c78dc(s->b[i]);
    _ZN6Player17St_EndingFly_MainEv(s->a);
    _ZN6Player17St_EndingFly_MainEv(s->b);
    _ZN6Player17St_EndingFly_MainEv(s);
}
