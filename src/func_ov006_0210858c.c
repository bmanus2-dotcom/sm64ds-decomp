struct Obj { char pad[8]; void *a; /* 0x8 */ void *b; /* 0xc */ };

extern void func_ov004_020adc5c(void *p);

int func_ov006_0210858c(struct Obj *o)
{
    if (o->a)
        func_ov004_020adc5c(o->a);
    if (o->b)
        func_ov004_020adc5c(o->b);
    return 1;
}
