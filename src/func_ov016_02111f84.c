// NONMATCHING: different op / idiom (div=16). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int func_020167a4(char* p);
extern int func_0204531c(char* p, int a);
extern int _ZN5Model6RenderEPK7Vector3(char* p, void* v);
struct DE { int w0, w1, w2; };
extern struct DE data_ov016_02114908[];
int func_ov016_02111f84(char* c) {
    int i;
    char* base;
    struct DE* dp;
    func_020167a4(c+0x350);
    base = (char*)(*(int*)(c+0x360) + 0x34);
    dp = data_ov016_02114908;
    for (i = 1; i < 7; i++) {
        short mv = ((short*)(c + 0x400))[i + 0xc];
        unsigned short* curr = (unsigned short*)(base + 0x1e);
        *curr = *curr + (unsigned short)(short)(mv * dp->w2);
        dp++;
        base += 0x34;
    }
    func_0204531c(c+0x358, *(int*)(c+0x3b4));
    _ZN5Model6RenderEPK7Vector3(c+0x350, 0);
    return 1;
}
