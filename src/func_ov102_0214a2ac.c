//cpp
// NONMATCHING: different op / idiom (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" { extern int data_0209caa0; }

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void m(int a);
};

extern "C" int func_ov102_0214a2ac(char* c) {
    if (*(int*)(c + 0x3e8) == 2)
        return 1;
    if ((*(int*)((char*)&data_0209caa0 + 4) & 0x80000000) == 0) {
        int b = (*(unsigned short*)(c + 0xc) == 0x14);
        if (b != 0) {
            Sub* s = (Sub*)(c + 0x320);
            s->m(0);
            return 1;
        }
    }
    Sub* s2 = (Sub*)(c + 0xd4);
    s2->m((int)(c + 0x80));
    return 1;
}
