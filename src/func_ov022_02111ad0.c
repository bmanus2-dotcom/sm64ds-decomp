// NONMATCHING: different op / idiom (div=39). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned char DecIfAbove0_Byte(unsigned char* p);
extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int a, void* v);
extern void func_ov022_02111a1c(char* t);
extern int _ZN8Platform13IsClsnInRangeE5Fix12IiES1_(void* t, int a, int b);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(void* t);

int func_ov022_02111ad0(char* c)
{
    if (DecIfAbove0_Byte((unsigned char*)c + 0x31e) == 0) {
        if (*(unsigned char*)(c + 0x31f) == 0) {
            short* p = (short*)(c + 0x96);
            *p = *p - 0x100;
            if (*(short*)(c + 0x96) <= -0x2000) {
                *(short*)(c + 0x96) = -0x2000;
                *(unsigned char*)(c + 0x31e) = 0xf;
                *(unsigned char*)(c + 0x31f) = 1;
            }
        } else {
            short* p = (short*)(c + 0x96);
            *p = *p + 0x100;
            if (*(short*)(c + 0x96) >= 0) {
                *(short*)(c + 0x96) = 0;
                *(unsigned char*)(c + 0x31e) = 0xf;
                *(unsigned char*)(c + 0x31f) = 0;
            }
        }
    } else {
        if (*(unsigned char*)(c + 0x31e) == 1) {
            if (*(unsigned char*)(c + 0x31f) == 0)
                _ZN5Sound9PlayBank3EjRK7Vector3(0x34, c + 0x74);
            else
                _ZN5Sound9PlayBank3EjRK7Vector3(0x35, c + 0x74);
        }
    }
    *(short*)(c + 0x90) = *(short*)(c + 0x96);
    func_ov022_02111a1c(c);
    if (_ZN8Platform13IsClsnInRangeE5Fix12IiES1_(c, 0, 0))
        _ZN8Platform19UpdateClsnPosAndRotEv(c);
    return 1;
}
