// NONMATCHING: prologue schedule wall; body byte-correct (r5=&m,r4=0,r6=wbase) (div=7, mwccarm 1.2/sp2p3).
typedef short s16;
typedef unsigned short u16;
typedef long long s64;
extern int func_02053200(int x);
struct M { int _00, _01, _10, _11; };
extern void func_ov004_020b1c68(void* a0, int a1, int a2, int a3, int a4, struct M* a5);
#pragma opt_propagation off
void func_ov004_020b38ac(char* self)
{
    char* el = self + 0x34;
    int idx = *(int*)(self + 0x24) >> 2;
    int i = 0x1000;
    int wbase = i;
    struct M m;
    struct M* mp = &m;
    int z = 0;
    u16 lim = 0xffff;
    u16 flag;
    do {
        int d = idx - i;
        int weight = wbase;
        if (d < 0) d = -d;
        if (d < 0x1000)
            weight += (int)((((s64)(0x1000 - d) << 10) + 0x800) >> 12);
        weight = func_02053200(weight);
        mp->_00 = z;
        mp->_01 = z;
        mp->_10 = z;
        mp->_11 = z;
        m._00 = weight;
        m._11 = weight;
        func_ov004_020b1c68(el, *(s16*)(self + 0x10), *(s16*)(self + 0x12),
                            *(int*)(self + 0x1c), *(int*)(self + 0x18), mp);
        flag = *(u16*)(el + 6);
        i += 0x1000;
        el += 8;
    } while (flag != lim);
}
