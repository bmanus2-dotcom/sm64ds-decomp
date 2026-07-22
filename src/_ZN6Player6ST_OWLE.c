struct S { int a, b; };

extern long long func_0203d5bc(int *p);
extern int func_ov006_02114590(void *a0, struct S *p, struct S *q0, struct S *q1, struct S *q2);

int _ZN6Player6ST_OWLE(char *self, struct S *v) {
    struct S d;
    struct S p, t1, t2, t3;
    struct S p2, t4, t5, t6;
    int t;
    int r;
    int yv, xv;
    int yv2, xv2;

    if (*(unsigned char *)(self + 0x30) == 0)
        return 0;
    t = v->a;
    d.a = t;
    d.b = v->b;
    d.a -= *(int *)(self + 0x8);
    d.b -= *(int *)(self + 0xc);
    if (*(int *)(self + 0x38) <= 0) {
        t = *(int *)(self + 0xc);
        if (v->b >= t) {
            if (func_0203d5bc(&d.a) >= 0x190000)
                return 0;
            return func_0203d5bc(&d.a) >= 0xc4000;
        }
        if (v->a >= *(int *)(self + 0x8) - 0x14000 && v->a < *(int *)(self + 0x8) + 0x14000 &&
            v->b >= t - 0xc000) {
            if (v->a >= *(int *)(self + 0x8) - 0x14000 && v->a < *(int *)(self + 0x8) - 0xa000) {
                p.a = v->a;
                p.b = v->b;
                yv = *(int *)(self + 0xc) - 0xc000;
                xv = *(int *)(self + 0x8) - 0x14000;
                t1.a = xv;
                t1.b = yv;
                yv = *(int *)(self + 0xc) - 0xc000;
                xv = *(int *)(self + 0x8) - 0xa000;
                t2.a = xv;
                t2.b = yv;
                yv = *(int *)(self + 0xc) - 0x1000;
                xv = *(int *)(self + 0x8) - 0xa000;
                t3.a = xv;
                t3.b = yv;
                r = func_ov006_02114590(self, &p, &t1, &t2, &t3);
                if (r == 0) goto in1;
                return 0;
            in1:
                return 1;
            }
            if (v->a >= *(int *)(self + 0x8) + 0xa000 && v->a < *(int *)(self + 0x8) + 0x16000) {
                p2.a = v->a;
                p2.b = v->b;
                yv2 = *(int *)(self + 0xc) - 0xc000;
                xv2 = *(int *)(self + 0x8) + 0x14000;
                t4.a = xv2;
                t4.b = yv2;
                yv2 = *(int *)(self + 0xc) - 0xc000;
                xv2 = *(int *)(self + 0x8) + 0xa000;
                t5.a = xv2;
                t5.b = yv2;
                yv2 = *(int *)(self + 0xc) - 0x1000;
                xv2 = *(int *)(self + 0x8) + 0xa000;
                t6.a = xv2;
                t6.b = yv2;
                r = func_ov006_02114590(self, &p2, &t4, &t5, &t6);
                if (r == 0) goto in2;
                return 0;
            in2:
                return 1;
            }
            return 0;
        }
        return 0;
    }
    if (func_0203d5bc(&d.a) < 0x100000)
        return 0;
    return func_0203d5bc(&d.a) < 0x190000;
}
