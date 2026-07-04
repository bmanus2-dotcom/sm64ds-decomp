// NONMATCHING: different op / idiom (div=29). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern char *_ZN5Actor10FindWithIDEj(unsigned int id);
extern void _ZN5Timer9StopTimerEv(void *t);
extern int _ZN5Sound7PlaySubEjjj5Fix12IiEb(unsigned int a, unsigned int b, unsigned int c, int d, int e);
extern void _ZN9Animation7AdvanceEv(void *a);
extern void func_ov062_0211afbc(char *t);
extern void _ZN12CylinderClsn5ClearEv(void *c);
extern void _ZN12CylinderClsn6UpdateEv(void *c);
extern char data_0209d4c8[];
int func_ov062_0211b05c(char *c)
{
    {
        unsigned int id;
        char *a;
        if (*(unsigned char*)(c + 0x16e) == 0 && (id = *(unsigned int*)(c + 0xf8)) != 0 &&
            (a = _ZN5Actor10FindWithIDEj(id)) != 0 &&
            *(unsigned short*)(a + 0xc) == 0xbf) {
            *(unsigned char*)(c + 0x16e) = 1;
            _ZN5Timer9StopTimerEv(data_0209d4c8);
            *(short*)(c + 0x16c) = 1;
            _ZN5Sound7PlaySubEjjj5Fix12IiEb(0x1f, 0x14, 0x7f, 0x6b000, 0);
        }
    }
    if (*(unsigned short*)(c + 0x16c) != 0) {
        *(unsigned short*)(c + 0x16c) += 1;
        if (*(unsigned short*)(c + 0x16c) >= 0x5a) {
            if (_ZN5Sound7PlaySubEjjj5Fix12IiEb(0x1f, 0x7f, 0, 0x8777, 0)) {
                *(unsigned short*)(c + 0x16c) = 0;
            }
        }
    }
    _ZN9Animation7AdvanceEv(c + 0xd4);
    func_ov062_0211afbc(c);
    _ZN12CylinderClsn5ClearEv(c + 0xd4);
    _ZN12CylinderClsn6UpdateEv(c + 0xd4);
    return 1;
}
