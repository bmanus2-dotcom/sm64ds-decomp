//cpp
// NONMATCHING: different op / idiom (div=31). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
int _Z15ApproachLinear2Rsss(short* a, short b, short c);
void func_ov004_020b1b40(void* c);
int _ZN4cstd4fdivEii(int a, int b);

void func_ov004_020addcc(char* r5) {
    if (_Z15ApproachLinear2Rsss((short*)(r5+0x1a), 0, 1)) {
        func_ov004_020b1b40((void*)1);
    }
    int a = *(short*)(r5+0x1a);
    int b = *(short*)(r5+0x1c);
    int s = _ZN4cstd4fdivEii(a << 0xc, b << 0xc);
    int c3 = *(short*)(r5+0x1c);
    int c2 = *(short*)(r5+0x1a);
    int t = _ZN4cstd4fdivEii((c3 - c2) << 0xc, c3 << 0xc);
    long long m1 = (long long)*(int*)(r5+8) * (long long)s;
    long long m2 = (long long)*(int*)(r5+0x10) * (long long)t;
    long long m3 = (long long)s * (long long)s;
    int d = *(int*)(r5+0xc) - *(int*)(r5+0x14);
    long long m4 = (long long)((m3 + 0x800) >> 0xc) * (long long)d;
    int x = (int)((m1 + 0x800) >> 0xc) + (int)((m2 + 0x800) >> 0xc);
    *(int*)r5 = x;
    *(int*)(r5+4) = *(int*)(r5+0x14) + (int)((m4 + 0x800) >> 0xc);
}
}
