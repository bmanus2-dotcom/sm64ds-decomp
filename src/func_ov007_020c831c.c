// NONMATCHING: extra logic (you do more) (div=30). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef short s16;
typedef int s32;
extern void func_02053320(int s, int *a, int *b, int *out);
struct S { s32 *p; s32 v4; s32 v8; s32 vc; s32 v10; s32 v14; s32 v18; s16 s1c; s16 pad1e; s32 v20; };
void func_ov007_020c831c(struct S *s, int shift, int r2arg)
{
    int flag = s->v20 & 1;
    if (flag == 0) {
        func_02053320(-shift, &s->v4, &s->v10, &s->v10);
        if (s->s1c == 0x1000) {
            s->v4 = s->v10 >> r2arg;
            s->v8 = s->v14 >> r2arg;
            s->vc = s->v18 >> r2arg;
        } else {
            func_02053320(s->s1c >> r2arg, &s->v10, &s->v4, &s->v4);
        }
    } else {
        func_02053320(flag >> r2arg, &s->v10, &s->v4, &s->v4);
    }
    s->p[0] += s->v4 >> r2arg;
    s->p[1] += s->v8 >> r2arg;
    s->p[2] += s->vc >> r2arg;
    s->v18 = 0;
    s->v14 = s->v18;
    s->v10 = s->v14;
}
