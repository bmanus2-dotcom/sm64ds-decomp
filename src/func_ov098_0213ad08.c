// NONMATCHING: different op / idiom (div=26). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern char* _ZN5Actor10FindWithIDEj(unsigned int id);
extern void func_ov102_0214ae1c(char* a);
extern int func_ov002_020df34c(char* self);
extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int n, void* v);
void func_ov098_0213ad08(char* self) {
    unsigned int id = *(unsigned int*)(self + 0x148);
    if (id == 0) return;
    char* a = _ZN5Actor10FindWithIDEj(id);
    if (a == 0) return;
    int b1 = *(unsigned short*)(a + 0xc) == 0xbf;
    if (b1 == 0) return;
    char* p = *(char**)(a + 0x358);
    if (p != 0 && *(unsigned short*)(p + 0xc) == 0xce) {
        func_ov102_0214ae1c(a);
        return;
    }
    if (func_ov002_020df34c(a) == 0) return;
    *(int*)(self + 0x180) = 3;
    *(unsigned char*)(self + 0x185) = 0;
    *(char**)(self + 0x158) = a;
    *(int*)(self + 0x13c) |= 1;
    _ZN5Sound9PlayBank3EjRK7Vector3(0x14b, self + 0x74);
}
