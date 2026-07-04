//cpp
// NONMATCHING: base materialization / addressing (div=10). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern "C" {
int _ZN6Player9IsOnShellEv(void* p);
void _ZN5Actor8PoofDustEv(void* p);
void _ZN9ActorBase18MarkForDestructionEv(void* p);
}

extern "C" int func_ov102_0214d044(char* c)
{
    if (*(void**)(c + 0x3c0) != 0) {
        if (_ZN6Player9IsOnShellEv(*(void**)(c + 0x3c0)) != 0)
            goto copy;
    }
    _ZN5Actor8PoofDustEv(c);
    _ZN9ActorBase18MarkForDestructionEv(c);
    return 0;
copy:
    {
        int* s = (int*)(*(char**)(c + 0x3c0) + 0x5c);
        short* a = (short*)(c + 0x8e);
        *(int*)(c + 0x5c) = s[0];
        *(int*)(c + 0x60) = s[1];
        *(int*)(c + 0x64) = s[2];
        *a = *a + 0x1000;
    }
    return 1;
}
