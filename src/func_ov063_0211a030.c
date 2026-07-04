// NONMATCHING: different op / idiom (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
typedef int Fix12i;
struct Sub { char pad[0x98]; int f98; };
struct C { char pad[0x98]; int f98; char pad2[0x484-0x98-4]; struct Sub* p484; };

void func_ov063_0211a030(struct C* c, int a, int b)
{
    int h = b >> 1;
    int m = (int)(((long long)a * h + 0x800) >> 12);
    struct Sub* p = c->p484;
    if (p->f98 < m) {
        c->f98 = m;
        return;
    }
    c->f98 = (int)(((long long)p->f98 * h + 0x800) >> 12);
}
