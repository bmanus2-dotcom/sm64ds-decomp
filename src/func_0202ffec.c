// NONMATCHING: smull/spill scheduling (div~999, size 0x150 vs 0x1d8). 4x4 fixed-
// point matrix transform; ROM interleaves 14 spill slots with specific smull order.
typedef signed int s32;
typedef unsigned int u32;

struct Mat4 {
    s32 m[4];
};

struct Vec4 {
    s32 v[4];
};

static s32 dot_scaled(s32 a, s32 b)
{
    return (s32)((((long long)a * (long long)b) + 0x800) >> 12);
}

void func_0202ffec(struct Mat4 *m, struct Vec4 *v, struct Vec4 *out)
{
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;
    s32 t8;
    s32 t9;
    s32 t10;
    s32 t11;
    s32 t12;
    s32 t13;
    s32 t14;
    s32 t15;

    t0 = dot_scaled(m->m[1], v->v[2]);
    t1 = dot_scaled(m->m[3], v->v[0]);
    t2 = dot_scaled(m->m[0], v->v[3]);
    t3 = dot_scaled(m->m[2], v->v[1]);
    out->v[0] = (t1 + t0) + t2 - t3;

    t4 = dot_scaled(m->m[2], v->v[0]);
    t5 = dot_scaled(m->m[3], v->v[1]);
    t6 = dot_scaled(m->m[1], v->v[3]);
    t7 = dot_scaled(m->m[0], v->v[2]);
    out->v[1] = (t4 + t5) + t6 - t7;

    t8 = dot_scaled(m->m[0], v->v[1]);
    t9 = dot_scaled(m->m[3], v->v[2]);
    t10 = dot_scaled(m->m[2], v->v[3]);
    t11 = dot_scaled(m->m[1], v->v[0]);
    out->v[2] = (t8 + t9) + t10 - t11;

    t12 = dot_scaled(m->m[3], v->v[3]);
    t13 = dot_scaled(m->m[0], v->v[0]);
    t14 = dot_scaled(m->m[1], v->v[1]);
    t15 = dot_scaled(m->m[2], v->v[2]);
    out->v[3] = t12 - t13 - t14 - t15;
}