//cpp
// NONMATCHING: base materialization / addressing (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
int _ZN5Actor18HorzAngleToCPlayerEv(void* p);
int AngleDiff(int a, int b);
void func_ov074_02121a4c(void* c, int i);
}

extern "C" void func_ov074_02120808(char* c)
{
    int ang = (short)(*(short*)(c + 0x5f4) + *(int*)(c + 0x5f0) * 0x4500);
    if (AngleDiff(ang, _ZN5Actor18HorzAngleToCPlayerEv(c)) <= 0x4000)
        return;
    func_ov074_02121a4c(c, 6);
    {
        int* p = (int*)(c + 0x5f0);
        *p = *p * -1;
    }
}
