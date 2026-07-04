// NONMATCHING: different op / idiom (div=28). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern short func_ov007_020c3be0(void* a, unsigned short h1, unsigned short h2);

struct S2 { unsigned short a, b; };
extern struct S2 data_ov007_020ccc50[];
extern struct S2 data_ov007_020ccc5c[];
extern char* data_ov007_0210342c;

void func_ov007_020b2764(int sl)
{
    int sb = 0;
    struct S2* p50 = data_ov007_020ccc50;
    int v7 = 0x1000 - (sl - 0x800) * 2;
    int v6 = sl * 2;
    struct S2* p5c = data_ov007_020ccc5c;
    do {
        char* obj = *(char**)(data_ov007_0210342c + sb * 4 + 0x108);
        *(unsigned short*)(obj + 0x4c) =
            func_ov007_020c3be0((void*)sl, p50[sb].a, p5c[sb].a);
        *(unsigned short*)(obj + 0x46) = *(unsigned short*)(obj + 0x4c);
        *(unsigned short*)(obj + 0x4a) =
            func_ov007_020c3be0((void*)sl, p50[sb].b, p5c[sb].b);
        *(unsigned short*)(obj + 0x48) = *(unsigned short*)(obj + 0x4a);
        if (sb == 1) {
            int t = (sl >= 0x800) ? v7 : v6;
            int u = 0x2000 - t;
            int p = (int)(((long long)t * u) >> 12);
            *(int*)(obj + 0x50) = (0x1000 - p) * 0xf + 0x10000;
        }
        sb++;
    } while (sb < 2);
}
